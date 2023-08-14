#include "BackGround.h"
#include "Transform.h"
#include "JSHinput.h"
#include "Time.h"
#include "SpriteRenderer.h"

namespace JSH
{
    BackGround::BackGround()
    {

    }
    BackGround::~BackGround()
    {
    }
    void BackGround::Initialize()
    {
    }
    void BackGround::Update()
    {
        GameObject::Update();
    }
    void BackGround::Render(HDC hdc)
    {
        GameObject::Render(hdc);
    }
}