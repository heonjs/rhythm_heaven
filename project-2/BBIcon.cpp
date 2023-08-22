#include "BBIcon.h"
#include "Texture.h"
#include "JSHResourcemng.h"
#include "Transform.h"
#include "Collider.h"
#include "Icon.h"
#include "Object.h"
#include "SpriteRenderer.h"
#include "BackGround.h"
#include "JSHinput.h"
#include "Animationmng.h"
#include "SceneManager.h"
#include "Sound.h"
#include "BlueBirdsExplain.h"
#include "BlueBirdsExTitle.h"

namespace JSH
{
    BBIcon::BBIcon()
        : BBEx{ nullptr }
        , BBExt{ nullptr }
    {
    }
    BBIcon::~BBIcon()
    {
    }
    void BBIcon::Initialize()
    {
        GameObject::Initialize();

        Animationmng* animationmng = AddComponent<Animationmng>();
        animationmng->SetScale(vector2(2.0f, 2.0f));

        Collider* col = AddComponent<Collider>();
        col->SetSize(vector2(60.0f, 52.0f));
        col->SetPosition(vector2(576.0f, 385.0f));

        Transform* tr = GetComponent<Transform>();
        tr->SetPosition(vector2(576.0f, 385.0f));

        //Frame
        Texture* iconframe = JSHResourcemng::Load<Texture>(L"IconFrame", L"..\\Resource\\GameSelect\\\Normal_Frame.bmp");
        BackGround* i3f = object::Instantiate<BackGround>(eLayerType::Effect);
        SpriteRenderer* i3fsr = i3f->AddComponent<SpriteRenderer>();
        Transform* i3ftr = i3f->GetComponent<Transform>();
        i3ftr->SetPosition(vector2(576.0f, 385.0f));
        i3fsr->SetTexture(iconframe);
        i3fsr->SetScale(vector2(2.0f, 2.0f));
        i3fsr->SetBmpRGB(255, 0, 255);

        //OK Button
        Texture* OK_Button = JSHResourcemng::Load<Texture>(L"OK_Button", L"..\\Resource\\GameSelect\\OK_Button.bmp");
        animationmng->CreateAnimation(L"OKButton", OK_Button, vector2::Zero, vector2(32.0f, 26.0f), 1);

        //OK Button Pressed
        Texture* Press_OK = JSHResourcemng::Load<Texture>(L"Press", L"..\\Resource\\GameSelect\\Press_OK.bmp");
        animationmng->CreateAnimation(L"Press_Button", Press_OK, vector2::Zero, vector2(32.0f, 26.0f), 1);

        //Icon
        Texture* bbicon = JSHResourcemng::Load<Texture>(L"BlueBirdsIcon", L"..\\Resource\\GameSelect\\Blue_Birds_Icon.bmp");
        animationmng->CreateAnimation(L"BBIcon", bbicon, vector2::Zero, vector2(30.0f, 26.0f), 1);

        //BB Explain
        BBEx = object::Instantiate<BlueBirdsExplain>(eLayerType::Explain);
        Transform* extr = BBEx->GetComponent<Transform>();
        extr->SetPosition(vector2(192.0f, 320.0f));

        //BB Explain Title
        BBExt = object::Instantiate<BlueBirdsExTitle>(eLayerType::Explain);
        Transform* exttr = BBExt->GetComponent<Transform>();
        exttr->SetPosition(vector2(160.0f, 180.0f));

        animationmng->PlayAnimation(L"BBIcon");
    }
    void BBIcon::Update()
    {
        GameObject::Update();
    }
    void BBIcon::Render(HDC hdc)
    {
        GameObject::Render(hdc);
    }
    void BBIcon::OnColliderEnter(Collider* other)
    {
        Animationmng* animationmng = GetComponent<Animationmng>();

        animationmng->PlayAnimation(L"OKButton");
        BBEx->SetTrigger(true);
        BBExt->SetTrigger(true);
    }
    void BBIcon::OnColliderStay(Collider* other)
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
            SceneManager::LoadScene(L"BlueBirdsTitle");
        }
    }
    void BBIcon::OnColliderExit(Collider* other)
    {
        Animationmng* animationmng = GetComponent<Animationmng>();
        animationmng->PlayAnimation(L"BBIcon");
        BBEx->SetTrigger(false);
        BBExt->SetTrigger(false);
    }
}