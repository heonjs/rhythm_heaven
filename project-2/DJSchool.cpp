#include "DJSchool.h"
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
#include "Player1.h"

namespace JSH
{
    DJSchool::DJSchool()
        : mState(eState::Idle)
    {
    }
    DJSchool::~DJSchool()
    {
    }
    void DJSchool::Initialize()
    {
        // DJ RightScreen
        Texture* texture1 = JSHResourcemng::Load<Texture>(L"Game DJ"
            , L"..\\Resource\\Ingame\\DJSchool\\DJ_School_bg.bmp");
        
        BackGround* dj1 = object::Instantiate<BackGround>(eLayerType::BackGround);
        SpriteRenderer* dj1sr = dj1->AddComponent<SpriteRenderer>();
        Transform* dj1tr = dj1->GetComponent<Transform>();
        dj1tr->SetPosition(vector2(192.0f, 288.0f));
        dj1sr->SetTexture(texture1);
        dj1sr->SetScale(vector2(2.0f, 2.25f));

        //DJ TouchScreen
        Texture* texture2 = JSHResourcemng::Load<Texture>(L"Touch DJ"
            , L"..\\Resource\\Ingame\\DJSchool\\DJ_School_Right.bmp");

        BackGround* dj2 = object::Instantiate<BackGround>(eLayerType::TouchScreen);
        SpriteRenderer* dj2sr = dj2->AddComponent<SpriteRenderer>();
        Transform* dj2tr = dj2->GetComponent<Transform>();
        dj2tr->SetPosition(vector2(576.0f, 288.0f));
        dj2sr->SetTexture(texture2);
        dj2sr->SetScale(vector2(2.0f, 2.25f));
        
        // DJ Table
        Texture* djt = JSHResourcemng::Load<Texture>(L"DJ Table"
            , L"..\\Resource\\Ingame\\DJSchool\\DJ_Table.bmp");

        BackGround* dt = object::Instantiate<BackGround>(eLayerType::BackGroundObject);
        SpriteRenderer* dtsr = dt->AddComponent<SpriteRenderer>();
        Transform* dttr = dt->GetComponent<Transform>();
        dttr->SetPosition(vector2(192.0f, 448.0f));
        dtsr->SetTexture(djt);
        dtsr->SetScale(vector2(2.0f, 2.25f));

        //Blue DJ
        BackGround* Bdj = object::Instantiate<BackGround>(eLayerType::NPC1);
        Animationmng* BdjA = Bdj->AddComponent<Animationmng>();
        Transform* Bdjtr = Bdj->GetComponent<Transform>();
        BdjA->CreateAnimationFolder(L"bluedj", L"..\\Resource\\Ingame\\DJSchool\\B_normal_body",
            vector2(97.0f, 105.0f), float(0.13f));
        Bdjtr->SetPosition(vector2(192.0f, 261.0f));
        BdjA->SetScale(vector2(2.0f, 2.25f));
        BdjA->PlayAnimation(L"bluedj", true);

        /*Texture* BDJ = JSHResourcemng::Load<Texture>(L"bdj"
            , L"..\\Resource\\Ingame\\DJSchool\\Bdj_normal.bmp");

        BackGround* bdj = object::Instantiate<BackGround>(eLayerType::NPC1);
        Animationmng* bdjA = bdj->AddComponent<Animationmng>();
        Transform* bdjtr = bdj->GetComponent<Transform>();
        bdjA->CreateAnimation(L"bdj", BDJ, vector2(0.0f, 0.0f), vector2(105.0f, 110.0f), 3, vector2(86.0f, 110.0f));
        bdjtr->SetPosition(vector2(192.0f, 261.0f));
        bdjA->SetScale(vector2(2.0f, 2.0f));
        bdjA->PlayAnimation(L"bdj", true);*/

        
    }
    void DJSchool::Update()
    {
        Scene::Update();
    }
    void DJSchool::Render(HDC hdc)
    {
        Scene::Render(hdc);
    }


    void DJSchool::Idle()
    {
    }
    void DJSchool::Touch()
    {
    }
    void DJSchool::Slide()
    {
    }
}