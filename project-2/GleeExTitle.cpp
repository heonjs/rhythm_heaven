#include "GleeExTitle.h"
#include "Animationmng.h"
#include "JSHResourcemng.h"
#include "Texture.h"
#include "Object.h"

namespace JSH
{
    GleeExTitle::GleeExTitle()
        : mTrigger(false)
    {
    }
    GleeExTitle::~GleeExTitle()
    {
    }
    void GleeExTitle::Initialize()
    {
        GameObject::Initialize();

        Animationmng* animationmng = AddComponent<Animationmng>();

        //GleeClub ExTitle
        Texture* GleeExt = JSHResourcemng::Load<Texture>(L"GleeExT", L"..\\Resource\\Ingame\\Glee_Club\\GleeClub_ExTitle.bmp");
        animationmng->CreateAnimation(L"GleeExT", GleeExt, vector2::Zero, vector2(105.0f, 35.0f), 1);
        animationmng->SetScale(vector2::One);

        animationmng->PlayAnimation(L"GleeExT");
    }
    void GleeExTitle::Update()
    {
        GameObject::Update();
    }
    void GleeExTitle::Render(HDC hdc)
    {
        if (mTrigger == true)
        {
            GameObject::Render(hdc);
        }
    }
}