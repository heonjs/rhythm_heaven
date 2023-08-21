#include "MoaiExplain.h"
#include "Animationmng.h"
#include "JSHResourcemng.h"
#include "Texture.h"
#include "Object.h"
#include "Transform.h"

namespace JSH
{
    MoaiExplain::MoaiExplain()
        : mTrigger(false)
    {
    }
    MoaiExplain::~MoaiExplain()
    {
    }
    void MoaiExplain::Initialize()
    {
        GameObject::Initialize();
        
        Animationmng* animationmng = AddComponent<Animationmng>();

        //Moai Explain
        Texture* MoaiEx = JSHResourcemng::Load<Texture>(L"Moai_Ex", L"..\\Resource\\Ingame\\Moai\\Moai_Ex.bmp");
        animationmng->CreateAnimation(L"MoaiEx", MoaiEx, vector2::Zero, vector2(200.0f, 150.0f), 1);
        animationmng->SetScale(vector2(1.2f, 1.2f));

        animationmng->PlayAnimation(L"MoaiEx");
    }
    void MoaiExplain::Update()
    {
        GameObject::Update();
    }
    void MoaiExplain::Render(HDC hdc)
    {
        if (mTrigger == true)
        {
            GameObject::Render(hdc);
        }     
    }
}