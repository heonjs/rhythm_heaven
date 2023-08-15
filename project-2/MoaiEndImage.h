#pragma once
#include "GameObject.h"

namespace JSH
{
    class MoaiEndImage : public GameObject
    {
    public:
        MoaiEndImage();
        virtual ~MoaiEndImage();

        virtual void Initialize();
        virtual void Update();
        virtual void Render(HDC hdc);

    private:

    };
}