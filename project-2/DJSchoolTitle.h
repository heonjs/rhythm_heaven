#pragma once
#include "Scene.h"

namespace JSH
{
    class DJSchoolTitle : public Scene
    {
    public:
        DJSchoolTitle();
        virtual ~DJSchoolTitle();

        virtual void Initialize() override;
        virtual void Update() override;
        virtual void Render(HDC hdc) override;

    private:
        
    };
}