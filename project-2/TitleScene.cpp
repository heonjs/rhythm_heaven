#include "TitleScene.h"
#include "SpriteRenderer.h"
#include "Object.h"
#include "JSHinput.h"
#include "Texture.h"
#include "JSHResourcemng.h"
#include "BackGround.h"
#include "Transform.h"
#include "Animationmng.h"
#include "Animation.h"
#include "JSHgame.h"
#include "Sound.h"

extern JSH::game Game;

namespace JSH
{
    TitleScene::TitleScene()
    {
    }
    TitleScene::~TitleScene()
    {
    }
    void TitleScene::Initialize()
    {
        //background Animation
        BackGround* bg = object::Instantiate<BackGround>(eLayerType::TouchScreen);
        Transform* bgtr = bg->GetComponent<Transform>();
        bgtr->SetPosition(vector2(192.0f, 288.0f));
        Animationmng* bgA = bg->AddComponent<Animationmng>();
        bgA->CreateAnimationFolder(L"Title", L"..\\Resource\\Title\\MainTitle", vector2(0.0f,0.0f), float (0.1f));
        bgA->PlayAnimation(L"Title", true);
        bgA->SetScale(vector2(2.0f, 2.25f));
        
        //Touch Screen
        Texture* texture2 = JSHResourcemng::Load<Texture>(L"TitleTouch"
            , L"..\\Resource\\Title\\TouchScreen.bmp");
        BackGround* rs = object::Instantiate<BackGround>(eLayerType::BackGround);
        SpriteRenderer* rssr = rs->AddComponent<SpriteRenderer>();
        Transform* rstr = rs->GetComponent<Transform>();
        rstr->SetPosition(vector2(576.0f, 288.0f));
        rssr->SetTexture(texture2);
        rssr->SetScale(vector2(2.0f, 2.25f));

        //Title Sound
        JSHResourcemng::Load<Sound>(L"TitleSound", L"..\\Resource\\Sound\\Title.wav");
    }
    void TitleScene::Update()
    {
        vector2 mp = input::GetMousepos();

        if (384.0f <= mp.x and mp.x <= 768.0f and
            0.0f <= mp.y and mp.y <= 576.0f)
        {
            if (input::GetKeyDown(eKeyCode::Lbutton))
            {      
                SceneManager::LoadScene(L"SelectScene");
            }
        }
        Scene::Update();
    }
    void TitleScene::Render(HDC hdc)
    {
        Scene::Render(hdc);
    }
    void TitleScene::Enter()
    {
        Sound* sound = JSHResourcemng::Find<Sound>(L"TitleSound");
        sound->Play(true);
    }
    void TitleScene::Exit()
    {
        Sound* sound = JSHResourcemng::Find<Sound>(L"TitleSound");
        sound->Stop(false);
    }
}