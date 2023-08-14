#include "BlueBirdsTitle.h"
#include "SpriteRenderer.h"
#include "Object.h"
#include "JSHinput.h"
#include "Texture.h"
#include "JSHResourcemng.h"
#include "BackGround.h"
#include "Transform.h"
#include "Time.h"
#include "Sound.h"
#include "Animationmng.h"

namespace JSH
{
    BlueBirdsTitle::BlueBirdsTitle()
        : mBackGround{ nullptr }
    {
    }
    BlueBirdsTitle::~BlueBirdsTitle()
    {
    }
    void BlueBirdsTitle::Initialize()
    {
        //BlueBirds Title BGM
        JSHResourcemng::Load<Sound>(L"BBTitle_S", L"..\\Resource\\sound\\Blue_Birds\\Title_BlueBirds.wav");

        // Blue Birds Title
        Texture* texture1 = JSHResourcemng::Load<Texture>(L"BlueBirds_TitleBG"
            , L"..\\Resource\\Ingame\\Loading.bmp");
        BackGround* bb = object::Instantiate<BackGround>(eLayerType::BackGround);
        SpriteRenderer* bbsr = bb->AddComponent<SpriteRenderer>();
        Transform* bbtr = bb->GetComponent<Transform>();
        bbtr->SetPosition(vector2(192.0f, 288.0f));
        bbsr->SetTexture(texture1);
        bbsr->SetScale(vector2(2.0f, 2.25f));

        // Blue Birds Title Loading
        Texture* texture2 = JSHResourcemng::Load<Texture>(L"BlueBirds_TouchScreen"
            , L"..\\Resource\\Ingame\\Loading.bmp");
        BackGround* bt = object::Instantiate<BackGround>(eLayerType::TouchScreen);
        SpriteRenderer* btsr = bt->AddComponent<SpriteRenderer>();
        Transform* bttr = bt->GetComponent<Transform>();
        bttr->SetPosition(vector2(576.0f, 288.0f));
        btsr->SetTexture(texture2);
        btsr->SetScale(vector2(2.0f, 2.25f));

        // BlueBirds TopLine
        Texture* line1 = JSHResourcemng::Load<Texture>(L"TopLine"
            , L"..\\Resource\\Ingame\\Blue_Bird\\BBT_TopLine.bmp");
        BackGround* tl = object::Instantiate<BackGround>(eLayerType::BackGroundObject);
        SpriteRenderer* tlsr = tl->AddComponent<SpriteRenderer>();
        Transform* tltr = tl->GetComponent<Transform>();
        tltr->SetPosition(vector2(192.0f, 100.0f));
        tlsr->SetTexture(line1);
        tlsr->SetScale(vector2(2.0f, 2.0f));
        tlsr->SetBmpRGB(227, 178, 255);

        // BlueBirds BottomLine
        Texture* line2 = JSHResourcemng::Load<Texture>(L"BottomLine"
            , L"..\\Resource\\Ingame\\Blue_Bird\\BBT_BottomLine.bmp");
        BackGround* bl = object::Instantiate<BackGround>(eLayerType::BackGroundObject);
        SpriteRenderer* blsr = bl->AddComponent<SpriteRenderer>();
        Transform* bltr = bl->GetComponent<Transform>();
        bltr->SetPosition(vector2(192.0f, 500.0f));
        blsr->SetTexture(line2);
        blsr->SetScale(vector2(2.0f, 2.0f));
        blsr->SetBmpRGB(227, 178, 255);

        //BlueBirds Title Animation
        mBackGround = object::Instantiate<BackGround>(eLayerType::BackGroundObject);
        Transform* batr = mBackGround->GetComponent<Transform>();
        Animationmng* baA = mBackGround->AddComponent<Animationmng>();
        baA->CreateAnimationFolder(L"BB_Title_A", L"..\\Resource\\Ingame\\Blue_Bird\\BB_Title");
        baA->SetScale(vector2(2.0f, 2.0f));
        baA->SetBmpRGB(L"BB_Title_A", 224, 248, 207);
        batr->SetPosition(vector2(192.0f, 240.0f));
    }
    void BlueBirdsTitle::Update()
    {
        static float mTime = 0.0f;
        mTime += Time::DeltaTime();
        if (mTime >= 3.5f)
        {
            mTime = 0.0f;
            SceneManager::LoadScene(L"BlueBirds");
        }

        Scene::Update();
    }
    void BlueBirdsTitle::Render(HDC hdc)
    {
        Scene::Render(hdc);
    }
    void BlueBirdsTitle::Enter()
    {
        Animationmng* animationmng = mBackGround->GetComponent<Animationmng>();
        animationmng->PlayAnimation(L"BB_Title_A", false);
        Sound* sound = JSHResourcemng::Find<Sound>(L"BBTitle_S");
        sound->Play(false);
    }
    void BlueBirdsTitle::Exit()
    {
        Sound* sound = JSHResourcemng::Find<Sound>(L"BBTitle_S");
        sound->Stop(true);
    }
}