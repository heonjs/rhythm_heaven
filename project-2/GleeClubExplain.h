#pragma once
#include "GameObject.h"

namespace JSH
{
    class GleeClubExplain : public GameObject
    {
    public:
        GleeClubExplain();
        virtual ~GleeClubExplain();

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