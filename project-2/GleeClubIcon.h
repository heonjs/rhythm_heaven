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

    private:

    };
}