#include "BlueBirdsExplain.h"
#include "Texture.h"
#include "Animationmng.h"
#include "Transform.h"
#include "JSHResourcemng.h"

namespace JSH
{
    BlueBirdsExplain::BlueBirdsExplain()
        : mTrigger(false)
    {
    }
    BlueBirdsExplain::~BlueBirdsExplain()
    {
    }
    void BlueBirdsExplain::Initialize()
    {
        GameObject::Initialize();

        Animationmng* animationmng = AddComponent<Animationmng>();

        //BlueBirds Explain
        Texture* BBEx = JSHResourcemng::Load<Texture>(L"BB_ex", L"..\\Resource\\Ingame\\Blue_Bird\\BB_Explain.bmp");
        animationmng->CreateAnimation(L"BB_Ex", BBEx, vector2::Zero, vector2(200.0f, 150.0f), 1);
        animationmng->SetScale(vector2(1.2f, 1.2f));

        animationmng->PlayAnimation(L"BB_Ex");
    }
    void BlueBirdsExplain::Update()
    {
        GameObject::Update();
    }
    void BlueBirdsExplain::Render(HDC hdc)
    {
        if (mTrigger == true)
        {
            GameObject::Render(hdc);
        }
    }
}