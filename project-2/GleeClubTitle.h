#pragma once
#include "Scene.h"

namespace JSH
{
    class GleeClubTitle : public Scene
    {
    public:
        GleeClubTitle();
        virtual ~GleeClubTitle();

        virtual void Initialize() override;
        virtual void Update() override;
        virtual void Render(HDC hdc) override;

        virtual void Enter();
        virtual void Exit();

    private:

    };
}