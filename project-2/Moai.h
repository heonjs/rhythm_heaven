#pragma once
#include "Scene.h"

namespace JSH
{
    class Moai : public Scene
    {
    public:
        Moai();
        virtual ~Moai();

        virtual void Initialize();
        virtual void Update();
        virtual void Render(HDC hdc);

        virtual void Enter();
        virtual void Exit();

        float GetScore()
        {
            return mScore;
        }

    private:
        bool SoundPlay;
        static float mPlayTime;

        static float mScore;
    };
}