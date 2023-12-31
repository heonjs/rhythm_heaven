#pragma once
#include "GameObject.h"

namespace JSH
{
    class BlueBirdsExplain : public GameObject
    {
    public:
        BlueBirdsExplain();
        virtual ~BlueBirdsExplain();

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