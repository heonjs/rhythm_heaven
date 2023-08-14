#include "GleePlayer.h"
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
    GleePlayer::GleePlayer()
        : mState(eState::Idle)
    {
    }
    GleePlayer::~GleePlayer()
    {
    }
    void GleePlayer::Initialize()
    {
        GameObject::Initialize();

        Animationmng* gp = AddComponent<Animationmng>();
        gp->SetScale(vector2(2.0f, 2.0f));

        //Glee Idle
        JSHResourcemng::Load<Sound>(L"Glee_KeyUp_S", L"..\\Resource\\sound\\Glee_Club\\Glee_Idle.wav");
        Texture* Gleeidle = JSHResourcemng::Load<Texture>(L"GleeIdle"
            , L"..\\Resource\\Ingame\\Glee_Club\\Glee_Idle.bmp");
        gp->CreateAnimation(L"GleeIdle", Gleeidle, vector2(0.0f, 0.0f), vector2(48.0f, 72.0f), 3);
        gp->SetBmpRGB(L"GleeIdle", 151, 151, 151);

        //Glee normal
        Texture* Gleetouch = JSHResourcemng::Load<Texture>(L"GleeTouch"
            , L"..\\Resource\\Ingame\\Glee_Club\\Glee_normal.bmp");
        gp->CreateAnimation(L"GleeTouch", Gleetouch, vector2(0.0f, 0.0f), vector2(47.0f, 73.0f), 2);
        gp->SetBmpRGB(L"GleeTouch", 151, 151, 151);

        //Glee Close Mouth
        Texture* Gleeclose = JSHResourcemng::Load<Texture>(L"GleeClose"
            , L"..\\Resource\\Ingame\\Glee_Club\\Glee_Close.bmp");
        gp->CreateAnimation(L"GleeClose", Gleeclose, vector2(0.0f, 0.0f), vector2(48.0f, 72.0f), 3, vector2(0.0f, 0.0f), 0.05f);
        gp->SetBmpRGB(L"GleeClose", 151, 151, 151);

        //Glee Open Mouth
        gp->CreateAnimationFolder(L"GleeOpen"
            , L"..\\Resource\\Ingame\\Glee_Club\\Glee_Open", vector2(0.0f, 0.0f), 0.05f);
        gp->SetBmpRGB(L"GleeOpen", 151, 151, 151);
        
        //Glee AH
        JSHResourcemng::Load<Sound>(L"Glee_AH_S", L"..\\Resource\\sound\\Glee_Club\\Glee_AH.wav");
        Texture* GleeAH = JSHResourcemng::Load<Texture>(L"GleeAH"
            , L"..\\Resource\\Ingame\\Glee_Club\\Glee_AH.bmp");
        gp->CreateAnimation(L"GleeAH", GleeAH, vector2(0.0f, 0.0f), vector2(52.5f, 82.0f), 8);
        gp->SetBmpRGB(L"GleeAH", 151, 151, 151);

        gp->PlayAnimation(L"GleeIdle", true);
    }
    void GleePlayer::Update()
    {
        GameObject::Update();

        switch (mState)
        {
        case JSH::GleePlayer::eState::Idle:
            Idle();
            break;
        case JSH::GleePlayer::eState::Closing:
            Closing();
            break;
        case JSH::GleePlayer::eState::Opening:
            Opening();
            break;
        case JSH::GleePlayer::eState::Touch:
            Touch();
            break;
        case JSH::GleePlayer::eState::AH:
            AH();
            break;
        case JSH::GleePlayer::eState::End:
            break;
        default:
            break;  
        }
    }
    void GleePlayer::Render(HDC hdc)
    {
        GameObject::Render(hdc);
    }

    void GleePlayer::Idle()
    {
        Animationmng* animationmng = GetComponent<Animationmng>();
        Sound* sound = JSHResourcemng::Find<Sound>(L"Glee_KeyUp_S");

        if (input::GetKeyDown(eKeyCode::Lbutton))
        {
            sound->Stop(false);
            animationmng->PlayAnimation(L"GleeClose", false);
            mState = eState::Closing;
        } 
    }
    void GleePlayer::Closing()
    {
        Animationmng* animationmng = GetComponent<Animationmng>();

        if (input::GetKeyUp(eKeyCode::Lbutton))
        {
            animationmng->PlayAnimation(L"GleeIdle", true);
            mState = eState::Idle;
        }

        if (animationmng->IsActiveAnimationComplete() == true)
        {
            animationmng->PlayAnimation(L"GleeTouch", true);
            mState = eState::Touch;
        }
    }
    void GleePlayer::Opening()
    {
        Animationmng* animationmng = GetComponent<Animationmng>();
        Sound* sound = JSHResourcemng::Find<Sound>(L"Glee_Idle_S");

        if (animationmng->IsActiveAnimationComplete() == true)
        {
            animationmng->PlayAnimation(L"GleeIdle", true);
            mState = eState::Idle;
        }

        if (input::GetKeyDown(eKeyCode::Lbutton))
        {
            animationmng->PlayAnimation(L"GleeClose", false);
            mState = eState::Closing;
        }
    }
    void GleePlayer::Touch()
    {
        Animationmng* animationmng = GetComponent<Animationmng>();
        
        if (input::GetKeyUp(eKeyCode::Lbutton))
        {
            animationmng->PlayAnimation(L"GleeOpen", false);
            mState = eState::Opening;
        }
    }
    void GleePlayer::AH()
    {
        Sound* sound = JSHResourcemng::Find<Sound>(L"Glee_AH_S");
        Animationmng* animationmng = GetComponent<Animationmng>();

        if (animationmng->IsActiveAnimationComplete() == true)
        {
            animationmng->PlayAnimation(L"GleeIdle", true);
            mState = eState::Idle;
        }
    }
}