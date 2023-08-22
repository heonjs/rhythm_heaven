#pragma once
#include "GameObject.h"

namespace JSH
{
    class BlueBirdsExTitle : public GameObject
    {
    public:
        BlueBirdsExTitle();
        virtual ~BlueBirdsExTitle();
        
        virtual void Initialize();
        virtual void Update();
        virtual void Render(HDC hdc);

        void SetTrigger(bool value)
        {
            mTrigger = value;
        }

    private:
        bool mTrigger;
    };
}