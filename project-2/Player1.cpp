#include "Player1.h"
#include "Time.h"
#include "JSHinput.h"
#include "Transform.h"

namespace JSH
{
    Player1::Player1()
    {
    }

    Player1::~Player1()
    {
    }

    void Player1::Initialize()
    {
    }

    void Player1::Update()
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

    void Player1::Render(HDC hdc)
    {
        GameObject::Render(hdc);
    }
}