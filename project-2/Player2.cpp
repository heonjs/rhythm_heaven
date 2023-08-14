#include "Player2.h"
#include "JSHinput.h"
#include "Include.h"
#include "Time.h"
#include "Transform.h"
#include "SpriteRenderer.h"

namespace JSH
{
    Player2::Player2()
    {
    }
    Player2::~Player2()
    {
    }
    void Player2::Initialize()
    {
    }
    void Player2::Update()
    {
        GameObject::Update();

        Transform* tr = GetComponent<Transform>();
        vector2 pos = tr->GetPosition();

        if (input::GetKey(eKeyCode::W))
        {
            pos.y -= 300.0f * Time::DeltaTime();
        }
        if (input::GetKey(eKeyCode::A))
        {
            pos.x -= 300.0f * Time::DeltaTime();
        }
        if (input::GetKey(eKeyCode::S))
        {
            pos.y += 300.0f * Time::DeltaTime();
        }
        if (input::GetKey(eKeyCode::D))
        {
            pos.x += 300.0f * Time::DeltaTime();
        }

        tr->SetPosition(pos);
    }
    void Player2::Render(HDC hdc)
    {
        GameObject::Render(hdc);
    }
}