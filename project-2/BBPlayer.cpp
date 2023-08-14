#include "BBPlayer.h"
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
    BBPlayer::BBPlayer()
        :mState(eState::Idle)
    {
    }
    BBPlayer::~BBPlayer()
    {
    }
    void BBPlayer::Initialize()
    {
        GameObject::Initialize();

        Animationmng* animationmng = AddComponent<Animationmng>();
        animationmng->SetScale(vector2(2.0f, 2.0f));

        //BB Idle
        Texture* BB_Idle = JSHResourcemng::Load<Texture>(L"BB_Idle"
            , L"..\\Resource\\Ingame\\Blue_Bird\\BB_Idle.bmp");
        animationmng->CreateAnimation(L"BB_Idle", BB_Idle, vector2(0.0f, 0.0f), vector2(51.0f, 97.0f), 4, vector2::Zero, 0.11f);
        animationmng->SetBmpRGB(L"BB_Idle", 227, 178, 255);

        //BB Peak
        Texture* BB_Peak = JSHResourcemng::Load<Texture>(L"BB_Peak"
            , L"..\\Resource\\Ingame\\Blue_Bird\\BB_Peak.bmp");
        JSHResourcemng::Load<Sound>(L"BB_Peak_S", L"..\\Resource\\sound\\Blue_Birds\\SE_BIRD_KOTU_PLAYER.wav");
        animationmng->CreateAnimation(L"BB_Peak", BB_Peak, vector2(0.0f, 0.0f), vector2(58.0f, 110.0f), 5, vector2::Zero, 0.05f);
        animationmng->SetBmpRGB(L"BB_Peak", 227, 178, 255);

        animationmng->PlayAnimation(L"BB_Idle", true);
    }
    void BBPlayer::Update()
    {
        switch (mState)
        {
        case JSH::BBPlayer::eState::Idle:
            Idle();
            break;
        case JSH::BBPlayer::eState::Hit:
            Hit();
            break;
        case JSH::BBPlayer::eState::Squat:
            Squat();
            break;
        case JSH::BBPlayer::eState::Stretch:
            Stretch();
            break;
        case JSH::BBPlayer::eState::End:
            break;
        default:
            break;
        }

        GameObject::Update();
    }
    void BBPlayer::Render(HDC hdc)
    {
        GameObject::Render(hdc);
    }

    void BBPlayer::Idle()
    {
        Animationmng* animationmng = GetComponent<Animationmng>();
        animationmng->FindAnimation(L"BB_Peak");

        Sound* sound = JSHResourcemng::Find<Sound>(L"BB_Peak_S");

        if (input::GetKeyDown(eKeyCode::Lbutton))
        {
            sound->SetPosition(0.2f, false);
            animationmng->PlayAnimation(L"BB_Peak", false);
            mState = eState::Hit;
        }
    }
    void BBPlayer::Hit()
    {
        Animationmng* animationmng = GetComponent<Animationmng>();
        animationmng->FindAnimation(L"BB_Idle");

        if (input::GetKeyUp(eKeyCode::Lbutton))
        {
            animationmng->PlayAnimation(L"BB_Idle", true);
            mState = eState::Idle;
        }

    }
    void BBPlayer::Squat()
    {
        Animationmng* animationmng = GetComponent<Animationmng>();
    }
    void BBPlayer::Stretch()
    {
        Animationmng* animationmng = GetComponent<Animationmng>();
    }
}