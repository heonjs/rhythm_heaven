#pragma once
#include "GameObject.h"

namespace JSH
{
    class BBCaptain : public GameObject
    {
    public:
        BBCaptain();
        virtual ~BBCaptain();

        virtual void Initialize();
        virtual void Update();
        virtual void Render(HDC hdc);

    private:

    };
}