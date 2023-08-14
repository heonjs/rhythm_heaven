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

    private:

    };
}