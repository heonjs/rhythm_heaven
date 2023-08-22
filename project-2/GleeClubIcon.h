#pragma once
#include "GameObject.h"

namespace JSH
{
    class GleeClubIcon : public GameObject
    {
    public:
        GleeClubIcon();
        virtual ~GleeClubIcon();

        virtual void Initialize();
        virtual void Update();
        virtual void Render(HDC hdc);

        virtual void OnColliderEnter(class Collider* other);
        virtual void OnColliderStay(class Collider* other);
        virtual void OnColliderExit(class Collider* other);

    private:
        class GleeClubExplain* mGleeEx;
        class GleeExTitle* mGleeExt;
    };
}