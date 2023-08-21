#pragma once
#include "GameObject.h"

namespace JSH
{
    class MoaiExTitle : public GameObject
    {
    public:
        MoaiExTitle();
        virtual ~MoaiExTitle();

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