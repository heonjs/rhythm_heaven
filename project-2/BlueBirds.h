#pragma once
#include "Scene.h"

namespace JSH
{
    class BlueBirds : public Scene
    {
    public:
        BlueBirds();
        virtual ~BlueBirds();

        virtual void Initialize() override;
        virtual void Update() override;
        virtual void Render(HDC hdc) override;

        virtual void Enter();
        virtual void Exit();

        static float GetScore()
        {
            return mScore;
        }

    private:
        class BBTouchScreen* mTouchScreen;

        static float mScore;
        static float mPlayTime;
    };
}