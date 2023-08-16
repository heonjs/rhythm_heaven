#include "MoaiPlayer.h"
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
    float MoaiPlayer::mTime = 0.0f;

    MoaiPlayer::MoaiPlayer()
        : mState(eState::Idle)
        , mPressed(false)
    {
    }
    MoaiPlayer::~MoaiPlayer()
    {
    }
    void MoaiPlayer::Initialize()
    {
        GameObject::Initialize();

        Animationmng* mp = AddComponent<Animationmng>();
        mp->SetScale(vector2(2.0f, 2.0f));
        
        //Moai Idle
        Texture* MoaiIdle = JSHResourcemng::Load<Texture>(L"MoaiIdle"
            , L"..\\Resource\\Ingame\\Moai\\Player\\Moai_Idle.bmp");
        mp->CreateAnimation(L"MoaiIdle", MoaiIdle, vector2(0.0f, 0.0f), vector2(75.0f, 140.0f), 1);
        mp->SetBmpRGB(L"MoaiIdle", 255, 0, 255);

        //Moai Pressed
        JSHResourcemng::Load<Sound>(L"MoaiWoo", L"..\\Resource\\sound\\Moai_Doo-Wop\\Moai_Woo.wav");
        mp->CreateAnimationFolder(L"MoaiPressed"
            , L"..\\Resource\\Ingame\\Moai\\Player\\Moai_Pressed", vector2::Zero, 0.05f);
        mp->SetBmpRGB(L"MoaiPressed", 255, 0, 255);

        //Moai KeyUp
        JSHResourcemng::Load<Sound>(L"MoaiWop", L"..\\Resource\\sound\\Moai_Doo-Wop\\Moai_KeyUp.wav");
        mp->CreateAnimationFolder(L"MoaiKeyUp"
            , L"..\\Resource\\Ingame\\Moai\\Player\\Moai_KeyUp", vector2::Zero, 0.07f);
        mp->SetBmpRGB(L"MoaiKeyUp", 255, 0, 255);

        //Moai Touch
        JSHResourcemng::Load<Sound>(L"MoaiTap", L"..\\Resource\\sound\\Moai_Doo-Wop\\Moai_Tap.wav");
        mp->CreateAnimationFolder(L"MoaiTouch", L"..\\Resource\\Ingame\\Moai\\Player\\Moai_Touch", vector2::Zero, 0.05f);
        mp->SetBmpRGB(L"MoaiTouch", 255, 0, 255);

        mp->PlayAnimation(L"MoaiIdle", true);
    }
    void MoaiPlayer::Update()
    {
        GameObject::Update();

        switch (mState)
        {
        case JSH::MoaiPlayer::eState::Idle:
            Idle();
            break;
        case JSH::MoaiPlayer::eState::Pressed:
            Pressed();
            break;
        case JSH::MoaiPlayer::eState::KeyUp:
            KeyUp();
            break;
        case JSH::MoaiPlayer::eState::Touch:
            Touch();
            break;
        case JSH::MoaiPlayer::eState::End:
            break;
        default:
            break;
        }
    }
    void MoaiPlayer::Render(HDC hdc)
    {
        GameObject::Render(hdc);
    }

    void MoaiPlayer::Idle()
    {

        Animationmng* animationmng = GetComponent<Animationmng>();
        Sound* sound1 = JSHResourcemng::Find<Sound>(L"MoaiWoo");
        Sound* sound2 = JSHResourcemng::Find<Sound>(L"MoaiTap");

        if (mPressed == true)
        {
            sound1->Play(false);
            animationmng->PlayAnimation(L"MoaiPressed", false);
            mState = eState::Pressed;
            mTime = 0.0f;
        }

        if (input::GetKey(eKeyCode::Lbutton))
        {
            mTime += Time::DeltaTime();

            if (mTime >= 0.1f)
            {
                sound1->Play(false);
                animationmng->PlayAnimation(L"MoaiPressed", false);
                mState = eState::Pressed;
                mTime = 0.0f;
            }
        }
        
        if (input::GetKeyUp(eKeyCode::Lbutton))
        {
            if (mTime <= 0.07f)
            {
                sound2->Play(false);
                animationmng->PlayAnimation(L"MoaiTouch", false);
                mState = eState::Touch;
                mTime = 0.0f;
            }
            else if (mTime > 0.07f)
            {
                mTime = 0.0f;;
            }
        }

        //if (input::GetKey(eKeyCode::Lbutton))
        //{
        //    pTime += Time::DeltaTime();

        //    if (pTime >= 0.1f)
        //    {
        //        mPressed = true;
        //    }
        //    else if (pTime < 0.1f)
        //    {
        //        sound2->Play(false);
        //        animationmng->PlayAnimation(L"MoaiTouch", false);
        //        mState = eState::Touch;
        //        pTime = 0.0f;
        //    }           
        //}       
    }
    void MoaiPlayer::Pressed()
    {
        Animationmng* animationmng = GetComponent<Animationmng>();
        Sound* sound1 = JSHResourcemng::Find<Sound>(L"MoaiWoo");
        Sound* sound2 = JSHResourcemng::Find<Sound>(L"MoaiWop");     

        if (input::GetKeyUp(eKeyCode::Lbutton))
        {
            sound1->Stop(false);
            sound2->Play(false);
            animationmng->PlayAnimation(L"MoaiKeyUp", false);
            mState = eState::KeyUp;
        }
    }
    void MoaiPlayer::KeyUp()
    {
        Animationmng* animationmng = GetComponent<Animationmng>();
        Sound* sound1 = JSHResourcemng::Find<Sound>(L"MoaiWoo");
        Sound* sound2 = JSHResourcemng::Find<Sound>(L"MoaiWop");

        if (animationmng->IsActiveAnimationComplete() == true)
        {
            animationmng->PlayAnimation(L"MoaiIdle", true);
            mState = eState::Idle;
            mTime = 0.0f;
        }
        if (input::GetKeyDown(eKeyCode::Lbutton))
        {
            sound1->Play(false);
            animationmng->PlayAnimation(L"MoaiPressed", false);
            mState = eState::Pressed;
        }
    }
    void MoaiPlayer::Touch()
    {
        Animationmng* animationmng = GetComponent<Animationmng>();
        Sound* sound1 = JSHResourcemng::Find<Sound>(L"MoaiTap");

        if (animationmng->IsActiveAnimationComplete() == true)
        {
            animationmng->PlayAnimation(L"MoaiIdle", false);
            mState = eState::Idle;
        }
        if (input::GetKeyDown(eKeyCode::Lbutton))
        {
            sound1->Play(false);
            animationmng->PlayAnimation(L"MoaiTouch", false);
            mState = eState::Touch;
        }
    }
}