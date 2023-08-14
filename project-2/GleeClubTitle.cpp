#include "GleeClubTitle.h"
#include "SpriteRenderer.h"
#include "Object.h"
#include "JSHinput.h"
#include "Texture.h"
#include "JSHResourcemng.h"
#include "BackGround.h"
#include "Transform.h"
#include "Time.h"
#include "Sound.h"

namespace JSH
{
    GleeClubTitle::GleeClubTitle()
    {
    }
    GleeClubTitle::~GleeClubTitle()
    {
    }
    void GleeClubTitle::Initialize()
    {
        //Glee Title BackGround
        Texture* texture1 = JSHResourcemng::Load<Texture>(L"LeftGlee"
            , L"..\\Resource\\Ingame\\Glee_Club\\BG_Glee_Club.bmp");
        
        BackGround* gb1 = object::Instantiate<BackGround>(eLayerType::Ingame);
        SpriteRenderer* gb1sr = gb1->AddComponent<SpriteRenderer>();
        Transform* gb1tr = gb1->GetComponent<Transform>();
        gb1tr->SetPosition(vector2(192.0f, 288.0f));
        gb1sr->SetTexture(texture1);
        gb1sr->SetScale(vector2(2.0f, 2.25f));

        //Glee Title
        Texture* title = JSHResourcemng::Load<Texture>(L"GleeTitle"
            , L"..\\Resource\\Ingame\\Glee_Club\\Glee_Club_Title.bmp");

        BackGround* gt = object::Instantiate<BackGround>(eLayerType::Ingame);
        SpriteRenderer* gtsr = gt->AddComponent<SpriteRenderer>();
        Transform* gttr = gt->GetComponent<Transform>();
        gttr->SetPosition(vector2(192.0f, 288.0f));
        gtsr->SetBmpRGB(151, 151, 151);
        gtsr->SetTexture(title);
        gtsr->SetScale(vector2(2.0f, 2.25f));


        //Glee Loading
        Texture* texture2 = JSHResourcemng::Load<Texture>(L"RightGlee"
            , L"..\\Resource\\Ingame\\Loading.bmp");

        BackGround* dj2 = object::Instantiate<BackGround>(eLayerType::TouchScreen);
        SpriteRenderer* dj2sr = dj2->AddComponent<SpriteRenderer>();
        Transform* dj2tr = dj2->GetComponent<Transform>();
        dj2tr->SetPosition(vector2(576.0f, 288.0f));
        dj2sr->SetTexture(texture2);
        dj2sr->SetScale(vector2(2.0f, 2.25f));

        //Glee Title BGM
        JSHResourcemng::Load<Sound>(L"GleeTitleBGM", L"..\\Resource\\sound\\Glee_Club\\Title_GleeClub.wav");
    }
    void GleeClubTitle::Update()
    {
        static float mTime = 0.0f;
        mTime += Time::DeltaTime();
        if (mTime >= 3.0f)
        {
            mTime = 0.0f;
            SceneManager::LoadScene(L"GleeClub");
        }

        Scene::Update();
    }
    void GleeClubTitle::Render(HDC hdc)
    {
        Scene::Render(hdc);
    }
    void GleeClubTitle::Enter()
    {
        Sound* sound = JSHResourcemng::Find<Sound>(L"GleeTitleBGM");
        sound->Play(false);
    }
    void GleeClubTitle::Exit()
    {
    }
}