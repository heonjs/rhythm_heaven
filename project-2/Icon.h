#pragma once
#include "GameObject.h"

namespace JSH
{
    class Icon : public GameObject
    {
    public:
        Icon();
        virtual ~Icon();

        virtual void Initialize() override;
        virtual void Update() override;
        virtual void Render(HDC hdc) override;

    private:

    };
}