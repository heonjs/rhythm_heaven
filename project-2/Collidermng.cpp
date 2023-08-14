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
        // �� �浹ü�� ID�� Ȯ��
        ColliderID ID;
        ID.left = (UINT)left->GetCollisionNumber();
        ID.right = (UINT)right->GetCollisionNumber();


        // ���� �浹ü�� ������ �����ͼ� Ȯ���Ѵ�.
        std::map<UINT64, bool>::iterator iter
            = mColliderMap.find(ID.id);

        // Ȥ�� �浹������ ���ٸ� �������ָ�ȴ�
        if (iter == mColliderMap.end())
        {
            mColliderMap.insert(std::make_pair(ID.id, false));
            iter = mColliderMap.find(ID.id);
        }


        //�浹�Լ� ȣ��
        if (Intersect(left, right))
        {
            // �浹 ���λ���
            if (iter->second == false)
            {
                left->OnColliderEnter(right);
                right->OnColliderEnter(left);

                iter->second = true;

            }
            else // ó�� �浹�ϴ� ����
            {
                left->OnColliderStay(right);
                right->OnColliderStay(left);
            }
        }
        else
        {
            // �浹�� ������������
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