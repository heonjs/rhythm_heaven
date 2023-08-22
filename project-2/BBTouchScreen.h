#pragma once
#include "GameObject.h"

namespace JSH
{
    class BBTouchScreen : public GameObject
    {
    public:
        BBTouchScreen();
        virtual ~BBTouchScreen();

        virtual void Initialize();
        virtual void Update();
        virtual void Render(HDC hdc);

        virtual void OnColliderExit(class Collider* other);

    private:

    };
}