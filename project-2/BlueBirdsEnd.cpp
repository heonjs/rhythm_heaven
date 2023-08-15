#include "BlueBirdsEnd.h"
#include "SpriteRenderer.h"
#include "Object.h"
#include "JSHinput.h"
#include "Texture.h"
#include "JSHResourcemng.h"
#include "BackGround.h"
#include "Transform.h"
#include "Time.h"
#include "Sound.h"
#include "BlueBirds.h"
#include "BBEndImage.h"

namespace JSH
{
    BlueBirdsEnd::BlueBirdsEnd()
    {
    }
    BlueBirdsEnd::~BlueBirdsEnd()
    {
    }
    void BlueBirdsEnd::Initialize()
    {
        //Ending Perfect BGM
        JSHResourcemng::Load<Sound>(L"BB_Perfect_BGM", L"..\\Resource\\sound\\Perfect.wav");
        
        //Ending OK BGM
        JSHResourcemng::Load<Sound>(L"BB_OK_BGM", L"..\\Resource\\sound\\OK.wav");

        //Ending Bad BGM
        JSHResourcemng::Load<Sound>(L"BB_Bad_BGM", L"..\\Resource\\sound\\Bad.wav");

        // Blue Birds Ending
        Texture* texture1 = JSHResourcemng::Load<Texture>(L"BB_Ending_BG"
            , L"..\\Resource\\Ingame\\Loading.bmp");
        BackGround* bb = object::Instantiate<BackGround>(eLayerType::BackGround);
        SpriteRenderer* bbsr = bb->AddComponent<SpriteRenderer>();
        Transform* bbtr = bb->GetComponent<Transform>();
        bbtr->SetPosition(vector2(192.0f, 288.0f));
        bbsr->SetTexture(texture1);
        bbsr->SetScale(vector2(2.0f, 2.25f));

        //Blue Birds Ending Loading
        Texture* texture2 = JSHResourcemng::Load<Texture>(L"BB_Ending_Touch"
            , L"..\\Resource\\Ingame\\Loading.bmp");
        BackGround* bt = object::Instantiate<BackGround>(eLayerType::TouchScreen);
        SpriteRenderer* btsr = bt->AddComponent<SpriteRenderer>();
        Transform* bttr = bt->GetComponent<Transform>();
        bttr->SetPosition(vector2(576.0f, 288.0f));
        btsr->SetTexture(texture2);
        btsr->SetScale(vector2(2.0f, 2.25f));

        //BB Ending Image
        BBEndImage* BBend = object::Instantiate<BBEndImage>(eLayerType::BackGroundObject);
        Transform* BBendtr = BBend->GetComponent<Transform>();
        BBendtr->SetPosition(vector2(192.0f, 288.0f));
    }
    void BlueBirdsEnd::Update()
    {
        Scene::Update();

        if (input::GetKeyDown(eKeyCode::Lbutton))
        {
            SceneManager::LoadScene(L"SelectScene");
        }
    }
    void BlueBirdsEnd::Render(HDC hdc)
    {
        Scene::Render(hdc);
    }
    void BlueBirdsEnd::Enter()
    {
        Sound* sound1 = JSHResourcemng::Find<Sound>(L"BB_Perfect_BGM");
        Sound* sound2 = JSHResourcemng::Find<Sound>(L"BB_OK_BGM");
        Sound* sound3 = JSHResourcemng::Find<Sound>(L"BB_Bad_BGM");

        if (BlueBirds::GetScore() >= 100.0f)
        {
            sound1->Play(false);

        }
        else if (BlueBirds::GetScore() < 100.0f and BlueBirds::GetScore() >= 30.0f)
        {
            sound2->Play(false);
        }
        else if (BlueBirds::GetScore() < 30.0f)
        {
            sound3->Play(false);
        }
    }
    void BlueBirdsEnd::Exit()
    {
        Sound* sound1 = JSHResourcemng::Find<Sound>(L"BB_Perfect_BGM");
        Sound* sound2 = JSHResourcemng::Find<Sound>(L"BB_OK_BGM");
        Sound* sound3 = JSHResourcemng::Find<Sound>(L"BB_Bad_BGM");

        sound1->Stop(true);
        sound2->Stop(true);
        sound3->Stop(true);
    }
}