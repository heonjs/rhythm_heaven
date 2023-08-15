#pragma once
#include "GameObject.h"

namespace JSH
{
    class GleeEndImage : public GameObject
    {
    public:
        GleeEndImage();
        virtual ~GleeEndImage();

        virtual void Initialize();
        virtual void Update();
        virtual void Render(HDC hdc);

    private:

    };
}