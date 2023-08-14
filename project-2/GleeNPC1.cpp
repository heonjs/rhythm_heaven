#include "GleeNPC1.h"
#include "Transform.h"
#include "JSHinput.h"
#include "Time.h"
#include "Animationmng.h"
#include "JSHResourcemng.h"
#include "Object.h"
#include "Texture.h"

namespace JSH
{
    GleeNPC1::GleeNPC1()
        : mState(eState::Idle)
    {
    }
    GleeNPC1::~GleeNPC1()
    {
    }
    void GleeNPC1::Initialize()
    {
        GameObject::Initialize();

        Animationmng* gn1 = AddComponent<Animationmng>();
        gn1->SetScale(vector2(2.0f, 2.0f));

        //Glee Idle
        Texture* Gleeidle = JSHResourcemng::Load<Texture>(L"Gleeidle"
            , L"..\\Resource\\Ingame\\Glee_Club\\Glee_Idle.bmp");
        gn1->CreateAnimation(L"Gleeidle", Gleeidle, vector2(0.0f, 0.0f), vector2(48.0f, 72.0f), 3);
        gn1->SetBmpRGB(L"Gleeidle", 151, 151, 151);

        //Glee normal
        Texture* Gleetouch = JSHResourcemng::Load<Texture>(L"Gleenormal"
            , L"..\\Resource\\Ingame\\Glee_Club\\Glee_normal.bmp");
        gn1->CreateAnimation(L"Gleenormal", Gleetouch, vector2(0.0f, 0.0f), vector2(47.0f, 73.0f), 2);
        gn1->SetBmpRGB(L"Gleenormal", 151, 151, 151);

        //Glee Close Mouth
        Texture* Gleeclose = JSHResourcemng::Load<Texture>(L"Gleeclose"
            , L"..\\Resource\\Ingame\\Glee_Club\\Glee_Close.bmp");
        gn1->CreateAnimation(L"Gleeclose", Gleeclose, vector2(0.0f, 0.0f), vector2(48.0f, 72.0f), 3, vector2(0.0f, 0.0f), 0.05f);
        gn1->SetBmpRGB(L"Gleeclose", 151, 151, 151);

        //Glee Open Mouth
        gn1->CreateAnimationFolder(L"Gleeopen", L"..\\Resource\\Ingame\\Glee_Club\\Glee_Open", vector2(0.0f, 0.0f), 0.05f);
        gn1->SetBmpRGB(L"Gleeopen", 151, 151, 151);

        //Glee AH
        Texture* GleeAH = JSHResourcemng::Load<Texture>(L"GleeAH", L"..\\Resource\\Ingame\\Glee_Club\\Glee_Close.bmp");
        gn1->CreateAnimation(L"GleeAH", GleeAH, vector2(0.0f, 0.0f), vector2(48.0f, 72.0f), 3);
        gn1->SetBmpRGB(L"GleeAH", 151, 151, 151);

        //Glee Fail
        Texture* Gleefail = JSHResourcemng::Load<Texture>(L"Gleefail", L"..\\Resource\\Ingame\\Glee_Club\\Glee_fail.bmp");
        gn1->CreateAnimation(L"Gleefail", Gleefail, vector2(0.0f, 0.0f), vector2(48.0f, 72.0f), 3);
        gn1->SetBmpRGB(L"Gleefail", 151, 151, 151);

        gn1->PlayAnimation(L"Gleenormal", true);
    }
    void GleeNPC1::Update()
    {
        GameObject::Update();
    }
    void GleeNPC1::Render(HDC hdc)
    {
        GameObject::Render(hdc);
    }

    void GleeNPC1::Idle()
    {
        Animationmng* animationmng = GetComponent<Animationmng>();
    }
    void GleeNPC1::Touch()
    {
        Animationmng* animationmng = GetComponent<Animationmng>();
    }
    void GleeNPC1::Closing()
    {
        Animationmng* animationmng = GetComponent<Animationmng>();
    }
    void GleeNPC1::Opening()
    {
        Animationmng* animationmng = GetComponent<Animationmng>();
    }
    void GleeNPC1::AH()
    {
        Animationmng* animationmng = GetComponent<Animationmng>();
    }
    void GleeNPC1::Success()
    {
        Animationmng* animationmng = GetComponent<Animationmng>();
    }
    void GleeNPC1::Fail()
    {
        Animationmng* animationmng = GetComponent<Animationmng>();
    }
}