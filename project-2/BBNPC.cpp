#include "BBNPC.h"
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
    BBNPC::BBNPC()
        : mState(eState::Idle)
    {
    }
    BBNPC::~BBNPC()
    {
    }
    void BBNPC::Initialize()
    {
        GameObject::Initialize();

        Animationmng* animationmng = AddComponent<Animationmng>();
        animationmng->SetScale(vector2(2.0f, 2.0f));

        //BB Idle
        Texture* BN_Idle = JSHResourcemng::Load<Texture>(L"BN_Idle"
            , L"..\\Resource\\Ingame\\Blue_Bird\\BB_Idle.bmp");
        animationmng->CreateAnimation(L"BN_Idle", BN_Idle, vector2(0.0f, 0.0f), vector2(51.0f, 97.0f), 4, vector2::Zero, 0.11f);
        animationmng->SetBmpRGB(L"BN_Idle", 227, 178, 255);

        animationmng->PlayAnimation(L"BN_Idle", true);
    }
    void BBNPC::Update()
    {
        switch (mState)
        {
        case JSH::BBNPC::eState::Idle:
            Idle();
            break;
        case JSH::BBNPC::eState::Hit:
            Hit();
            break;
        case JSH::BBNPC::eState::Squat:
            Squat();
            break;
        case JSH::BBNPC::eState::Stretch:
            Stretch();
            break;
        case JSH::BBNPC::eState::End:
            break;
        default:
            break;
        }

        GameObject::Update();
    }
    void BBNPC::Render(HDC hdc)
    {
        GameObject::Render(hdc);
    }

    void BBNPC::Idle()
    {
        Animationmng* animationmng = GetComponent<Animationmng>();
    }
    void BBNPC::Hit()
    {
        Animationmng* animationmng = GetComponent<Animationmng>();
    }
    void BBNPC::Squat()
    {
        Animationmng* animationmng = GetComponent<Animationmng>();
    }
    void BBNPC::Stretch()
    {
        Animationmng* animationmng = GetComponent<Animationmng>();
    }
}