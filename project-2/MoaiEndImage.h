#pragma once
#include "GameObject.h"

namespace JSH
{
    class MoaiEndImage : public GameObject
    {
    public:
        MoaiEndImage();
        virtual ~MoaiEndImage();

        virtual void Initialize() override;
        virtual void Update() override;
        virtual void Render(HDC hdc) override;

    private:

    };
}