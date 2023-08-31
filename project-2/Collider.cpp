#include "Collider.h"
#include "Transform.h"
#include "GameObject.h"
#include "JSHinput.h"

namespace JSH
{
    UINT Collider::mCollisionCount = 0;
    bool Collider::mColTrigger = false;

    Collider::Collider()
        : Component(eComponentType::Collider)
        , mSize(vector2::Zero)
        , mOffset(vector2::Zero)
        , mCollisionNumber(-1)
        , mbIsCollision(false)
    {
        mCollisionNumber = mCollisionCount;
        mCollisionCount++;
    }
    Collider::~Collider()
    {
    }
    void Collider::Initialize()
    {
    }
    void Collider::Update()
    {
        if (input::GetKeyDown(eKeyCode::P))
        {
            mColTrigger = true;
        }
        if (input::GetKeyDown(eKeyCode::M))
        {
            mColTrigger = false;
        }
    }
    void Collider::Render(HDC hdc)
    {
        Transform* tr = GetOwner()->GetComponent<Transform>();
        vector2 pos = tr->GetPosition();
        mPosition = pos + mOffset;

        pos.x -= mSize.x / 2.0f;
        pos.y -= mSize.y / 2.0f;
        pos.x += mOffset.x;
        pos.y += mOffset.y;

        HBRUSH TransParentBrush = (HBRUSH)GetStockObject(NULL_BRUSH);
        HBRUSH OldBrush = (HBRUSH)SelectObject(hdc, TransParentBrush);
        HPEN pen = NULL;

        if (mbIsCollision)
        {
            pen = CreatePen(PS_SOLID, 2, RGB(255, 50, 50));
        }
        else
        {
            pen = CreatePen(PS_SOLID, 2, RGB(50, 255, 50));
        }

        HPEN OldPen = (HPEN)SelectObject(hdc, pen);

        if (mColTrigger == true)
        {
            Rectangle(hdc, pos.x, pos.y
                , pos.x + mSize.x, pos.y + mSize.y);
        }

        SelectObject(hdc, OldBrush);
        DeleteObject(TransParentBrush);

        SelectObject(hdc, OldPen);
        DeleteObject(pen);
    }
    void Collider::OnColliderEnter(Collider* other)
    {
        mbIsCollision = true;
        GetOwner()->OnColliderEnter(other);
    }
    void Collider::OnColliderStay(Collider* other)
    {
        GetOwner()->OnColliderStay(other);
    }
    void Collider::OnColliderExit(Collider* other)
    {
        mbIsCollision = false;
        GetOwner()->OnColliderExit(other);
    }
}