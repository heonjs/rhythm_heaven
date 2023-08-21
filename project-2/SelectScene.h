#pragma once
#include "Scene.h"

namespace JSH
{
    class SelectScene : public Scene
    {
    public:
        SelectScene();
        virtual ~SelectScene();

        virtual void Initialize() override;
        virtual void Update() override;
        virtual void Render(HDC hdc) override;

        virtual void Enter();
        virtual void Exit();

    private:
        class Icon* mIcon;
        class BackGround* mBG;
        bool mChange;
    };
}