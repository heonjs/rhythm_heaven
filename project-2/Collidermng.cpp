#include "Collidermng.h"
#include "Scene.h"
#include "SceneManager.h"

namespace JSH
{
    map<UINT64, bool> Collidermng::mColliderMap = {};
    bitset<LAYER_MAX> Collidermng::mLayerMasks[LAYER_MAX] = {};

    void Collidermng::Initialize()
    {
    }
    void Collidermng::Update()
    {
        Scene* activeScene = SceneManager::GetActiveScene();
        for (size_t row = 0; row < LAYER_MAX; row++)
        {
            for (size_t col = 0; col < LAYER_MAX; col++)
            {
                if (mLayerMasks[row][col] == true)
                {
                    LayerCollider(activeScene, (eLayerType)row, (eLayerType)col);
                }
            }
        }
    }
    void Collidermng::Render(HDC hdc)
    {
    }
    void Collidermng::Release()
    {
    }
    void Collidermng::Clear()
    {
        mLayerMasks->reset();
        mColliderMap.clear();
    }
    void Collidermng::ColliderLayerCheck(eLayerType left, eLayerType right, bool enable)
    {
        int row = -1;
        int col = -1;

        if (left > right)
        {
            row = (UINT)left;
            col = (UINT)right;
        }
        else
        {
            col = (UINT)left;
            row = (UINT)right;
        }

        mLayerMasks[row][col] = enable;
    }
    void Collidermng::LayerCollider(Scene* scene, eLayerType left, eLayerType right)
    {
        // finds left layer objects
        Layer& leftLayer = scene->GetLayer(left);
        vector<GameObject*>& lefts = leftLayer.GetGameObjects();

        Layer& rightLayer = scene->GetLayer(right);
        vector<GameObject*>& rights = rightLayer.GetGameObjects();

        // finds right layer Objects
        for (GameObject* left : lefts)
        {
            Collider* leftCol = left->GetComponent<Collider>();
            if (leftCol == nullptr)
            {
                continue;
            }

            for (GameObject* right : rights)
            {
                Collider* rightCol = right->GetComponent<Collider>();
                if (rightCol == nullptr)
                {
                    continue;
                }
                if (left == right)
                {
                    continue;
                }

                ColliderCollision(leftCol, rightCol);
            }
        }
    }
    void Collidermng::ColliderCollision(Collider* left, Collider* right)
    {
        // 두 충돌체의 ID를 확인
        ColliderID ID;
        ID.left = (UINT)left->GetCollisionNumber();
        ID.right = (UINT)right->GetCollisionNumber();


        // 이전 충돌체의 정보를 가져와서 확인한다.
        std::map<UINT64, bool>::iterator iter
            = mColliderMap.find(ID.id);

        // 혹시 충돌정보가 없다면 생성해주면된다
        if (iter == mColliderMap.end())
        {
            mColliderMap.insert(std::make_pair(ID.id, false));
            iter = mColliderMap.find(ID.id);
        }


        //충돌함수 호출
        if (Intersect(left, right))
        {
            // 충돌 중인상태
            if (iter->second == false)
            {
                left->OnColliderEnter(right);
                right->OnColliderEnter(left);

                iter->second = true;

            }
            else // 처음 충돌하는 상태
            {
                left->OnColliderStay(right);
                right->OnColliderStay(left);
            }
        }
        else
        {
            // 충돌을 빠져나간상태
            if (iter->second == true)
            {
                left->OnColliderExit(right);
                right->OnColliderExit(left);

                iter->second = false;
            }
        }
    }
    bool Collidermng::Intersect(Collider* left, Collider* right)
    {
        vector2 leftPos = left->GetPosition();
        vector2 rightPos = right->GetPosition();

        vector2 leftSize = left->GetSize();
        vector2 rightSize = right->GetSize();

        if (fabs(leftPos.x - rightPos.x) < fabs(leftSize.x / 2.0f + rightSize.x / 2.0f)
            && fabs(leftPos.y - rightPos.y) < fabs(leftSize.y / 2.0f + rightSize.y / 2.0f))
        {
            return true;
        }

        return false;
    }
}