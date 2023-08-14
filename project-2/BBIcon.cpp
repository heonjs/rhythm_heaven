#include "BBIcon.h"
#include "Texture.h"
#include "JSHResourcemng.h"
#include "Transform.h"
#include "Collider.h"
#include "Icon.h"
#include "Object.h"
#include "SpriteRenderer.h"
#include "BackGround.h"
#include "JSHinput.h"
#include "Animationmng.h"

namespace JSH
{
    BBIcon::BBIcon()
    {
    }
    BBIcon::~BBIcon()
    {
    }
    void BBIcon::Initialize()
    {
        GameObject::Initialize();

        //Icon
        Texture* bbicon = JSHResourcemng::Load<Texture>(L"BlueBirdsIcon"
            , L"..\\Resource\\GameSelect\\Blue_Birds_Icon.bmp");
        Icon* ic3 = object::Instantiate<Icon>(eLayerType::Icon);
        SpriteRenderer* ic3sr = ic3->AddComponent<SpriteRenderer>();
        Transform* ic3tr = ic3->GetComponent<Transform>();
        Collider* ic3col = ic3->AddComponent<Collider>();
        ic3tr->SetPosition(vector2(576.0f, 384.0f));
        ic3sr->SetTexture(bbicon);
        ic3sr->SetScale(vector2(2.0f, 2.0f));
        ic3col->SetSize(vector2(60.0f, 52.0f));

        //Frame
        Texture* iconframe = JSHResourcemng::Load<Texture>(L"IconFrame"
            , L"..\\Resource\\GameSelect\\\Normal_Frame.bmp");
        BackGround* i3f = object::Instantiate<BackGround>(eLayerType::Effect);
        SpriteRenderer* i3fsr = i3f->AddComponent<SpriteRenderer>();
        Transform* i3ftr = i3f->GetComponent<Transform>();
        i3ftr->SetPosition(vector2(576.0f, 385.0f));
        i3fsr->SetTexture(iconframe);
        i3fsr->SetScale(vector2(2.0f, 2.0f));
        i3fsr->SetBmpRGB(255, 0, 255);

        //OK Button
        Texture* OK_Button = JSHResourcemng::Load<Texture>(L"OK_Button"
            , L"..\\Resource\\GameSelect\\\OK_Button.bmp");
    }
    void BBIcon::Update()
    {
        GameObject::Update();
    }
    void BBIcon::Render(HDC hdc)
    {
        GameObject::Render(hdc);
    }
}