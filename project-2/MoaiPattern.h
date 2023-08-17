#pragma once
#include "MoaiNPC.h"

namespace JSH
{
    class MoaiPattern : public MoaiNPC
    {
    public:
        MoaiPattern();
        virtual ~MoaiPattern();

    private:
        static int mpTime;
    };
}