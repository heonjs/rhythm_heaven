#pragma once
#include "GameObject.h"

namespace JSH
{
    class Player2 : public GameObject
    {
    public:
        Player2();
        virtual ~Player2();

        virtual void Initialize() override;
        virtual void Update() override;
        virtual void Render(HDC hdc) override;

    private:

    };
}