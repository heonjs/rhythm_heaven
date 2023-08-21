#include "MoaiExTitle.h"
#include "Animationmng.h"
#include "JSHResourcemng.h"
#include "Texture.h"
#include "Object.h"
#include "Transform.h"

namespace JSH
{
    MoaiExTitle::MoaiExTitle()
        : mTrigger(false)
    {
    }
    MoaiExTitle::~MoaiExTitle()
    {
    }
    void MoaiExTitle::Initialize()
    {
        GameObject::Initialize();

        Animationmng* animationmng = AddComponent<Animationmng>();

        //Moai ExTitle
        Texture* Moaiext = JSHResourcemng::Load<Texture>(L"MoaiExT", L"..\\Resource\\Ingame\\Moai\\Moai_ExTitle.bmp");
        animationmng->CreateAnimation(L"MoaiExT", Moaiext, vector2::Zero, vector2(200.0f, 150.0f), 1);
        animationmng->SetScale(vector2(1.2f, 1.2f));

        animationmng->PlayAnimation(L"MoaiExT");
    }
    void MoaiExTitle::Update()
    {
        GameObject::Update();
    }
    void MoaiExTitle::Render(HDC hdc)
    {
        if (mTrigger == true)
        {
            GameObject::Render(hdc);
        }
    }
}