#include "BlueBirdsExTitle.h"
#include "Texture.h"
#include "Animationmng.h"
#include "Transform.h"
#include "JSHResourcemng.h"

namespace JSH
{
    BlueBirdsExTitle::BlueBirdsExTitle()
        : mTrigger(false)
    {
    }
    BlueBirdsExTitle::~BlueBirdsExTitle()
    {
    }
    void BlueBirdsExTitle::Initialize()
    {
        GameObject::Initialize();

        Animationmng* animationmng = AddComponent<Animationmng>();

        //BlueBirds Explain Title
        Texture* BBExt = JSHResourcemng::Load<Texture>(L"BB_Ext", L"..\\Resource\\Ingame\\Blue_Bird\\BB_ExTitle.bmp");
        animationmng->CreateAnimation(L"BB_Ext", BBExt, vector2::Zero, vector2(140.0f, 35.0f), 1);
        animationmng->SetScale(vector2::One);

        animationmng->PlayAnimation(L"BB_Ext");
    }
    void BlueBirdsExTitle::Update()
    {
        GameObject::Update();
    }
    void BlueBirdsExTitle::Render(HDC hdc)
    {
        if (mTrigger == true)
        {
            GameObject::Render(hdc);
        }
    }
}