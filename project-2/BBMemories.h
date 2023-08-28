#pragma once
#include "GameObject.h"

namespace JSH
{
    class BBMemories : public GameObject
    {
    public:
        BBMemories();
        virtual ~BBMemories();

        virtual void Initialize();
        virtual void Update();
        virtual void Render(HDC hdc);

    private:
        bool mSwitch;
        float mTime;
    };
}