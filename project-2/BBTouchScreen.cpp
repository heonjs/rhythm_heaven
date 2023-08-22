#include "BBTouchScreen.h"
#include "Transform.h"
#include "Collider.h"
#include "MouseCursor.h"
#include "JSHinput.h"
#include "Texture.h"
#include "SpriteRenderer.h"
#include "BackGround.h"
#include "Object.h"
#include "JSHResourcemng.h"

namespace JSH
{
    BBTouchScreen::BBTouchScreen()
    {
    }
    BBTouchScreen::~BBTouchScreen()
    {
    }
    void BBTouchScreen::Initialize()
    {
        GameObject::Initialize();

        //Touch Screen
        Texture* texture = JSHResourcemng::Load<Texture>(L"BlueBirdsTouchScreen"
            , L"..\\Resource\\Ingame\\Blue_Bird\\TouchScreen.bmp");
        BackGround* bt = object::Instantiate<BackGround>(eLayerType::TouchScreen);
        SpriteRenderer* btsr = bt->AddComponent<SpriteRenderer>();
        Transform* bttr = bt->GetComponent<Transform>();
        bttr->SetPosition(vector2(576.0f, 288.0f));
        btsr->SetTexture(texture);
        btsr->SetScale(vector2(2.0f, 2.25f));
    }
    void BBTouchScreen::Update()
    {
        GameObject::Update();
    }
    void BBTouchScreen::Render(HDC hdc)
    {
        GameObject::Render(hdc);
    }
    void BBTouchScreen::OnColliderExit(Collider* other)
    {
    }
}