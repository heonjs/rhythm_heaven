#include "GleeClubExplain.h"
#include "Animationmng.h"
#include "JSHResourcemng.h"
#include "Texture.h"
#include "Object.h"

namespace JSH
{
    GleeClubExplain::GleeClubExplain()
        : mTrigger(false)
    {
    }
    GleeClubExplain::~GleeClubExplain()
    {
    }
    void GleeClubExplain::Initialize()
    {
        GameObject::Initialize();

        Animationmng* animationmng = AddComponent<Animationmng>();

        //GleeClub Explain
        Texture* GleeClubEx = JSHResourcemng::Load<Texture>(L"GleeClub_Ex", L"..\\Resource\\Ingame\\Glee_Club\\GleeClub_Ex.bmp");
        animationmng->CreateAnimation(L"GleeEx", GleeClubEx, vector2::Zero, vector2(200.0f, 150.0f), 1);
        animationmng->SetScale(vector2(1.2f, 1.2f));

        animationmng->PlayAnimation(L"GleeEx");
    }
    void GleeClubExplain::Update()
    {
        GameObject::Update();
    }
    void GleeClubExplain::Render(HDC hdc)
    {
        if (mTrigger == true)
        {
            GameObject::Render(hdc);
        }
    }
}