#include "Moai.h"
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
#include "MoaiPlayer.h"
#include "MoaiNPC.h"
#include "Sound.h"
#include "GameObject.h"

namespace JSH
{
    float Moai::mPlayTime = 0.0f;
    float Moai::mScore = 0.0f;

    Moai::Moai()
        : SoundPlay(false)
    {
    }
    Moai::~Moai()
    {
    }
    void Moai::Initialize()
    {
        //Moai Main BGM
        JSHResourcemng::Load<Sound>(L"MoaiMain", L"..\\Resource\\sound\\Moai_Doo-Wop\\Moai_Doo-Wop.wav");

        // Moai BackGround
        Texture* texture1 = JSHResourcemng::Load<Texture>(L"MoaiBackGround"
            , L"..\\Resource\\Ingame\\Moai\\Moai_BG.bmp");

        BackGround* mbg = object::Instantiate<BackGround>(eLayerType::BackGround);
        SpriteRenderer* mbgsr = mbg->AddComponent<SpriteRenderer>();
        Transform* mbgtr = mbg->GetComponent<Transform>();
        mbgtr->SetPosition(vector2(192.0f, 288.0f));
        mbgsr->SetTexture(texture1);
        mbgsr->SetScale(vector2(2.0f, 2.25f));

        // Moai TouchScreen
        Texture* texture2 = JSHResourcemng::Load<Texture>(L"MoaiTouchScreen"
            , L"..\\Resource\\Ingame\\Moai\\Moai_TouchScreen.bmp");

        BackGround* mt2 = object::Instantiate<BackGround>(eLayerType::TouchScreen);
        SpriteRenderer* mt2sr = mt2->AddComponent<SpriteRenderer>();
        Transform* mt2tr = mt2->GetComponent<Transform>();
        mt2tr->SetPosition(vector2(576.0f, 288.0f));
        mt2sr->SetTexture(texture2);
        mt2sr->SetScale(vector2(2.0f, 2.25f));

        // Moai Ground
        Texture* texture3 = JSHResourcemng::Load<Texture>(L"MoaiGround"
            , L"..\\Resource\\Ingame\\Moai\\Moai_Ground.bmp");

        BackGround* mg = object::Instantiate<BackGround>(eLayerType::BackGroundObject);
        SpriteRenderer* mgsr = mg->AddComponent<SpriteRenderer>();
        Transform* mgtr = mg->GetComponent<Transform>();
        mgtr->SetPosition(vector2(192.0f, 415.0f));
        mgsr->SetTexture(texture3);
        mgsr->SetBmpRGB(255, 0, 255);
        mgsr->SetScale(vector2(2.0f, 2.0f));

        // Moai Front Ground
        Texture* texture4 = JSHResourcemng::Load<Texture>(L"MoaiFrontGround"
            , L"..\\Resource\\Ingame\\Moai\\Moai_FrontGround.bmp");
        BackGround* mfg = object::Instantiate<BackGround>(eLayerType::FrontObject);
        SpriteRenderer* mfgsr = mfg->AddComponent<SpriteRenderer>();
        Transform* mfgtr = mfg->GetComponent<Transform>();
        mfgtr->SetPosition(vector2(192.0f, 498.0f));
        mfgsr->SetTexture(texture4);
        mfgsr->SetBmpRGB(255, 0, 255);
        mfgsr->SetScale(vector2(2.0f, 2.0f));

        // Bird
        Texture* Bird = JSHResourcemng::Load<Texture>(L"Bird"
            , L"..\\Resource\\Ingame\\Moai\\Bird.bmp");
        BackGround* bird = object::Instantiate<BackGround>(eLayerType::UI);
        Animationmng* birdA = bird->AddComponent<Animationmng>();
        Transform* birdtr = bird->GetComponent<Transform>();
        birdA->CreateAnimation(L"Bird", Bird, vector2::Zero, vector2(57.0f, 39.0f), 3, vector2::Zero, 0.12f);
        birdA->SetBmpRGB(L"Bird", 255, 0, 255);
        birdA->SetScale(vector2(2.0f, 2.0f));
        birdtr->SetPosition(vector2(320.0f, 500.0f));
        birdA->PlayAnimation(L"Bird", true);

        // Bird Shadow
        Texture* BirdShadow = JSHResourcemng::Load<Texture>(L"BirdShadow"
            , L"..\\Resource\\Ingame\\Moai\\Bird_Shadow.bmp");
        BackGround* birds = object::Instantiate<BackGround>(eLayerType::Effect);
        SpriteRenderer* birdssr = birds->AddComponent<SpriteRenderer>();
        Transform* birdstr = birds->GetComponent<Transform>();
        birdssr->SetBmpRGB(255, 0, 255);
        birdssr->SetScale(vector2(2.0f, 2.0f));
        birdssr->SetTexture(BirdShadow);
        birdstr->SetPosition(vector2(320.0f, 540.0f));

        //Moai NPC
        MoaiNPC* mn = object::Instantiate<MoaiNPC>(eLayerType::NPC1);
        Transform* mntr = mn->GetComponent<Transform>();
        mntr->SetPosition(vector2(85.0f, 380.0f));

        //Moai YOU
        Texture* You = JSHResourcemng::Load<Texture>(L"You"
            , L"..\\Resource\\Ingame\\_You.bmp");
        BackGround* you = object::Instantiate<BackGround>(eLayerType::UI);
        SpriteRenderer* yousr = you->AddComponent<SpriteRenderer>();
        Transform* youtr = you->GetComponent<Transform>();
        youtr->SetPosition(vector2(320.0f, 230.0f));
        yousr->SetTexture(You);
        yousr->SetScale(vector2(2.0f, 2.0f));
        yousr->SetBmpRGB(136, 0, 21);

        //Moai Player
        MoaiPlayer* mp = object::Instantiate<MoaiPlayer>(eLayerType::Player);
        Transform* mptr = mp->GetComponent<Transform>();
        mptr->SetPosition(vector2(300.0f, 380.0f));
    }
    void Moai::Update()
    {
        Sound* sound = JSHResourcemng::Find<Sound>(L"MoaiMain");
        static float mTime = 0.0f;
        mPlayTime += Time::DeltaTime();

        if (mPlayTime >= 84.0f)
        {
            // 노래가 끝나면 End Scene으로 이동
            SceneManager::LoadScene(L"MoaiEnd");
            mPlayTime = 0.0f;
        }
        if (SoundPlay == false)
        {          
            mTime += Time::DeltaTime();
        }
        // 사운드재생
        if (mTime >= 1.0f)
        {
            SoundPlay = true;
            sound->Play(false);
            mTime = 0.0f;
        }

        //SelectScene 으로 이동
        if (input::GetKeyDown(eKeyCode::Rbutton))
        {
            SceneManager::LoadScene(L"SelectScene");
        }

        //MoaiTitle 로 이동
        if (input::GetKeyDown(eKeyCode::R))
        {
            SceneManager::LoadScene(L"MoaiTitle");
        }

        //MoaiEnd 로 이동
        if (input::GetKeyDown(eKeyCode::E))
        {
            SceneManager::LoadScene(L"MoaiEnd");
        }

        Scene::Update();
    }
    void Moai::Render(HDC hdc)
    {
        Scene::Render(hdc);
    }
    void Moai::Enter()
    {
        SoundPlay = false;
    }
    void Moai::Exit()
    {
        Sound* sound = JSHResourcemng::Find<Sound>(L"MoaiMain");
        sound->Stop(true);
    }
}