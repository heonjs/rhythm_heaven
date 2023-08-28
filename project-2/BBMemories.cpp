#include "BBMemories.h"
#include "Object.h"
#include "Texture.h"
#include "Animationmng.h"
#include "Transform.h"
#include "Time.h"

namespace JSH
{
    BBMemories::BBMemories()
        : mSwitch(false)
        , mTime(0.0f)
    {
    }
    BBMemories::~BBMemories()
    {
    }
    void BBMemories::Initialize()
    {
        GameObject::Initialize();

        Animationmng* animationmng = AddComponent<Animationmng>();
        animationmng->SetScale(vector2(2.0f, 2.0f));

        animationmng->CreateAnimationFolder(L"BB_Memories", L"..\\Resource\\Ingame\\Blue_Bird\\BBMemories", vector2::Zero, 5.2f);
    }
    void BBMemories::Update()
    {
        GameObject::Update();
        Animationmng* animationmng = GetComponent<Animationmng>();

        mTime += Time::DeltaTime();

        if (mTime >= 25.0f and mSwitch == false)
        {
            animationmng->PlayAnimation(L"BB_Memories");
            mSwitch = true;
        }
        if (mTime >= 60.0f)
        {
            mTime = 0.0f;
        }
    }
    void BBMemories::Render(HDC hdc)
    {
        GameObject::Render(hdc);
    }
}