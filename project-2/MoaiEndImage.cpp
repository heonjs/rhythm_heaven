#include "MoaiEndImage.h"
#include "Texture.h"
#include "Animationmng.h"
#include "Transform.h"
#include "JSHResourcemng.h"
#include "Moai.h"
#include "MoaiPlayer.h"

namespace JSH
{
    MoaiEndImage::MoaiEndImage()
    {
    }
    MoaiEndImage::~MoaiEndImage()
    {
    }
    void MoaiEndImage::Initialize()
    {
        GameObject::Initialize();

        Animationmng* animationmng = AddComponent<Animationmng>();
        animationmng->SetScale(vector2(2.0f, 2.0f));

        //Moai Perfect Animation
        Texture* Perfect = JSHResourcemng::Load<Texture>(L"MoaiPerfect", L"..\\Resource\\Ingame\\Moai\\Moai_End_Perfect.bmp");
        animationmng->CreateAnimation(L"MoaiPerfect", Perfect, vector2::Zero, vector2(128.0f, 80.0f), 1);

        //Moai OK Animation
        Texture* OK = JSHResourcemng::Load<Texture>(L"MoaiOK", L"..\\Resource\\Ingame\\Moai\\Moai_End_OK.bmp");
        animationmng->CreateAnimation(L"MoaiOK", OK, vector2::Zero, vector2(128.0f, 80.0f), 1);

        //Moai Bad Animation
        Texture* Bad = JSHResourcemng::Load<Texture>(L"MoaiBad", L"..\\Resource\\Ingame\\Moai\\Moai_End_Bad.bmp");
        animationmng->CreateAnimation(L"MoaiBad", Bad, vector2::Zero, vector2(128.0f, 80.0f), 1);
    }
    void MoaiEndImage::Update()
    {
        GameObject::Update();

        Animationmng* animationmng = GetComponent<Animationmng>();

        if (MoaiPlayer::GetScore() >= 50)
        {
            animationmng->PlayAnimation(L"MoaiPerfect");
        }
        else if (MoaiPlayer::GetScore() < 50 and MoaiPlayer::GetScore() >= 20)
        {
            animationmng->PlayAnimation(L"MoaiOK");
        }
        else if (MoaiPlayer::GetScore() < 20)
        {
            animationmng->PlayAnimation(L"MoaiBad");
        }
    }
    void MoaiEndImage::Render(HDC hdc)
    {
        GameObject::Render(hdc);
    }
}