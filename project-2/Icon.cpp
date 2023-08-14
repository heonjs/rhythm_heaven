#include "Icon.h"
#include "JSHinput.h"
#include "Time.h"
#include "SpriteRenderer.h"
#include "JSHResourcemng.h"
#include "Texture.h"
#include "BackGround.h"
#include "Object.h"
#include "Transform.h"
#include "Animationmng.h"
#include "Collider.h"
#include "Collidermng.h"

namespace JSH
{
    Icon::Icon()
    {
    }
    Icon::~Icon()
    {
    }
    void Icon::Initialize()
    {
        GameObject::Initialize();
    }
    void Icon::Update()
    {
        GameObject::Update();
    }
    void Icon::Render(HDC hdc)
    {
        GameObject::Render(hdc);
    }
}