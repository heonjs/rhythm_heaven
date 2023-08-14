#include "FanClubTitle.h"
#include "SpriteRenderer.h"
#include "Object.h"
#include "JSHinput.h"
#include "Texture.h"
#include "JSHResourcemng.h"
#include "BackGround.h"
#include "Transform.h"
#include "Time.h"
#include "Animationmng.h"

namespace JSH
{
    FanClubTitle::FanClubTitle()
    {
    }
    FanClubTitle::~FanClubTitle()
    {
    }
    void FanClubTitle::Initialize()
    {
        //Fan Club Title BackGround
        Texture* texture1 = JSHResourcemng::Load<Texture>(L"FanClubBG"
            , L"..\\Resource\\Ingame\\Fan_Club\\FanClubTitle_BG.bmp");

        BackGround* fb1 = object::Instantiate<BackGround>(eLayerType::BackGround);
        SpriteRenderer* fb1sr = fb1->AddComponent<SpriteRenderer>();
        Transform* fb1tr = fb1->GetComponent<Transform>();
        fb1tr->SetPosition(vector2(192.0f, 288.0f));
        fb1sr->SetTexture(texture1);
        fb1sr->SetScale(vector2(2.0f, 2.25f));

        //Fan Club Title
        Texture* texture2 = JSHResourcemng::Load<Texture>(L"FanClubTitle"
            , L"..\\Resource\\Ingame\\Fan_Club\\FanClub_Title.bmp");

        BackGround* ft = object::Instantiate<BackGround>(eLayerType::BackGroundObject);
        SpriteRenderer* ftsr = ft->AddComponent<SpriteRenderer>();
        Transform* fttr = ft->GetComponent<Transform>();
        fttr->SetPosition(vector2(192.0f, 288.0f));
        ftsr->SetBmpRGB(255, 255, 255);
        ftsr->SetTexture(texture2);
        ftsr->SetScale(vector2(2.0f, 2.25f));

        //Fan Club Loding
        Texture* texture3 = JSHResourcemng::Load<Texture>(L"FanClubLoading"
            , L"..\\Resource\\Ingame\\Loading.bmp");

        BackGround* fl = object::Instantiate<BackGround>(eLayerType::TouchScreen);
        SpriteRenderer* flsr = fl->AddComponent<SpriteRenderer>();
        Transform* fltr = fl->GetComponent<Transform>();
        fltr->SetPosition(vector2(576.0f, 288.0f));
        flsr->SetTexture(texture3);
        flsr->SetScale(vector2(2.0f, 2.25f));

        //Singer Animation
        Texture* texture4 = JSHResourcemng::Load<Texture>(L"idol Animation"
            , L"..\\Resource\\Ingame\\Fan_Club\\Fan_Club.bmp");

        BackGround* idol = object::Instantiate<BackGround>(eLayerType::NPC1);
        Animationmng* idolA = idol->AddComponent<Animationmng>();
        Transform* idoltr = idol->GetComponent<Transform>();
        idolA->CreateAnimation(L"idol Animation", texture4, vector2(0.0f, 875.0f), vector2(51.0f, 125.0f), 18);
        idoltr->SetPosition(vector2(100.0f, 450.0f));
        idolA->SetBmpRGB(L"idol Animation", 151, 151, 151);
        idolA->SetScale(vector2(2.0f, 2.0f));
        idolA->PlayAnimation(L"idol Animation", true);
    }
    void FanClubTitle::Update()
    {
        Scene::Update();
    }
    void FanClubTitle::Render(HDC hdc)
    {
        Scene::Render(hdc);
    }
}