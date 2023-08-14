#pragma once
#include "Scene.h"

namespace JSH
{
    class GleeClub : public Scene
    {
    public:
        GleeClub();
        virtual ~GleeClub();

        virtual void Initialize() override;
        virtual void Update() override;
        virtual void Render(HDC hdc) override;

        virtual void Enter();
        virtual void Exit();

    private:
        bool SoundPlay;
    };
}