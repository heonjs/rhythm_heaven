#include "EndingScene.h"
#include "Player1.h"
#include "SpriteRenderer.h"
#include "Object.h"

namespace JSH
{
    EndingScene::EndingScene()
    {
    }
    EndingScene::~EndingScene()
    {
    }
    void EndingScene::Initialize()
    {

    }

    void EndingScene::Update()
    {
        Scene::Update();
    }

    void EndingScene::Render(HDC hdc)
    {
        Scene::Render(hdc);

        wchar_t szFloat[50] = { L"GAME OVER" };
        int strlen = wcsnlen_s(szFloat, 50);
        TextOut(hdc, 10, 10, szFloat, strlen);
    }
}