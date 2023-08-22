#include "GleeClubIcon.h"
#include "Texture.h"
#include "JSHResourcemng.h"
#include "Transform.h"
#include "Collider.h"
#include "Icon.h"
#include "Object.h"
#include "SpriteRenderer.h"
#include "BackGround.h"
#include "Animationmng.h"
#include "GleeClubExplain.h"
#include "JSHinput.h"
#include "Sound.h"
#include "GleeExTitle.h"

namespace JSH
{
    GleeClubIcon::GleeClubIcon()
        : mGleeEx{ nullptr }
        , mGleeExt{ nullptr }
    {
    }
    GleeClubIcon::~GleeClubIcon()
    {
    }
    void GleeClubIcon::Initialize()
    {
        GameObject::Initialize();

        Animationmng* animationmng = AddComponent<Animationmng>();
        animationmng->SetScale(vector2(2.0f, 2.0f));

        Collider* col = AddComponent<Collider>();
        col->SetSize(vector2(60.0f, 52.0f));
        col->SetPosition(vector2(576.0f, 264.0f));

        Transform* tr = GetComponent<Transform>();
        tr->SetPosition(vector2(576.0f, 264.0f));

        //Frame
        Texture* iconframe = JSHResourcemng::Load<Texture>(L"IconFrame", L"..\\Resource\\GameSelect\\\Normal_Frame.bmp");
        BackGround* i2f = object::Instantiate<BackGround>(eLayerType::Effect);
        SpriteRenderer* i2fsr = i2f->AddComponent<SpriteRenderer>();
        Transform* i2ftr = i2f->GetComponent<Transform>();
        i2ftr->SetPosition(vector2(576.0f, 265.0f));
        i2fsr->SetTexture(iconframe);
        i2fsr->SetScale(vector2(2.0f, 2.0f));
        i2fsr->SetBmpRGB(255, 0, 255);

        //OK Button
        Texture* OK_Button = JSHResourcemng::Load<Texture>(L"OK_Button", L"..\\Resource\\GameSelect\\OK_Button.bmp");
        animationmng->CreateAnimation(L"OKButton", OK_Button, vector2::Zero, vector2(32.0f, 26.0f), 1);

        //OK Button Pressed
        Texture* Press_OK = JSHResourcemng::Load<Texture>(L"Press", L"..\\Resource\\GameSelect\\Press_OK.bmp");
        animationmng->CreateAnimation(L"Press_Button", Press_OK, vector2::Zero, vector2(32.0f, 26.0f), 1);

        //Icon
        Texture* icon2 = JSHResourcemng::Load<Texture>(L"GleeClubIcon", L"..\\Resource\\GameSelect\\Glee_Club_Icon.bmp");
        animationmng->CreateAnimation(L"GleeClubIcon", icon2, vector2::Zero, vector2(30.0f, 26.0f), 1);

        //Game Explain
        mGleeEx = object::Instantiate<GleeClubExplain>(eLayerType::Explain);
        Transform* getr = mGleeEx->GetComponent<Transform>();
        getr->SetPosition(vector2(192.0f, 320.0f));

        //Ex Title
        mGleeExt = object::Instantiate<GleeExTitle>(eLayerType::Explain);
        Transform* gettr = mGleeExt->GetComponent<Transform>();
        gettr->SetPosition(vector2(160.0f, 180.0f));

        animationmng->PlayAnimation(L"GleeClubIcon");
    }
    void GleeClubIcon::Update()
    {
        GameObject::Update();
    }
    void GleeClubIcon::Render(HDC hdc)
    {
        GameObject::Render(hdc);
    }
    void GleeClubIcon::OnColliderEnter(Collider* other)
    {
        Animationmng* animationmng = GetComponent<Animationmng>();

        animationmng->PlayAnimation(L"OKButton");
        mGleeEx->SetTrigger(true);
        mGleeExt->SetTrigger(true);
    }
    void GleeClubIcon::OnColliderStay(Collider* other)
    {
        Sound* sound = JSHResourcemng::Find<Sound>(L"SelectSound");
        Animationmng* animationmng = GetComponent<Animationmng>();

        if (input::GetKey(eKeyCode::Lbutton))
        {
            animationmng->PlayAnimation(L"Press_Button");
        }
        if (input::GetKeyUp(eKeyCode::Lbutton))
        {
            sound->Stop(true);
            SceneManager::LoadScene(L"GleeClubTitle");
        }
    }
    void GleeClubIcon::OnColliderExit(Collider* other)
    {
        Animationmng* animationmng = GetComponent<Animationmng>();
        animationmng->PlayAnimation(L"GleeClubIcon");
        mGleeEx->SetTrigger(false);
        mGleeExt->SetTrigger(false);
    }
}