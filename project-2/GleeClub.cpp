#include "GleeClub.h"
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
#include "GleePlayer.h"
#include "GleeNPC1.h"
#include "GleeNPC2.h"
#include "Sound.h"

namespace JSH
{
    float GleeClub::mScore = 0.0f;

    GleeClub::GleeClub()
        : mSoundPlay(false)
    {
    }
    GleeClub::~GleeClub()
    {
    }
    void GleeClub::Initialize()
    {
        //Glee Club Main BGM
        JSHResourcemng::Load<Sound>(L"GleeMain", L"..\\Resource\\sound\\Glee_Club\\GleeClub.wav");

        //Glee BackGround
        Texture* texture1 = JSHResourcemng::Load<Texture>(L"Glee Game"
            , L"..\\Resource\\Ingame\\Glee_Club\\Glee_Club_bg.bmp");
        BackGround* dj1 = object::Instantiate<BackGround>(eLayerType::Ingame);
        SpriteRenderer* dj1sr = dj1->AddComponent<SpriteRenderer>();
        Transform* dj1tr = dj1->GetComponent<Transform>();
        dj1tr->SetPosition(vector2(192.0f, 288.0f));
        dj1sr->SetTexture(texture1);
        dj1sr->SetScale(vector2(2.0f, 2.25f));

        //Glee TouchScreen
        Texture* texture2 = JSHResourcemng::Load<Texture>(L"Glee Touch"
            , L"..\\Resource\\Ingame\\Glee_Club\\Glee_Touch.bmp");
        BackGround* dj2 = object::Instantiate<BackGround>(eLayerType::TouchScreen);
        SpriteRenderer* dj2sr = dj2->AddComponent<SpriteRenderer>();
        Transform* dj2tr = dj2->GetComponent<Transform>();
        dj2tr->SetPosition(vector2(576.0f, 288.0f));
        dj2sr->SetTexture(texture2);
        dj2sr->SetScale(vector2(2.0f, 2.25f));

        //Teacher
        Texture* teacher = JSHResourcemng::Load<Texture>(L"Teacher"
            , L"..\\Resource\\Ingame\\Glee_Club\\Glee_Teacher.bmp");
        BackGround* tc = object::Instantiate<BackGround>(eLayerType::NPC1);
        Animationmng* tcA = tc->AddComponent<Animationmng>();
        Transform* tctr = tc->GetComponent<Transform>();
        tcA->CreateAnimation(L"Teacher", teacher, vector2(0.0f, 0.0f), vector2(72.0f, 98.0f), 3);
        tctr->SetPosition(vector2(100.0f, 450.0f));
        tcA->SetBmpRGB(L"Teacher", 151, 151, 151);
        tcA->SetScale(vector2(2.0f, 2.0f));
        tcA->PlayAnimation(L"Teacher", true);

        //Glee NPC1
        GleeNPC1* gn1 = object::Instantiate<GleeNPC1>(eLayerType::NPC1);
        Transform* gn1tr = gn1->GetComponent<Transform>();
        gn1tr->SetPosition(vector2(140.0f, 240.0f));

        //Glee NPC2
        GleeNPC2* gn2 = object::Instantiate<GleeNPC2>(eLayerType::NPC2);
        Transform* gn2tr = gn2->GetComponent<Transform>();
        gn2tr->SetPosition(vector2(230.0f, 260.0f));

        //Glee YOU
        Texture* You = JSHResourcemng::Load<Texture>(L"You", L"..\\Resource\\Ingame\\_You.bmp");
        BackGround* you = object::Instantiate<BackGround>(eLayerType::UI);
        SpriteRenderer* yousr = you->AddComponent<SpriteRenderer>();
        Transform* youtr = you->GetComponent<Transform>();
        youtr->SetPosition(vector2(320.0f, 380.0f));
        yousr->SetTexture(You);
        yousr->SetScale(vector2(2.0f, 2.0f));
        yousr->SetBmpRGB(136, 0, 21);

        //Glee Player
        GleePlayer* gp = object::Instantiate<GleePlayer>(eLayerType::Player);
        Transform* gptr = gp->GetComponent<Transform>();
        gptr->SetPosition(vector2(320.0f, 280.0f));
    }
    void GleeClub::Update()
    {
        Sound* sound = JSHResourcemng::Find<Sound>(L"GleeMain");

        static float mTime = 0.0f;

        if (mSoundPlay == false)
        {
            mTime += Time::DeltaTime();
        }
        if (mTime >= 1.0f)
        {
            mSoundPlay = true;
            sound->Play(false);
            mTime = 0.0f;
        }

        if (input::GetKeyDown(eKeyCode::Rbutton))
        {
            SceneManager::LoadScene(L"SelectScene");
        }
        if (input::GetKeyDown(eKeyCode::R))
        {
            SceneManager::LoadScene(L"GleeClubTitle");
        }
        if (input::GetKeyDown(eKeyCode::E))
        {
            SceneManager::LoadScene(L"GleeClubEnd");
        }

        Scene::Update();
    }
    void GleeClub::Render(HDC hdc)
    {
        Scene::Render(hdc);
    }
    void GleeClub::Enter()
    {
        mSoundPlay = false;
    }
    void GleeClub::Exit()
    {
        Sound* sound = JSHResourcemng::Find<Sound>(L"GleeMain");
        sound->Stop(true);
    }
}