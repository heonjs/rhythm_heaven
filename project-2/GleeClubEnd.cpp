#include "GleeClubEnd.h"
#include "Object.h"
#include "JSHinput.h"
#include "Texture.h"
#include "JSHResourcemng.h"
#include "BackGround.h"
#include "Transform.h"
#include "Time.h"
#include "Sound.h"
#include "Animationmng.h"
#include "SpriteRenderer.h"
#include "GleeClub.h"
#include "GleeEndImage.h"

namespace JSH
{
    GleeClubEnd::GleeClubEnd()
        : mGleeEnd{ nullptr }
    {
    }
    GleeClubEnd::~GleeClubEnd()
    {
    }
    void GleeClubEnd::Initialize()
    {
        //Perfect BGM
        JSHResourcemng::Load<Sound>(L"GleePerfect_S", L"..\\Resource\\sound\\Perfect.wav");

        //OK BGM
        JSHResourcemng::Load<Sound>(L"GleeOK_S", L"..\\Resource\\sound\\OK.wav");

        //Bad BGM
        JSHResourcemng::Load<Sound>(L"GleeBad_S", L"..\\Resource\\sound\\Bad.wav");

        //GleeClub Ending BackGround
        Texture* EndingBG = JSHResourcemng::Load<Texture>(L"EndingBG", L"..\\Resource\\Ingame\\Loading.bmp");
        BackGround* edbg = object::Instantiate<BackGround>(eLayerType::BackGround);
        SpriteRenderer* edsr = edbg->AddComponent<SpriteRenderer>();
        Transform* edtr = edbg->GetComponent<Transform>();
        edtr->SetPosition(vector2(192.0f, 288.0f));
        edsr->SetTexture(EndingBG);
        edsr->SetScale(vector2(2.0f, 2.25f));

        //GleeClub Ending TouchScreen
        BackGround* edtc = object::Instantiate<BackGround>(eLayerType::TouchScreen);
        SpriteRenderer* edtcsr = edtc->AddComponent<SpriteRenderer>();
        Transform* edtctr = edtc->GetComponent<Transform>();
        edtctr->SetPosition(vector2(576.0f, 288.0f));
        edtcsr->SetTexture(EndingBG);
        edtcsr->SetScale(vector2(2.0f, 2.25f));

        GleeEndImage* glee = object::Instantiate<GleeEndImage>(eLayerType::BackGroundObject);
        Transform* gleetr = glee->GetComponent<Transform>();
        gleetr->SetPosition(vector2(192.0f, 288.0f));
    }
    void GleeClubEnd::Update()
    {
        if (input::GetKeyDown(eKeyCode::Lbutton))
        {
            SceneManager::LoadScene(L"SelectScene");
        }

        Scene::Update();
    }
    void GleeClubEnd::Render(HDC hdc)
    {
        Scene::Render(hdc);
    }
    void GleeClubEnd::Enter()
    {
        //Find BGM
        Sound* sound1 = JSHResourcemng::Find<Sound>(L"GleePerfect_S");
        Sound* sound2 = JSHResourcemng::Find<Sound>(L"GleeOK_S");
        Sound* sound3 = JSHResourcemng::Find<Sound>(L"GleeBad_S");

        if (GleeClub::GetScore() >= 100.0f)
        {
            sound1->Play(false);
            
        }
        else if (GleeClub::GetScore() < 100.0f and GleeClub::GetScore() >= 30.0f)
        {
            sound2->Play(false);
        }
        else if (GleeClub::GetScore() < 30.0f)
        {
            sound3->Play(false);
        }
    }
    void GleeClubEnd::Exit()
    {
        Sound* sound1 = JSHResourcemng::Find<Sound>(L"GleePerfect_S");
        Sound* sound2 = JSHResourcemng::Find<Sound>(L"GleeOK_S");
        Sound* sound3 = JSHResourcemng::Find<Sound>(L"GleeBad_S");

        sound1->Stop(true);
        sound2->Stop(true);
        sound3->Stop(true);
    }
}