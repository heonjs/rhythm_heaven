#include "BlueBirdsExplain.h"
#include "Texture.h"
#include "Animationmng.h"
#include "Transform.h"
#include "JSHResourcemng.h"
#include "JSHinput.h"

namespace JSH
{
    BlueBirdsExplain::BlueBirdsExplain()
    {
    }
    BlueBirdsExplain::~BlueBirdsExplain()
    {
    }
    void BlueBirdsExplain::Initialize()
    {
        GameObject::Initialize();

        Animationmng* animationmng = AddComponent<Animationmng>();


        //BlueBIrds Mini Title
        Texture* BB_MT = JSHResourcemng::Load<Texture>(L"BB_mt", L"..\\Resource\\Ingame\\Blue_Bird\\BB_MiniTitle.bmp");


        //BlueBirds Explain
        Texture* BB_Ex = JSHResourcemng::Load<Texture>(L"BB_ex", L"..\\Resource\\Ingame\\Blue_Bird\\BB_Ex.bmp");
    }
    void BlueBirdsExplain::Update()
    {
        GameObject::Update();

        Animationmng* animationmng = GetComponent<Animationmng>();

    }
    void BlueBirdsExplain::Render(HDC hdc)
    {
        GameObject::Render(hdc);
    }
}