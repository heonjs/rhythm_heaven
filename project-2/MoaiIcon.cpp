#include "MoaiIcon.h"
#include "Texture.h"
#include "JSHResourcemng.h"
#include "Transform.h"
#include "Collider.h"
#include "Icon.h"
#include "Object.h"
#include "SpriteRenderer.h"
#include "BackGround.h"
#include "Animationmng.h"
#include "JSHinput.h"
#include "MoaiExplain.h"
#include "SceneManager.h"
#include "Sound.h"
#include "MoaiExTitle.h"

namespace JSH
{
    MoaiIcon::MoaiIcon()
        : moaiEx{ nullptr }
        , moaiExt{ nullptr }
    {      
    }
    MoaiIcon::~MoaiIcon()
    {
    }
    void MoaiIcon::Initialize()
    {
        GameObject::Initialize();

        Animationmng* animationmng = AddComponent<Animationmng>();
        animationmng->SetScale(vector2(2.0f, 2.0f));

        Animationmng* animationmng1 = AddComponent<Animationmng>();
        animationmng1->SetScale(vector2(2.0f, 2.0f));

        Collider* col = AddComponent<Collider>();
        col->SetSize(vector2(60.0f, 52.0f));
        col->SetPosition(vector2(576.0f, 144.0f));

        Transform* tr = GetComponent<Transform>();
        tr->SetPosition(vector2(576.0f, 144.0f));

        //Frame
        Texture* iconframe = JSHResourcemng::Load<Texture>(L"IconFrame", L"..\\Resource\\GameSelect\\\Normal_Frame.bmp");
        BackGround* i1f = object::Instantiate<BackGround>(eLayerType::Effect);
        SpriteRenderer* i1fsr = i1f->AddComponent<SpriteRenderer>();
        Transform* i1ftr = i1f->GetComponent<Transform>();
        i1ftr->SetPosition(vector2(576.0f, 145.0f));
        i1fsr->SetTexture(iconframe);
        i1fsr->SetScale(vector2(2.0f, 2.0f));
        i1fsr->SetBmpRGB(255, 0, 255);

        //OK Button
        Texture* OK_Button = JSHResourcemng::Load<Texture>(L"OK_Button", L"..\\Resource\\GameSelect\\OK_Button.bmp");
        animationmng->CreateAnimation(L"OKButton", OK_Button, vector2::Zero, vector2(32.0f, 26.0f), 1);

        //OK Button Pressed
        Texture* Press_OK = JSHResourcemng::Load<Texture>(L"Press", L"..\\Resource\\GameSelect\\Press_OK.bmp");
        animationmng->CreateAnimation(L"Press_Button", Press_OK, vector2::Zero, vector2(32.0f, 26.0f), 1);
        
        //Icon
        Texture* icon1 = JSHResourcemng::Load<Texture>(L"MoaiIcon", L"..\\Resource\\GameSelect\\Moai_Icon.bmp");
        animationmng->CreateAnimation(L"MoaiIcon", icon1, vector2::Zero, vector2(30.0f, 26.0f), 1);
        
        //Moai Explain
        moaiEx = object::Instantiate<MoaiExplain>(eLayerType::Explain);
        Transform* extr = moaiEx->GetComponent<Transform>();
        extr->SetPosition(vector2(192.0f, 320.0f));

        //Moai Explain Title
        moaiExt = object::Instantiate<MoaiExTitle>(eLayerType::Explain);
        Transform* exttr = moaiExt->GetComponent<Transform>();
        exttr->SetPosition(vector2(160.0f, 180.0f));

        animationmng->PlayAnimation(L"MoaiIcon");
    }
    void MoaiIcon::Update()
    {
        GameObject::Update();
    }
    void MoaiIcon::Render(HDC hdc)
    {
        GameObject::Render(hdc);
    }
    void MoaiIcon::OnColliderEnter(Collider* other)
    {
        Animationmng* animationmng = GetComponent<Animationmng>();

        animationmng->PlayAnimation(L"OKButton");
        moaiEx->SetTrigger(true);      
        moaiExt->SetTrigger(true);

    }
    void MoaiIcon::OnColliderStay(Collider* other)
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
            SceneManager::LoadScene(L"MoaiTitle");    
        }
    }
    void MoaiIcon::OnColliderExit(Collider* other)
    {
        Animationmng* animationmng = GetComponent<Animationmng>();       
        animationmng->PlayAnimation(L"MoaiIcon");
        moaiEx->SetTrigger(false);
        moaiExt->SetTrigger(false);
    }
}