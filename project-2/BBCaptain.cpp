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
        Texture* Captain_Idle = JSHResourcemng::Load<Texture>(L"Captain_Idle"
            , L"..\\Resource\\Ingame\\Blue_Bird\\Cpt_Normal.bmp");
        animationmng->CreateAnimation(L"Captain_Idle", Captain_Idle, vector2(0.0f, 0.0f), vector2(62.0f, 78.0f), 3, vector2::Zero, 0.15f);
        animationmng->SetBmpRGB(L"Captain_Idle", 227, 178, 255);

        //Captain Talk
        Texture* Captain_Talk = JSHResourcemng::Load<Texture>(L"Captain_Talk"
            , L"..\\Resource\\Ingame\\Blue_Bird\\Cpt_Talk.bmp");
        JSHResourcemng::Load<Sound>(L"Peck_a_Beak", L"..\\Resource\\sound\\Blue_Birds\\SE_BIRD_TUTUITE.wav");
        animationmng->CreateAnimation(L"Captain_Talk", Captain_Talk, vector2(0.0f, 0.0f), vector2(62.0f, 78.0f), 2, vector2::Zero, 0.15f);
        animationmng->SetBmpRGB(L"Captain_Talk", 227, 178, 255);

        animationmng->PlayAnimation(L"Captain_Idle", true);
    }
    void BBCaptain::Update()
    {
        GameObject::Update();
    }
    void BBCaptain::Render(HDC hdc)
    {
        GameObject::Render(hdc);
    }
}