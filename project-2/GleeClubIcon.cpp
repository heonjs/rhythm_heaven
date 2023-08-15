#include "GleeClubIcon.h"
#include "Texture.h"
#include "JSHResourcemng.h"
#include "Transform.h"
#include "Collider.h"
#include "Icon.h"
#include "Object.h"
#include "SpriteRenderer.h"
#include "BackGround.h"
#include "Animationmng.h"

namespace JSH
{
    GleeClubIcon::GleeClubIcon()
    {
    }
    GleeClubIcon::~GleeClubIcon()
    {
    }
    void GleeClubIcon::Initialize()
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
        Texture* icon2 = JSHResourcemng::Load<Texture>(L"GleeClubIcon"
            , L"..\\Resource\\GameSelect\\Glee_Club_Icon.bmp");
        Icon* ic2 = object::Instantiate<Icon>(eLayerType::Icon);
        SpriteRenderer* ic2sr = ic2->AddComponent<SpriteRenderer>();
        Transform* ic2tr = ic2->GetComponent<Transform>();
        Collider* ic2col = ic2->AddComponent<Collider>();
        ic2tr->SetPosition(vector2(576.0f, 264.0f));
        ic2sr->SetTexture(icon2);
        ic2sr->SetScale(vector2(2.0f, 2.0f));
        ic2col->SetSize(vector2(60.0f, 52.0f));

        //Frame
        Texture* iconframe = JSHResourcemng::Load<Texture>(L"IconFrame"
            , L"..\\Resource\\GameSelect\\\Normal_Frame.bmp");
        BackGround* i2f = object::Instantiate<BackGround>(eLayerType::Effect);
        SpriteRenderer* i2fsr = i2f->AddComponent<SpriteRenderer>();
        Transform* i2ftr = i2f->GetComponent<Transform>();
        i2ftr->SetPosition(vector2(576.0f, 265.0f));
        i2fsr->SetTexture(iconframe);
        i2fsr->SetScale(vector2(2.0f, 2.0f));
        i2fsr->SetBmpRGB(255, 0, 255);
    }
    void GleeClubIcon::Update()
    {
        GameObject::Update();
    }
    void GleeClubIcon::Render(HDC hdc)
    {
        GameObject::Render(hdc);
    }
}