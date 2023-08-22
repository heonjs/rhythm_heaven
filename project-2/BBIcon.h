#pragma once
#pragma once
#include "GameObject.h"

namespace JSH
{
    class BBIcon : public GameObject
    {
    public:
        BBIcon();
        virtual ~BBIcon();

        virtual void Initialize();
        virtual void Update();
        virtual void Render(HDC hdc);

        virtual void OnColliderEnter(class Collider* other);
        virtual void OnColliderStay(class Collider* other);
        virtual void OnColliderExit(class Collider* other);

    private:
        class BlueBirdsExplain* BBEx;
        class BlueBirdsExTitle* BBExt;
    };
}