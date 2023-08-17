#include "BBCaptain.h"
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
    BBCaptain::BBCaptain()
        :mState(eState::Idle)
    {
    }
    BBCaptain::~BBCaptain()
    {
    }
    void BBCaptain::Initialize()
    {
        GameObject::Initialize();

        Animationmng* animationmng = AddComponent<Animationmng>();
        animationmng->SetScale(vector2(2.0f, 2.0f));

        //Captain Idle
        Texture* Captain_Idle = JSHResourcemng::Load<Texture>(L"Captain_Idle", L"..\\Resource\\Ingame\\Blue_Bird\\Cpt_Normal.bmp");
        animationmng->CreateAnimation(L"Captain_Idle", Captain_Idle, vector2(0.0f, 0.0f), vector2(62.0f, 80.0f), 3, vector2::Zero, 0.15f);
        animationmng->SetBmpRGB(L"Captain_Idle", 227, 178, 255);
        
        //Captain Talk
        Texture* Captain_Talk = JSHResourcemng::Load<Texture>(L"Captain_Talk", L"..\\Resource\\Ingame\\Blue_Bird\\Cpt_Talk.bmp");
        animationmng->CreateAnimation(L"Captain_Talk", Captain_Talk, vector2(0.0f, 0.0f), vector2(62.0f, 80.0f), 2, vector2::Zero, 0.15f);
        animationmng->SetBmpRGB(L"Captain_Talk", 227, 178, 255);

        //Captain Fail
        Texture* Captain_Fail = JSHResourcemng::Load<Texture>(L"Captain_Fail", L"..\\Resource\\Ingame\\Blue_Bird\\Cpt_Fail.bmp");
        animationmng->CreateAnimation(L"Captain_Fail", Captain_Fail, vector2(0.0f, 0.0f), vector2(58.0f, 80.0f), 1);
        animationmng->SetBmpRGB(L"Captain_Fail", 227, 178, 255);

    }
    void BBCaptain::Update()
    {
        GameObject::Update();

        static float Cpt_xpos = 30.0f;
        static int mTime = 0.0f;
        mTime += Time::DeltaTime();

        if (mTime >= 10.0f);
        {
            if (Cpt_xpos == -100.0f)
            {
                int a = 0;
            }
            Cpt_xpos -= 1.0f;
        }

        Transform* bctr = GetComponent<Transform>();
        bctr->SetPosition(vector2(Cpt_xpos, 120.0f));

        switch (mState) 
        {
        case JSH::BBCaptain::eState::Idle:
            Idle();
            break;
        case JSH::BBCaptain::eState::Talk:
            Talk();
            break;
        case JSH::BBCaptain::eState::Fail:
            Fail();
            break;
        case JSH::BBCaptain::eState::End:
            break;
        default:
            break;
        }
    }
    void BBCaptain::Render(HDC hdc)
    {
        GameObject::Render(hdc);
    }
    void BBCaptain::Idle()
    {
        Animationmng* animationmng = GetComponent<Animationmng>();
        animationmng->FindAnimation(L"Captain_Idle");

        animationmng->PlayAnimation(L"Captain_Idle", true);
    }
    void BBCaptain::Talk()
    {
        Animationmng* animationmng = GetComponent<Animationmng>();
        animationmng->FindAnimation(L"Captain_Talk");

        animationmng->PlayAnimation(L"Captain_Talk", false);

        if (animationmng->IsActiveAnimationComplete() == true)
        {
            mState = eState::Idle;
        }
    }
    void BBCaptain::Fail()
    {
        Animationmng* animationmng = GetComponent<Animationmng>();
        animationmng->FindAnimation(L"Captain_Fail");

        animationmng->PlayAnimation(L"Captain_Fail", true);
    }
    void BBCaptain::CptPlay()
    {

    }
}