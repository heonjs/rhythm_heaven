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

        // Pattern 1
        if (miTime == 3.9f)
        {
            Pressed();
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

        // Pattern to Pattern Gap == 3.4f

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
        if (miTime == 35.5f)
        {
            Pressed();
        }
        if (miTime == 36.7f)
        {
            KeyUp();
        }
        if (miTime == 36.9f)
        {
            Idle();
        }
        if (miTime == 37.1f)
        {
            Touch();
        }
        if (miTime == 37.3f)
        {
            Idle();
        }
        if (miTime == 37.5f)
        {
            Touch();
        }
        if (miTime == 37.7f)
        {
            Idle();
        }
        if (miTime == 37.9f)
        {
            Touch();
        }
        if (miTime == 38.1f)
        {
            Idle();
        }

        //Pattern 7
        if (miTime == 42.3f)
        {
            Touch();
        }
        if (miTime == 42.35f)
        {
            Idle();
        }
        if (miTime == 42.45f)
        {
            Touch();
        }
        if (miTime == 42.6f)
        {
            Idle();
        }
        if (miTime == 43.0f)
        {
            Touch();
        }
        if (miTime == 43.2f)
        {
            Idle();
        }
        if (miTime == 43.8f)
        {
            Touch();
        }
        if (miTime == 43.85f)
        {
            Idle();
        }
        if (miTime == 43.95f)
        {
            Touch();
        }
        if (miTime == 44.1f)
        {
            Idle();
        }
        if (miTime == 44.6f)
        {
            Touch();
        }
        if (miTime == 44.7f)
        {
            Idle();
        }

        //Pattern 8
        if (miTime == 48.6f)
        {
            Touch();
        }
        if (miTime == 48.65f)
        {
            Idle();
        }
        if (miTime == 48.75f)
        {
            Touch();
        }
        if (miTime == 48.9f)
        {
            Idle();
        }
        if (miTime == 49.3f)
        {
            Touch();
        }
        if (miTime == 49.5f)
        {
            Idle();
        }
        if (miTime == 50.2f)
        {
            Touch();
        }
        if (miTime == 50.25f)
        {
            Idle();
        }
        if (miTime == 50.35f)
        {
            Touch();
        }
        if (miTime == 50.5f)
        {
            Idle();
        }
        if (miTime == 51.0f)
        {
            Touch();
        }
        if (miTime == 51.1f)
        {
            Idle();
        }

        // Pattern 9
        if (miTime == 54.9f)
        {
            Touch();
        }
        if (miTime == 54.95f)
        {
            Idle();
        }
        if (miTime == 55.05f)
        {
            Touch();
        }
        if (miTime == 55.2f)
        {
            Idle();
        }
        if (miTime == 55.3f)
        {
            Pressed();
        }
        if (miTime == 55.7f)
        {
            KeyUp();
        }
        if (miTime == 55.9f)
        {
            Idle();
        }
        if (miTime == 56.5f)
        {
            Touch();
        }
        if (miTime == 56.55f)
        {
            Idle();
        }
        if (miTime == 56.65f)
        {
            Touch();
        }
        if (miTime == 56.8f)
        {
            Idle();
        }
        if (miTime == 56.9f)
        {
            Pressed();
        }
        if (miTime == 57.3f)
        {
            KeyUp();
        }
        if (miTime == 57.5f)
        {
            Idle();
        }

        // Pattern 10
        if (miTime == 60.8f)
        {
            Pressed();
        }
        if (miTime == 61.6f)
        {
            KeyUp();
        }
        if (miTime == 61.8f)
        {
            Idle();
        }
        if (miTime == 62.4f)
        {
            Pressed();
        }
        if (miTime == 63.0f)
        {
            KeyUp();
        }
        if (miTime == 63.2f)
        {
            Idle();
        }

        // Pattern 11
        if (miTime == 67.1f)
        {
            Pressed();
        }
        if (miTime == 67.9f)
        {
            KeyUp();
        }
        if (miTime == 68.1f)
        {
            Idle();
        }
        if (miTime == 68.7f)
        {
            Pressed();
        }
        if (miTime == 69.3f)
        {
            KeyUp();
        }
        if (miTime == 69.5f)
        {
            Idle();
        }

        // Pattern 12
        if (miTime == 73.4f)
        {
            Pressed();
        }
        if (miTime == 74.6f)
        {
            KeyUp();
        }
        if (miTime == 74.8f)
        {
            Idle();
        }
        if (miTime == 75.0f)
        {
            Touch();
        }
        if (miTime == 75.2f)
        {
            Idle();
        }
        if (miTime == 75.4f)
        {
            Touch();
        }
        if (miTime == 75.6f)
        {
            Idle();
        }
        if (miTime == 75.8f)
        {
            Touch();
        }
        if (miTime == 76.0f)
        {
            Idle();
        }
        if (miTime == 76.2f)
        {
            Touch();
        }
        if (miTime == 76.4f)
        {
            Idle();
        }
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
    }

    void MoaiNPC::Touch()
    {
        Animationmng* animationmng = GetComponent<Animationmng>();
        Sound* sound = JSHResourcemng::Find<Sound>(L"NPCTap");
        animationmng->FindAnimation(L"NPCTouch");

        sound->Play(false);
        animationmng->PlayAnimation(L"NPCTouch", false);
    }
}