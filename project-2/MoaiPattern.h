#pragma once
#include "MoaiNPC.h"

namespace JSH
{
    class MoaiPattern : public MoaiNPC
    {
    public:
        MoaiPattern();
        virtual ~MoaiPattern();

        virtual void Initialize();
        virtual void Update();
        virtual void Render(HDC hdc);

    private:
        static int mpTime;
    };
}