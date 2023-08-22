#pragma once
#include "GameObject.h"

namespace JSH
{
    class GleeExTitle : public GameObject
    {
    public:
        GleeExTitle();
        virtual ~GleeExTitle();

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