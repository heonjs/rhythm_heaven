#pragma once
#include "Scene.h"

namespace JSH
{
    class FanClub : public Scene
    {
    public:
        FanClub();
        virtual ~FanClub();

        virtual void Initialize() override;
        virtual void Update() override;
        virtual void Render(HDC hdc) override;

    private:

    };
}