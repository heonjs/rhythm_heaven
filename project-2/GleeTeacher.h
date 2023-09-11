#pragma once
#include "GameObject.h"

namespace JSH
{
    class GleeTeacher : public GameObject
    {
    public:
        GleeTeacher();
        virtual ~GleeTeacher();

        virtual void Initialize();
        virtual void Update();
        virtual void Render(HDC hdc);

        void Together();

    private:
        static float mPlayTime;
        static float miTime;
    };
}