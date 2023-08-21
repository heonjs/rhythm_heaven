#pragma once
#include "GameObject.h"

namespace JSH
{
    using namespace math;

    class MouseCursor : public GameObject
    {
    public:
        MouseCursor();
        virtual ~MouseCursor();

        virtual void Initialize();
        virtual void Update();
        virtual void Render(HDC hdc);

        virtual void OnColliderEnter(class Collider* other);
        virtual void OnColliderExit(class Collider* other);

    private:

    };
}