#pragma once
#include "GameObject.h"

namespace JSH
{
    class MoaiExplain : public GameObject
    {
    public:
        MoaiExplain();
        virtual ~MoaiExplain();

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