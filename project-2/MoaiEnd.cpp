#include "MoaiEnd.h"
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
#include "Moai.h"
#include "MoaiEndImage.h"
#include "MoaiPlayer.h"

namespace JSH
{
    MoaiEnd::MoaiEnd()
    {
    }
    MoaiEnd::~MoaiEnd()
    {
    }
    void MoaiEnd::Initialize()
    {
        //Perfect BGM
        JSHResourcemng::Load<Sound>(L"MoaiPerfect_S", L"..\\Resource\\sound\\Perfect.wav");

        //OK BGM
        JSHResourcemng::Load<Sound>(L"MoaiOK_S", L"..\\Resource\\sound\\OK.wav");

        //Bad BGM
        JSHResourcemng::Load<Sound>(L"MoaiBad_S", L"..\\Resource\\sound\\Bad.wav");

        //Ending BackGround
        Texture* EndingBG = JSHResourcemng::Load<Texture>(L"EndingBG", L"..\\Resource\\Ingame\\Loading.bmp");
        BackGround* edbg = object::Instantiate<BackGround>(eLayerType::BackGround);
        SpriteRenderer* edsr = edbg->AddComponent<SpriteRenderer>();
        Transform* edtr = edbg->GetComponent<Transform>();
        edtr->SetPosition(vector2(192.0f, 288.0f));
        edsr->SetTexture(EndingBG);
        edsr->SetScale(vector2(2.0f, 2.25f));

        //Ending TouchScreen
        BackGround* edtc = object::Instantiate<BackGround>(eLayerType::TouchScreen);
        SpriteRenderer* edtcsr = edtc->AddComponent<SpriteRenderer>();
        Transform* edtctr = edtc->GetComponent<Transform>();
        edtctr->SetPosition(vector2(576.0f, 288.0f));
        edtcsr->SetTexture(EndingBG);
        edtcsr->SetScale(vector2(2.0f, 2.25f));

        //Moai Ending Image
        MoaiEndImage* Moaiend = object::Instantiate<MoaiEndImage>(eLayerType::BackGroundObject);
        Transform* Moaiendtr = Moaiend->GetComponent<Transform>();
        Moaiendtr->SetPosition(vector2(192.0f, 288.0f));
    }
    void MoaiEnd::Update()
    {
        Scene::Update();

        if (input::GetKeyDown(eKeyCode::Lbutton))
        {
            SceneManager::LoadScene(L"SelectScene");
        }

    }
    void MoaiEnd::Render(HDC hdc)
    {
        Scene::Render(hdc);
    }
    void MoaiEnd::Enter()
    {
        //Find BGM
        Sound* sound1 = JSHResourcemng::Find<Sound>(L"MoaiPerfect_S");
        Sound* sound2 = JSHResourcemng::Find<Sound>(L"MoaiOK_S");
        Sound* sound3 = JSHResourcemng::Find<Sound>(L"MoaiBad_S");

        if (MoaiPlayer::GetScore() >= 100.0f)
        {
            sound1->Play(false);
        }
        else if (MoaiPlayer::GetScore() < 100.0f and MoaiPlayer::GetScore() >= 30.0f)
        {
            sound2->Play(false);
        }
        else if (MoaiPlayer::GetScore() < 30.0f)
        {
            sound3->Play(false);
        }
    }
    void MoaiEnd::Exit()
    {
        Sound* sound1 = JSHResourcemng::Find<Sound>(L"MoaiPerfect_S");
        Sound* sound2 = JSHResourcemng::Find<Sound>(L"MoaiOK_S");
        Sound* sound3 = JSHResourcemng::Find<Sound>(L"MoaiBad_S");

        sound1->Stop(true);
        sound2->Stop(true);
        sound3->Stop(true);
    }
}