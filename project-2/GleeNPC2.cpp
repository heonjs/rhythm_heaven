#include "GleeNPC2.h"
#include "Transform.h"
#include "JSHinput.h"
#include "Time.h"
#include "Animationmng.h"
#include "Object.h"
#include "GleePlayer.h"
#include "JSHResourcemng.h"
#include "Texture.h"

namespace JSH
{
    GleeNPC2::GleeNPC2()
        : mState(eState::Idle)
    {
    }
    GleeNPC2::~GleeNPC2()
    {
    }
    void GleeNPC2::Initialize()
    {
        GameObject::Initialize();

        Animationmng* gn2 = AddComponent<Animationmng>();
        gn2->SetScale(vector2(2.0f, 2.0f));

        //Glee Idle
        Texture* Gleeidle = JSHResourcemng::Load<Texture>(L"Gleeidle"
            , L"..\\Resource\\Ingame\\Glee_Club\\Glee_Idle.bmp");
        gn2->CreateAnimation(L"Gleeidle", Gleeidle, vector2(0.0f, 0.0f), vector2(48.0f, 72.0f), 3);
        gn2->SetBmpRGB(L"Gleeidle", 151, 151, 151);

        //Glee normal
        Texture* Gleetouch = JSHResourcemng::Load<Texture>(L"Gleenormal"
            , L"..\\Resource\\Ingame\\Glee_Club\\Glee_normal.bmp");
        gn2->CreateAnimation(L"Gleenormal", Gleetouch, vector2(0.0f, 0.0f), vector2(47.0f, 73.0f), 2);
        gn2->SetBmpRGB(L"Gleenormal", 151, 151, 151);

        //Glee Close Mouth
        Texture* Gleeclose = JSHResourcemng::Load<Texture>(L"Gleeclose"
            , L"..\\Resource\\Ingame\\Glee_Club\\Glee_Close.bmp");
        gn2->CreateAnimation(L"Gleeclose", Gleeclose, vector2(0.0f, 0.0f), vector2(48.0f, 72.0f), 3, vector2(0.0f, 0.0f), 0.05f);
        gn2->SetBmpRGB(L"Gleeclose", 151, 151, 151);

        //Glee Open Mouth
        gn2->CreateAnimationFolder(L"Gleeopen", L"..\\Resource\\Ingame\\Glee_Club\\Glee_Open", vector2(0.0f, 0.0f), 0.05f);
        gn2->SetBmpRGB(L"Gleeopen", 151, 151, 151);

        //Glee AH
        Texture* GleeAH = JSHResourcemng::Load<Texture>(L"GleeAH", L"..\\Resource\\Ingame\\Glee_Club\\Glee_Close.bmp");
        gn2->CreateAnimation(L"GleeAH", GleeAH, vector2(0.0f, 0.0f), vector2(48.0f, 72.0f), 3);
        gn2->SetBmpRGB(L"GleeAH", 151, 151, 151);

        //Glee Fail
        Texture* Gleefail = JSHResourcemng::Load<Texture>(L"Gleefail", L"..\\Resource\\Ingame\\Glee_Club\\Glee_fail.bmp");
        gn2->CreateAnimation(L"Gleefail", Gleefail, vector2(0.0f, 0.0f), vector2(48.0f, 72.0f), 3);
        gn2->SetBmpRGB(L"Gleefail", 151, 151, 151);

        gn2->PlayAnimation(L"Gleenormal", true);
    }
    void GleeNPC2::Update()
    {
        GameObject::Update();
    }
    void GleeNPC2::Render(HDC hdc)
    {
        GameObject::Render(hdc);
    }

    void GleeNPC2::Idle()
    {
        Animationmng* animationmng = GetComponent<Animationmng>();

    }
    void GleeNPC2::Touch()
    {
        Animationmng* animationmng = GetComponent<Animationmng>();
    }
    void GleeNPC2::Closing()
    {
        Animationmng* animationmng = GetComponent<Animationmng>();
    }
    void GleeNPC2::Opening()
    {
        Animationmng* animationmng = GetComponent<Animationmng>();
    }
    void GleeNPC2::AH()
    {
        Animationmng* animationmng = GetComponent<Animationmng>();
    }
    void GleeNPC2::Success()
    {
        Animationmng* animationmng = GetComponent<Animationmng>();
    }
    void GleeNPC2::Fail()
    {
        Animationmng* animationmng = GetComponent<Animationmng>();
    }
}