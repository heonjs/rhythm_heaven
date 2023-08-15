#pragma once
#include "GameObject.h"

namespace JSH
{
    class BBEndImage : public GameObject
    {
    public:
        BBEndImage();
        virtual ~BBEndImage();
        
        virtual void Initialize();
        virtual void Update();
        virtual void Render(HDC hdc);

    private:
        
    };
}