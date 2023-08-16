#include "SelectScene.h"
#include "SpriteRenderer.h"
#include "Object.h"
#include "JSHinput.h"
#include "Texture.h"
#include "JSHResourcemng.h"
#include "BackGround.h"
#include "Transform.h"
#include "Time.h"
#include "Sound.h"
#include "Collider.h"
#include "Collidermng.h"
#include "MouseCursor.h"
#include "MoaiIcon.h"
#include "GleeClubIcon.h"
#include "BBIcon.h"
#include "BlueBirdsExplain.h"
#include "GleeClubExplain.h"
#include "MoaiExplain.h"

namespace JSH
{
    SelectScene::SelectScene()
        : mIcon{nullptr}
        , mBG{ nullptr }
        , mChange(false)
    {
    }
    SelectScene::~SelectScene()
    {
    }
    void SelectScene::Initialize()
    {         
        // BackGround
        Texture* texture1 = JSHResourcemng::Load<Texture>(L"SelectRight"
            , L"..\\Resource\\Title\\RightTitle.bmp");
        BackGround* bg1 = object::Instantiate<BackGround>(eLayerType::BackGround);
        SpriteRenderer* bg1sr = bg1->AddComponent<SpriteRenderer>();
        Transform* bg1tr = bg1->GetComponent<Transform>();
        bg1tr->SetPosition(vector2(192.0f, 288.0f));
        bg1sr->SetTexture(texture1);
        bg1sr->SetScale(vector2(2.0f, 2.25f));

        //Touch Screen
        Texture* texture2 = JSHResourcemng::Load<Texture>(L"SelectTouch"
            , L"..\\Resource\\GameSelect\\Select_Scene.bmp");
        BackGround* rs = object::Instantiate<BackGround>(eLayerType::TouchScreen);
        SpriteRenderer* rssr = rs->AddComponent<SpriteRenderer>();
        Transform* rstr = rs->GetComponent<Transform>();
        rstr->SetPosition(vector2(576.0f, 288.0f));
        rssr->SetTexture(texture2);
        rssr->SetScale(vector2(2.0f, 2.25f));

        //Mini Title
        Texture* minititle = JSHResourcemng::Load<Texture>(L"MiniTitle"
            , L"..\\Resource\\GameSelect\\Mini_Title.bmp");
        BackGround* mt = object::Instantiate<BackGround>(eLayerType::UI);
        SpriteRenderer* mtsr = mt->AddComponent<SpriteRenderer>();
        Transform* mttr = mt->GetComponent<Transform>();
        mttr->SetPosition(vector2(73.0f, 59.0f));
        mtsr->SetTexture(minititle);
        mtsr->SetScale(vector2(2.0f, 2.0f));
        mtsr->SetBmpRGB(255, 0, 255);

        //Game Explain
        Texture* texture3 = JSHResourcemng::Load<Texture>(L"GameExplain"
            , L"..\\Resource\\GameSelect\\Game_Explain.bmp");
        BackGround* ge = object::Instantiate<BackGround>(eLayerType::UI);
        SpriteRenderer* ge1sr = ge->AddComponent<SpriteRenderer>();
        Transform* ge1tr = ge->GetComponent<Transform>();
        ge1tr->SetPosition(vector2(192.0f, 288.0f));
        ge1sr->SetTexture(texture3);
        ge1sr->SetScale(vector2(2.0f, 2.0f));
        ge1sr->SetBmpRGB(255, 0, 255);

        //Moai Icon
        MoaiIcon* moaiicon = object::Instantiate<MoaiIcon>(eLayerType::Icon);

        //GleeClub Icon
        GleeClubIcon* gleeclubicon = object::Instantiate<GleeClubIcon>(eLayerType::Icon);

        //BlueBirds Icon
        BBIcon* bbicon = object::Instantiate<BBIcon>(eLayerType::Icon);

        //Mouse Cursor
        MouseCursor* mouse = object::Instantiate<MouseCursor>(eLayerType::Cursor);
        Collidermng::ColliderLayerCheck(eLayerType::Icon, eLayerType::Cursor, true);

        //Select BGM
        JSHResourcemng::Load<Sound>(L"SelectSound", L"..\\Resource\\Sound\\Game_Select.wav");      
    }
    void SelectScene::Update()
    {
        vector2 mp = input::GetMousepos();
        
        Sound* sound = JSHResourcemng::Find<Sound>(L"SelectSound");

        if (546.0f <= mp.x and mp.x <= 606.0f and
            115.0f <= mp.y and mp.y <= 173.0f)
        {
            if (input::GetKeyDown(eKeyCode::Lbutton))
            {
                sound->Stop(false);
                SceneManager::LoadScene(L"MoaiTitle");
            }
        }

        if (546.0f <= mp.x and mp.x <= 606.0f and
            238.0f <= mp.y and mp.y <= 290.0f)
        {
            if (input::GetKeyDown(eKeyCode::Lbutton))
            {
                sound->Stop(false);
                SceneManager::LoadScene(L"GleeClubTitle");
            }
        }

        if (546.0f <= mp.x and mp.x <= 606.0f and
            358.0f <= mp.y and mp.y <= 410.0f)
        {
            if (input::GetKeyDown(eKeyCode::Lbutton))
            {
                sound->Stop(false);
                SceneManager::LoadScene(L"BlueBirdsTitle");
            }
        }

        if (546.0f <= mp.x and mp.x <= 606.0f and
            499.0f <= mp.y and mp.y <= 551.0f)
        {
            if (input::GetKeyDown(eKeyCode::Lbutton))
            {
                //sound->Stop(false);
                //SceneManager::LoadScene(L"CafeScene");
            }
        }

        if (input::GetKeyDown(eKeyCode::R))
        {
            SceneManager::LoadScene(L"TitleScene");
        }

        Scene::Update();
    }
    void SelectScene::Render(HDC hdc)
    {
        Scene::Render(hdc);
    }
    void SelectScene::onCollisionEnter()
    {
        
    }
    void SelectScene::onCollisionExit()
    {
    }
    void SelectScene::Enter()
    {
        Sound* sound = JSHResourcemng::Find<Sound>(L"SelectSound");
        sound->Play(true);
    }
    void SelectScene::Exit()
    {
        Sound* sound = JSHResourcemng::Find<Sound>(L"SelectSound");
        sound->Stop(false);
    }
}