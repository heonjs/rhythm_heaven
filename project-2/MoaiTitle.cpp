#include "MoaiTitle.h"
#include "SpriteRenderer.h"
#include "Object.h"
#include "JSHinput.h"
#include "Texture.h"
#include "JSHResourcemng.h"
#include "BackGround.h"
#include "Transform.h"
#include "Time.h"
#include "Animationmng.h"
#include "Animation.h"
#include "Sound.h"

namespace JSH
{
    MoaiTitle::MoaiTitle()
        : mBackGround{ nullptr }
    {
    }
    MoaiTitle::~MoaiTitle()
    {
    }
    void MoaiTitle::Initialize()
    {
        // Moai Title BackGround
        Texture* texture1 = JSHResourcemng::Load<Texture>(L"Left Moai"
            , L"..\\Resource\\Ingame\\Moai\\MoaiTitle_BG.bmp");

        BackGround* mt1 = object::Instantiate<BackGround>(eLayerType::BackGround);
        SpriteRenderer* mt1sr = mt1->AddComponent<SpriteRenderer>();
        Transform* mt1tr = mt1->GetComponent<Transform>();
        mt1tr->SetPosition(vector2(192.0f, 288.0f));
        mt1sr->SetTexture(texture1);
        mt1sr->SetScale(vector2(2.0f, 2.25f));

        // Moai Loading
        Texture* texture2 = JSHResourcemng::Load<Texture>(L"Right Moai"
            , L"..\\Resource\\Ingame\\Loading.bmp");

        BackGround* mt2 = object::Instantiate<BackGround>(eLayerType::TouchScreen);
        SpriteRenderer* mt2sr = mt2->AddComponent<SpriteRenderer>();
        Transform* mt2tr = mt2->GetComponent<Transform>();
        mt2tr->SetPosition(vector2(576.0f, 288.0f));
        mt2sr->SetTexture(texture2);
        mt2sr->SetScale(vector2(2.0f, 2.25f));

        // Moai Title Animation
        mBackGround = object::Instantiate<BackGround>(eLayerType::BackGroundObject);
        Animationmng* mtA = mBackGround->AddComponent<Animationmng>();
        Transform* mttr = mBackGround->GetComponent<Transform>();
        mtA->CreateAnimationFolder(L"MoaiTitleAnimation", L"..\\Resource\\Ingame\\Moai\\Moai_TitleA");
        mtA->SetBmpRGB(L"MoaiTitleAnimation", 255, 0, 255);
        mtA->SetScale(vector2(2.0f, 2.0f));
        mttr->SetPosition(vector2(192.0f, 380.0f));

        // Moai Title BGM
        JSHResourcemng::Load<Sound>(L"MoaiTitle", L"..\\Resource\\sound\\Moai_Doo-Wop\\Title_Moai_Doo-Wop.wav");
    }
    void MoaiTitle::Update()
    {
        static float mTime = 0.0f;
        mTime += Time::DeltaTime();

        if (mTime >= 3.3f)
        {
            mTime = 0.0f;
            SceneManager::LoadScene(L"Moai");
        }

        Scene::Update();
    }
    void MoaiTitle::Render(HDC hdc)
    {
        Scene::Render(hdc);
    }
    void MoaiTitle::Enter()
    {
        Animationmng* animatnionmng = mBackGround->GetComponent<Animationmng>();
        animatnionmng->PlayAnimation(L"MoaiTitleAnimation", false);

        Sound* sound = JSHResourcemng::Find<Sound>(L"MoaiTitle");
        sound->Play(false);
    }
    void MoaiTitle::Exit()
    {
    }
}