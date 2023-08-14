#pragma once
#include "Include.h"
#include "Collider.h"

namespace JSH
{
#define LAYER_MAX (UINT)eLayerType::End

    union ColliderID
    {
        struct
        {
            UINT left;
            UINT right;
        };
        UINT64 id;
    };

    using namespace enums;
    class Collidermng
    {
    public:
        static void Initialize();
        static void Update();
        static void Render(HDC hdc);
        static void Release();
        
        static void Clear();
        static void ColliderLayerCheck(eLayerType left, eLayerType right, bool enable);
        static void LayerCollider(class Scene* scene, eLayerType left, eLayerType right);
        static void ColliderCollision(Collider* left, Collider* right);
        static bool Intersect(Collider* left, Collider* right);

    private:
        static map<UINT64, bool> mColliderMap;
        static bitset<LAYER_MAX> mLayerMasks[LAYER_MAX];
    };
}