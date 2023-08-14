#pragma once
#include "GameObject.h"

namespace JSH
{
    class BackGround : public GameObject
    {
    public:
        BackGround();
        virtual ~BackGround();

        virtual void Initialize() override;
        virtual void Update() override;
        virtual void Render(HDC hdc) override;

    private:

    };
}