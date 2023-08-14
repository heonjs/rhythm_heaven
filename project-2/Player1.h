#pragma once
#include "GameObject.h"

namespace JSH
{
    class Player1 : public GameObject
    {
    public:
        Player1();
        virtual ~Player1();

        virtual void Initialize() override;
        virtual void Update() override;
        virtual void Render(HDC hdc) override;

    private:

    };

}