#include "MoaiIcon.h"
#include "Texture.h"
#include "JSHResourcemng.h"
#include "Transform.h"
#include "Collider.h"
#include "Icon.h"
#include "Object.h"
#include "SpriteRenderer.h"
#include "BackGround.h"
#include "Animationmng.h"
#include "JSHinput.h"

namespace JSH
{
    MoaiIcon::MoaiIcon()
    {
    }
    MoaiIcon::~MoaiIcon()
    {
    }
    void MoaiIcon::Initialize()
    {
        GameObject::Initialize();

        Animationmng* animationmng = AddComponent<Animationmng>();
        animationmng->SetScale(vector2(2.0f, 2.0f));

        //OK Button
        Texture* OK_Button = JSHResourcemng::Load<Texture>(L"OK_Button", L"..\\Resource\\GameSelect\\OK_Button.bmp");
        animationmng->CreateAnimation(L"OKButton", OK_Button, vector2::Zero, vector2(32.0f, 26.0f), 1);

        //OK Button Pressed
        Texture* Press_OK = JSHResourcemng::Load<Texture>(L"Press", L"..\\Resource\\GameSelect\\Press_OK.bmp");
        animationmng->CreateAnimation(L"Press_Button", Press_OK, vector2::Zero, vector2(32.0f, 26.0f), 2);
        
        //Icon
        Texture* icon1 = JSHResourcemng::Load<Texture>(L"MoaiIcon", L"..\\Resource\\GameSelect\\Moai_Icon.bmp");
        Icon* ic1 = object::Instantiate<Icon>(eLayerType::Icon);
        SpriteRenderer* ic1sr = ic1->AddComponent<SpriteRenderer>();
        Transform* ic1tr = ic1->GetComponent<Transform>();
        Collider* ic1col = ic1->AddComponent<Collider>();
        ic1tr->SetPosition(vector2(576.0f, 144.0f));
        ic1sr->SetTexture(icon1);
        ic1sr->SetScale(vector2(2.0f, 2.0f));
        ic1col->SetSize(vector2(60.0f, 52.0f));

        //Frame
        Texture* iconframe = JSHResourcemng::Load<Texture>(L"IconFrame", L"..\\Resource\\GameSelect\\\Normal_Frame.bmp");
        BackGround* i1f = object::Instantiate<BackGround>(eLayerType::Effect);
        SpriteRenderer* i1fsr = i1f->AddComponent<SpriteRenderer>();
        Transform* i1ftr = i1f->GetComponent<Transform>();
        i1ftr->SetPosition(vector2(576.0f, 145.0f));
        i1fsr->SetTexture(iconframe);
        i1fsr->SetScale(vector2(2.0f, 2.0f));
        i1fsr->SetBmpRGB(255, 0, 255);
    }
    void MoaiIcon::Update()
    {
        GameObject::Update();
    }
    void MoaiIcon::Render(HDC hdc)
    {
        GameObject::Render(hdc);
    }
}