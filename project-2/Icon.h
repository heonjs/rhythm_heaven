#pragma once
#include "GameObject.h"

namespace JSH
{
    enum class eIcontype
    {
        Moai,
        GleeClub,
        BlueBirds,
        Cafe,
        End
    };

    class Icon : public GameObject
    {
    public:
        Icon();
        virtual ~Icon();

        virtual void Initialize();
        virtual void Update();
        virtual void Render(HDC hdc);

        virtual void OncollisionEnter();
        virtual void OncollisionExit();

    private:
        eIcontype   mType;
        class Animationmng* mAnimationmng;

    };
}