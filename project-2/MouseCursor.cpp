#include "MouseCursor.h"
#include "JSHinput.h"
#include "Collider.h"
#include "Transform.h"
#include "MoaiIcon.h"
#include "BBIcon.h"
#include "GleeClubIcon.h"

namespace JSH
{
    MouseCursor::MouseCursor()
    {
    }
    MouseCursor::~MouseCursor()
    {
    }
    void MouseCursor::Initialize()
    {
        GameObject::Initialize();

        Collider* col = AddComponent<Collider>();
        col->SetSize(vector2(10.0f, 10.0f));
    }
    void MouseCursor::Update()
    {
        GameObject::Update();

        Transform* mtr = GetComponent<Transform>();

        mtr->SetPosition(input::GetMousepos());

    }
    void MouseCursor::Render(HDC hdc)
    {
        GameObject::Render(hdc);
    }
    void MouseCursor::OnColliderEnter(Collider* other)
    {
    }
    void MouseCursor::OnColliderExit(Collider* other)
    {
    }
}