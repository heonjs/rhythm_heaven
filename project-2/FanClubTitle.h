#pragma once
#include "Scene.h"

namespace JSH
{
    class FanClubTitle : public Scene
    {
    public:
        FanClubTitle();
        virtual ~FanClubTitle();

        virtual void Initialize() override;
        virtual void Update() override;
        virtual void Render(HDC hdc) override;

    private:

    };
}