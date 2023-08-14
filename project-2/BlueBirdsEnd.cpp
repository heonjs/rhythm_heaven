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
        JSHResourcemng::Load<Sound>(L"BB_Bad_BGM", L"..\\Resource\\sound\\TryAgain.wav");

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

        //BlueBirds Ending Perfect
        Texture* BB_Perfect = JSHResourcemng::Load<Texture>(L"BB_Perfect"
            , L"..\\Resource\\Ingame\\Blue_Bird\\BBEnd_Perfect.bmp");
        BackGround* bbP = object::Instantiate<BackGround>(eLayerType::Effect);
        SpriteRenderer* bbPsr = bbP->AddComponent<SpriteRenderer>();
        Transform* bbPtr = bbP->GetComponent<Transform>();
        bbPsr->SetTexture(BB_Perfect);
        bbPsr->SetScale(vector2(2.0f, 2.0f));
        bbPtr->SetPosition(vector2(192.0f, 288.0f));

        //BlueBirds Ending OK
        Texture* BB_OK = JSHResourcemng::Load<Texture>(L"BB_OK"
            , L"..\\Resource\\Ingame\\Blue_Bird\\BBEnd_OK.bmp");
        BackGround* bbO = object::Instantiate<BackGround>(eLayerType::Effect);
        SpriteRenderer* bbOsr = bbO->AddComponent<SpriteRenderer>();
        Transform* bbOtr = bbO->GetComponent<Transform>();
        bbOsr->SetTexture(BB_OK);
        bbOsr->SetScale(vector2(2.0f, 2.0f));
        bbOtr->SetPosition(vector2(192.0f, 288.0f));

        //BlueBirds Ending Bad
        Texture* BB_Bad = JSHResourcemng::Load<Texture>(L"BB_Bad"
            , L"..\\Resource\\Ingame\\Blue_Bird\\BBEnd_Bad.bmp");
        BackGround* bbB = object::Instantiate<BackGround>(eLayerType::Effect);
        SpriteRenderer* bbBsr = bbB->AddComponent<SpriteRenderer>();
        Transform* bbBtr = bbB->GetComponent<Transform>();
        bbBsr->SetTexture(BB_Bad);
        bbBsr->SetScale(vector2(2.0f, 2.0f));
        bbBtr->SetPosition(vector2(192.0f, 288.0f));

    }
    void BlueBirdsEnd::Update()
    {
        Scene::Update();
    }
    void BlueBirdsEnd::Render(HDC hdc)
    {
        Scene::Render(hdc);
    }
    void BlueBirdsEnd::Enter()
    {
    }
    void BlueBirdsEnd::Exit()
    {
    }
}