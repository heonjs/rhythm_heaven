#include "BBEndImage.h"
#include "Texture.h"
#include "Animationmng.h"
#include "Transform.h"
#include "JSHResourcemng.h"
#include "BlueBirds.h"

namespace JSH
{
    BBEndImage::BBEndImage()
    {
    }
    BBEndImage::~BBEndImage()
    {
    }
    void BBEndImage::Initialize()
    {
        GameObject::Initialize();

        Animationmng* animationmng = AddComponent<Animationmng>();
        animationmng->SetScale(vector2(2.0f, 2.0f));

        //BB Perfect Animation
        Texture* Perfect = JSHResourcemng::Load<Texture>(L"BBPerfect", L"..\\Resource\\Ingame\\Blue_Bird\\BBEnd_Perfect.bmp");
        animationmng->CreateAnimation(L"BBPerfect", Perfect, vector2::Zero, vector2(128.0f, 80.0f), 1);

        //BB OK Animation
        Texture* OK = JSHResourcemng::Load<Texture>(L"BBOK", L"..\\Resource\\Ingame\\Blue_Bird\\BBEnd_OK.bmp");
        animationmng->CreateAnimation(L"BBOK", OK, vector2::Zero, vector2(128.0f, 80.0f), 1);

        //BB Bad Animation
        Texture* Bad = JSHResourcemng::Load<Texture>(L"BBBad", L"..\\Resource\\Ingame\\Blue_Bird\\BBEnd_Bad.bmp");
        animationmng->CreateAnimation(L"BBBad", Bad, vector2::Zero, vector2(128.0f, 80.0f), 1);
    }
    void BBEndImage::Update()
    {
        GameObject::Update();

        Animationmng* animationmng = GetComponent<Animationmng>();

        if (BlueBirds::GetScore() >= 100.0f)
        {
            animationmng->PlayAnimation(L"BBPerfect");
        }
        else if (BlueBirds::GetScore() < 100.0f and BlueBirds::GetScore() >= 30.0f)
        {
            animationmng->PlayAnimation(L"BBOK");
        }
        else if (BlueBirds::GetScore() < 30.0f)
        {
            animationmng->PlayAnimation(L"BBBad");
        }
    }
    void BBEndImage::Render(HDC hdc)
    {
        GameObject::Render(hdc);
    }
}