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

    private:

    };
}