#include "MoaiNPC.h"
#include "Transform.h"
#include "JSHinput.h"
#include "Time.h"
#include "Animationmng.h"
#include "JSHResourcemng.h"
#include "Object.h"
#include "Texture.h"
#include "Sound.h"

namespace JSH
{
    float MoaiNPC::mPlayTime = 0.0f;

    MoaiNPC::MoaiNPC()
        : mState(eState::Idle)
    {
    }
    MoaiNPC::~MoaiNPC()
    {
    }
    void MoaiNPC::Initialize()
    {
        GameObject::Initialize();

        Animationmng* mn = AddComponent<Animationmng>();
        mn->SetScale(vector2(2.0f, 2.0f));

        //NPC Idle
        Texture* NPCIdle = JSHResourcemng::Load<Texture>(L"NPCIdle", L"..\\Resource\\Ingame\\Moai\\NPC\\NPC_Idle.bmp");
        mn->CreateAnimation(L"NPCIdle", NPCIdle, vector2(0.0f, 0.0f), vector2(75.0f, 140.0f), 1);
        mn->SetBmpRGB(L"NPCIdle", 255, 0, 255);

        //NPC Pressed
        JSHResourcemng::Load<Sound>(L"NPCWoo", L"..\\Resource\\sound\\Moai_Doo-Wop\\NPC_Woo.wav");
        mn->CreateAnimationFolder(L"NPCPressed"
            , L"..\\Resource\\Ingame\\Moai\\NPC\\NPC_Pressed", vector2::Zero, 0.05f);
        mn->SetBmpRGB(L"NPCPressed", 255, 0, 255);

        //NPC KeyUp
        JSHResourcemng::Load<Sound>(L"NPCWop", L"..\\Resource\\sound\\Moai_Doo-Wop\\NPC_KeyUp.wav");
        mn->CreateAnimationFolder(L"NPCKeyUp", L"..\\Resource\\Ingame\\Moai\\NPC\\NPC_KeyUp");
        mn->SetBmpRGB(L"NPCKeyUp", 255, 0, 255);

        //NPC Touch
        JSHResourcemng::Load<Sound>(L"NPCTap", L"..\\Resource\\sound\\Moai_Doo-Wop\\NPC_Tap.wav");
        mn->CreateAnimationFolder(L"NPCTouch", L"..\\Resource\\Ingame\\Moai\\NPC\\NPC_Touch", vector2::Zero, 0.05f);
        mn->SetBmpRGB(L"NPCTouch", 255, 0, 255);

        mn->PlayAnimation(L"NPCIdle", true);
    }
    void MoaiNPC::Update()
    {
        mPlayTime += Time::DeltaTime();

        switch (mState) 
        {
        case JSH::MoaiNPC::eState::Idle:
            Idle();
            break;
        case JSH::MoaiNPC::eState::Pressed:
            Pressed();
            break;
        case JSH::MoaiNPC::eState::KeyUp:
            KeyUp();
            break;
        case JSH::MoaiNPC::eState::Touch:
            Touch();
            break;
        case JSH::MoaiNPC::eState::End:
            break;
        default:
            break;
        }

        GameObject::Update();
    }
    void MoaiNPC::Render(HDC hdc)
    {
        GameObject::Render(hdc);
    }

    void MoaiNPC::Idle()
    {
        Animationmng* animationmng = GetComponent<Animationmng>();
    }

    void MoaiNPC::Pressed()
    {
        Animationmng* animationmng = GetComponent<Animationmng>();
        animationmng->FindAnimation(L"NPCPressed");
        Sound* sound1 = JSHResourcemng::Find<Sound>(L"NPCWoo");
        Sound* sound2 = JSHResourcemng::Find<Sound>(L"NPCWop");

        if (animationmng->IsActiveAnimationComplete() == true)
        {
            sound1->Stop(true);
            animationmng->PlayAnimation(L"NPCIdle");
            mState = eState::Idle;
        }

        sound1->Play(false);
        animationmng->PlayAnimation(L"NPCPressed");
    }

    void MoaiNPC::KeyUp()
    {
        Animationmng* animationmng = GetComponent<Animationmng>();
        Sound* sound = JSHResourcemng::Find<Sound>(L"NPCWop");
        animationmng->FindAnimation(L"NPCKeyUp");

        sound->Play(false);
        animationmng->PlayAnimation(L"NPCKeyUp");
    }

    void MoaiNPC::Touch()
    {
        Animationmng* animationmng = GetComponent<Animationmng>();
        Sound* sound = JSHResourcemng::Find<Sound>(L"NPCTap");
        animationmng->FindAnimation(L"NPCTouch");

        sound->Play(false);
        animationmng->PlayAnimation(L"NPCTouch");
    }
}