#include "BlueBirds.h"
#include "SpriteRenderer.h"
#include "Object.h"
#include "JSHinput.h"
#include "Texture.h"
#include "JSHResourcemng.h"
#include "BackGround.h"
#include "Transform.h"
#include "Time.h"
#include "Sound.h"
#include "BBNPC.h"
#include "BBPlayer.h"
#include "BBCaptain.h"
#include "BBTouchScreen.h"
#include "Collider.h"
#include "BBMemories.h"

namespace JSH
{
    float BlueBirds::mScore = 0.0f;
    float BlueBirds::mPlayTime = 0.0f;

    BlueBirds::BlueBirds()
        : mTouchScreen{ nullptr }
    {
    }
    BlueBirds::~BlueBirds()
    {
    }
    void BlueBirds::Initialize()
    {
        //BlueBirds Main BGM
        JSHResourcemng::Load<Sound>(L"BBMain_S", L"..\\Resource\\sound\\Blue_Birds\\BlueBirds.wav");

        //BlueBirds BackGround
        Texture* texture1 = JSHResourcemng::Load<Texture>(L"BlueBirdsBG"
            , L"..\\Resource\\Ingame\\Blue_Bird\\Blue_Birds_BG.bmp");
        BackGround* bb = object::Instantiate<BackGround>(eLayerType::BackGround);
        SpriteRenderer* bbsr = bb->AddComponent<SpriteRenderer>();
        Transform* bbtr = bb->GetComponent<Transform>();
        bbtr->SetPosition(vector2(192.0f, 288.0f));
        bbsr->SetTexture(texture1);
        bbsr->SetScale(vector2(2.0f, 2.25f));

        //BlueBirds TouchScreen
        //Texture* texture2 = JSHResourcemng::Load<Texture>(L"BlueBirdsTouchScreen"
        //    , L"..\\Resource\\Ingame\\Blue_Bird\\TouchScreen.bmp");
        //BackGround* bt = object::Instantiate<BackGround>(eLayerType::TouchScreen);
        //SpriteRenderer* btsr = bt->AddComponent<SpriteRenderer>();
        //Transform* bttr = bt->GetComponent<Transform>();
        //bttr->SetPosition(vector2(576.0f, 288.0f));
        //btsr->SetTexture(texture2);
        //btsr->SetScale(vector2(2.0f, 2.25f));

        //Touch Screen Collider
        mTouchScreen = object::Instantiate<BBTouchScreen>(eLayerType::TouchScreen);
        Collider* Tcol = mTouchScreen->AddComponent<Collider>();
        Tcol->SetSize(vector2(2.0f, 2.5f));

        //BlueBirds Memories
        BBMemories* bm = object::Instantiate<BBMemories>(eLayerType::Ingame);
        Transform* bmtr = bm->GetComponent<Transform>();
        bmtr->SetPosition(vector2(192.0f, 136.0f));
        
        //BlueBirds Captain
        BBCaptain* bc = object::Instantiate<BBCaptain>(eLayerType::BackGroundObject);

        //BlueBirds NPC1
        BBNPC* bn1 = object::Instantiate<BBNPC>(eLayerType::NPC1);
        Transform* bn1tr = bn1->GetComponent<Transform>();
        bn1tr->SetPosition(vector2(150.0f, 420.0f));

        //BlueBirds NPC2
        BBNPC* bn2 = object::Instantiate<BBNPC>(eLayerType::NPC2);
        Transform* bn2tr = bn2->GetComponent<Transform>();
        bn2tr->SetPosition(vector2(240.0f, 420.0f));

        //BlueBirds YOU
        Texture* You = JSHResourcemng::Load<Texture>(L"You"
            , L"..\\Resource\\Ingame\\_You.bmp");
        BackGround* you = object::Instantiate<BackGround>(eLayerType::UI);
        SpriteRenderer* yousr = you->AddComponent<SpriteRenderer>();
        Transform* youtr = you->GetComponent<Transform>();
        youtr->SetPosition(vector2(330.0f, 540.0f));
        yousr->SetTexture(You);
        yousr->SetScale(vector2(2.0f, 2.0f));
        yousr->SetBmpRGB(136, 0, 21);

        //BlueBirds Player
        BBPlayer* bp = object::Instantiate<BBPlayer>(eLayerType::Player);
        Transform* bptr = bp->GetComponent<Transform>();
        bptr->SetPosition(vector2(330.0f, 420.0f));
    }
    void BlueBirds::Update()
    {
        Sound* sound = JSHResourcemng::Find<Sound>(L"BBMain_S");
        mPlayTime += Time::DeltaTime();

        if (input::GetKeyDown(eKeyCode::Rbutton))
        {
            SceneManager::LoadScene(L"SelectScene");
        }
        if (input::GetKeyDown(eKeyCode::R))
        {
            SceneManager::LoadScene(L"BlueBirdsTitle");
        }
        if (input::GetKeyDown(eKeyCode::E))
        {
            SceneManager::LoadScene(L"BlueBirdsEnd");
        }
        if (mPlayTime >= 60.0f)
        {
            SceneManager::LoadScene(L"BlueBirdsEnd");
            mPlayTime = 0.0f;
        }

        Scene::Update();
    }
    void BlueBirds::Render(HDC hdc)
    {
        Scene::Render(hdc);
    }
    void BlueBirds::Enter()
    {
        Sound* sound = JSHResourcemng::Find<Sound>(L"BBMain_S");
        sound->Play(false);
    }
    void BlueBirds::Exit()
    {
        Sound* sound = JSHResourcemng::Find<Sound>(L"BBMain_S");
        sound->Stop(true);
    }
}