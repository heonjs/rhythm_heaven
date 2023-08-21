#pragma once
#include "GameObject.h"

namespace JSH
{
    class MoaiIcon : public GameObject
    {
    public:
        MoaiIcon();
        virtual ~MoaiIcon();

        virtual void Initialize();
        virtual void Update();
        virtual void Render(HDC hdc);

        virtual void OnColliderEnter(class Collider* other);
        virtual void OnColliderStay(class Collider* other);
        virtual void OnColliderExit(class Collider* other);

    private:
        class MoaiExplain* moaiEx;
        class MoaiExTitle* moaiExt;
    };
}