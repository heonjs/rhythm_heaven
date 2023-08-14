#pragma once
#include "TitleScene.h"
#include "SceneManager.h"
#include "Scene.h"

namespace JSH
{
    class EndingScene : public Scene
    {
    public:
        EndingScene();
        virtual ~EndingScene();

        virtual void Initialize();
        virtual void Update();
        virtual void Render(HDC hdc);

    private:

    };
}