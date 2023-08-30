#include "MoaiNPC.h"
#include "Transform.h"
#include "JSHinput.h"
#include "Time.h"
#include "Animationmng.h"
#include "JSHResourcemng.h"
#include "Object.h"
#include "Texture.h"
#include "Sound.h"
#include "MoaiPattern.h"

namespace JSH
{ 
    float MoaiNPC::mPlayTime = 0.0f;
    float MoaiNPC::miTime = 0.0;
    map<int, MoaiNPC::eState> MoaiNPC::mPattern = {};

    MoaiNPC::MoaiNPC()
        : mState(eState::Idle)
        , mPrevState(eState::Idle)
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
        mn->CreateAnimationFolder(L"NPCPressed", L"..\\Resource\\Ingame\\Moai\\NPC\\NPC_Pressed", vector2::Zero, 0.05f);
        mn->SetBmpRGB(L"NPCPressed", 255, 0, 255);

        //NPC KeyUp
        JSHResourcemng::Load<Sound>(L"NPCWop", L"..\\Resource\\sound\\Moai_Doo-Wop\\NPC_KeyUp.wav");
        mn->CreateAnimationFolder(L"NPCKeyUp", L"..\\Resource\\Ingame\\Moai\\NPC\\NPC_KeyUp", vector2::Zero, 0.05f);
        mn->SetBmpRGB(L"NPCKeyUp", 255, 0, 255);

        //NPC Touch
        JSHResourcemng::Load<Sound>(L"NPCTap", L"..\\Resource\\sound\\Moai_Doo-Wop\\Moai_Tap.wav");
        mn->CreateAnimationFolder(L"NPCTouch", L"..\\Resource\\Ingame\\Moai\\NPC\\NPC_Touch", vector2::Zero, 0.04f);
        mn->SetBmpRGB(L"NPCTouch", 255, 0, 255);

