#include "GleeEndImage.h"
#include "Texture.h"
#include "Animationmng.h"
#include "Transform.h"
#include "JSHResourcemng.h"
#include "GleeClub.h"

namespace JSH
{
    GleeEndImage::GleeEndImage()
    {
    }
    GleeEndImage::~GleeEndImage()
    {
    }
    void GleeEndImage::Initialize()
    {
        GameObject::Initialize();

        Animationmng* animationmng = AddComponent<Animationmng>();
        animationmng->SetScale(vector2(2.0f, 2.0f));

        //GleeClub Perfect Animation
        Texture* Perfect = JSHResourcemng::Load<Texture>(L"GleePerfect", L"..\\Resource\\Ingame\\Glee_Club\\Glee_End_Perfect.bmp");
        animationmng->CreateAnimation(L"GleePerfect", Perfect, vector2::Zero, vector2(128.0f, 80.0f), 1);

        //GleeClub OK Animation
        Texture* OK = JSHResourcemng::Load<Texture>(L"GleeOK", L"..\\Resource\\Ingame\\Glee_Club\\Glee_End_OK.bmp");
        animationmng->CreateAnimation(L"GleeOK", OK, vector2::Zero, vector2(128.0f, 80.0f), 1);

        //GleeClub Bad Animation
        Texture* Bad = JSHResourcemng::Load<Texture>(L"GleeBad", L"..\\Resource\\Ingame\\Glee_Club\\Glee_End_Bad.bmp");
        animationmng->CreateAnimation(L"GleeBad", Bad, vector2::Zero, vector2(128.0f, 80.0f), 1);
    }
    void GleeEndImage::Update()
    {
        GameObject::Update();

        Animationmng* animationmng = GetComponent<Animationmng>();

        if (GleeClub::GetScore() >= 100.0f)
        {
            animationmng->PlayAnimation(L"GleePerfect");
        }
        else if (GleeClub::GetScore() < 100.0f and GleeClub::GetScore() >= 30.0f)
        {
            animationmng->PlayAnimation(L"GleeOK");
        }
        else if (GleeClub::GetScore() < 30.0f)
        {
            animationmng->PlayAnimation(L"GleeBad");
        }
    }
    void GleeEndImage::Render(HDC hdc)
    {
        GameObject::Render(hdc);
    }
}