        mn->PlayAnimation(L"NPCIdle", true);
    }
    void MoaiNPC::Update()
    {
        GameObject::Update();

        mPlayTime += Time::DeltaTime();
        miTime = floor(mPlayTime * 100) / 100;

        Sound* sound1 = JSHResourcemng::Find<Sound>(L"NPCWoo");
        Sound* sound2 = JSHResourcemng::Find<Sound>(L"NPCWop");
        Sound* sound3 = JSHResourcemng::Find<Sound>(L"NPCTouch");

        //switch (mState) 
        //{
        //case JSH::MoaiNPC::eState::Idle:
        //    Idle();
        //    break;
        //case JSH::MoaiNPC::eState::Pressed:
        //    Pressed();
        //    break;
        //case JSH::MoaiNPC::eState::KeyUp:
        //    KeyUp();
        //    break;
        //case JSH::MoaiNPC::eState::Touch:
        //    Touch();
        //    break;
        //case JSH::MoaiNPC::eState::End:
        //    break;
        //default:
        //    break;
        //}        

        // Pattern 1
        if (miTime == 3.9f)
        {
            Pressed();

            //if (mPrevState != eState::Pressed)
            //{
            //    Sound* sound1 = JSHResourcemng::Find<Sound>(L"NPCWoo");
            //    sound1->Play(false);
            //}
        }
        if (miTime == 4.3f)
        {
            KeyUp();
        }
        if (miTime == 4.5f)
        {
            Idle();
        }
        if (miTime == 4.7f)
        {
            Pressed();
        }
        if (miTime == 5.1f)
        {
            KeyUp();
        }
        if (miTime == 5.3f)
        {
            Idle();
        }
        if (miTime == 5.5f)
        {
            Pressed();
        }
        if (miTime == 5.9f)
        {
            KeyUp();
        }
        if (miTime == 6.1f)
        {
            Idle();
        }
        if (miTime == 6.3f)
        {
            Pressed();
        }
        if (miTime == 6.7f)
        {
            KeyUp();
        }
        if (miTime == 6.9f)
        {
            Idle();
        }

        // Pattern to Pattern Gap == 3.8f

        // Pattern 2
        if (miTime == 10.2f)
        {
            Pressed();
        }
        if (miTime == 10.6f)
        {
            KeyUp();
        }
        if (miTime == 10.8f)
        {
            Idle();
        }
        if (miTime == 11.0f)
        {
            Pressed();
        }
        if (miTime == 11.4f)
        {
            KeyUp();
        }
        if (miTime == 11.6f)
        {
            Idle();
        }
        if (miTime == 11.8f)
        {
            Pressed();
        }
        if (miTime == 12.2f)
        {
            KeyUp();
        }
        if (miTime == 12.4f)
        {
            Idle();
        }
        if (miTime == 12.6f)
        {
            Touch();
        }
        if (miTime == 13.0f)
        {
            Touch();
        }
        if (miTime == 13.4f)
        {
            Idle();
        }

        // Pattern 3
        if (miTime == 16.5f)
        {
            Pressed();
        }
        if (miTime == 17.7f)
        {
            KeyUp();
        }
        if (miTime == 17.9f)
        {
            Idle();
        }
        if (miTime == 18.1f)
        {
            Touch();
        }
        if (miTime == 18.3f)
        {
            Idle();
        }
        if (miTime == 18.5f)
        {
            Touch();
        }
        if (miTime == 18.7f)
        {
            Idle();
        }
        if (miTime == 18.9f)
        {
            Touch();
        }
        if (miTime == 19.1f)
        {
            Idle();
        }

        // Pattern 4
        if (miTime == 22.9f)
        {
            Pressed();
        }
        if (miTime == 23.3f)
        {
            KeyUp();
        }
        if (miTime == 23.5f)
        {
            Idle();
        }
        if (miTime == 23.7f)
        {
            Pressed();
        }
        if (miTime == 24.1f)
        {
            KeyUp();
        }
        if (miTime == 24.3f)
        {
            Idle();
        }
        if (miTime == 24.5f)
        {
            Pressed();
        }
        if (miTime == 24.9f)
        {
            KeyUp();
        }
        if (miTime == 25.1f)
        {
            Idle();
        }
        if (miTime == 25.5f)
        {
            Touch();
        }
        if (miTime == 25.6f)
        {
            Idle();
        }
        if (miTime == 25.65f)
        {
            Touch();
        }
        if (miTime == 25.8f)
        {
            Idle();
        }

        // Pattern 5
        if (miTime == 29.2f)
        {
            Pressed();
        }
        if (miTime == 29.6f)
        {
            KeyUp();
        }
        if (miTime == 29.8f)
        {
            Idle();
        }
        if (miTime == 30.0f)
        {
            Pressed();
        }
        if (miTime == 30.4f)
        {
            KeyUp();
        }
        if (miTime == 30.6f)
        {
            Idle();
        }
        if (miTime == 30.8f)
        {
            Pressed();
        }
        if (miTime == 31.2f)
        {
            KeyUp();
        }
        if (miTime == 31.4f)
        {
            Idle();
        }
        if (miTime == 31.8f)
        {
            Touch();
        }
        if (miTime == 31.9f)
        {
            Idle();
        }
        if (miTime == 31.95f)
        {
            Touch();
        }
        if (miTime == 32.1f)
        {
            Idle();
        }

        // Pattern 6
    }
    void MoaiNPC::Render(HDC hdc)
    {
        GameObject::Render(hdc);
    }

    void MoaiNPC::Idle()
    {
        Animationmng* animationmng = GetComponent<Animationmng>();
        animationmng->FindAnimation(L"NPCIdle");

        animationmng->PlayAnimation(L"NPCIdle", false);

        mPrevState = eState::Idle;
    }
    void MoaiNPC::Pressed()
    {
        Animationmng* animationmng = GetComponent<Animationmng>();
        animationmng->FindAnimation(L"NPCPressed");
        Sound* sound1 = JSHResourcemng::Find<Sound>(L"NPCWoo");
        //Sound* sound = JSHResourcemng::Find<Sound>(L"NPCWop");

        //sound->Stop(true);
        sound1->Play(false);
        animationmng->PlayAnimation(L"NPCPressed", false);

        mPrevState = eState::Pressed;
    }

    void MoaiNPC::KeyUp()
    {
        Animationmng* animationmng = GetComponent<Animationmng>();
        Sound* sound = JSHResourcemng::Find<Sound>(L"NPCWop");
        Sound* sound1 = JSHResourcemng::Find<Sound>(L"NPCWoo");
        animationmng->FindAnimation(L"NPCKeyUp");

        sound1->Stop(true);     
        animationmng->PlayAnimation(L"NPCKeyUp", false);
        sound->Play(false);

        mPrevState = eState::KeyUp;
    }

    void MoaiNPC::Touch()
    {
        Animationmng* animationmng = GetComponent<Animationmng>();
        Sound* sound = JSHResourcemng::Find<Sound>(L"NPCTap");
        animationmng->FindAnimation(L"NPCTouch");

        sound->Play(false);
        animationmng->PlayAnimation(L"NPCTouch", false);

        mPrevState = eState::Touch;
    }
}