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
        : mAnimationmng(nullptr)
    {
    }
    Icon::~Icon()
    {
    }
    void Icon::Initialize()
    {
        GameObject::Initialize();

        //Moai Icon
        Texture* icon1 = JSHResourcemng::Load<Texture>(L"MoaiIcon"
            , L"..\\Resource\\GameSelect\\Moai_Icon.bmp");
        BackGround* ic1 = object::Instantiate<BackGround>(eLayerType::UI);
        SpriteRenderer* ic1sr = ic1->AddComponent<SpriteRenderer>();
        Transform* ic1tr = ic1->GetComponent<Transform>();
        Collider* ic1col = ic1->AddComponent<Collider>();
        ic1tr->SetPosition(vector2(576.0f, 144.0f));
        ic1sr->SetTexture(icon1);
        ic1sr->SetScale(vector2(2.0f, 2.0f));
        ic1col->SetSize(vector2(60.0f, 52.0f));

        //GleeClub icon
        Texture* icon2 = JSHResourcemng::Load<Texture>(L"GleeClubIcon"
            , L"..\\Resource\\GameSelect\\Glee_Club_Icon.bmp");
        BackGround* ic2 = object::Instantiate<BackGround>(eLayerType::UI);
        SpriteRenderer* ic2sr = ic2->AddComponent<SpriteRenderer>();
        Transform* ic2tr = ic2->GetComponent<Transform>();
        Collider* ic2col = ic2->AddComponent<Collider>();
        ic2tr->SetPosition(vector2(576.0f, 264.0f));
        ic2sr->SetTexture(icon2);
        ic2sr->SetScale(vector2(2.0f, 2.0f));
        ic2col->SetSize(vector2(60.0f, 52.0f));

        // Blue Birds icon
        Texture* icon3 = JSHResourcemng::Load<Texture>(L"BlueBirdsIcon"
            , L"..\\Resource\\GameSelect\\Blue_Birds_Icon.bmp");
        BackGround* ic3 = object::Instantiate<BackGround>(eLayerType::UI);
        SpriteRenderer* ic3sr = ic3->AddComponent<SpriteRenderer>();
        Transform* ic3tr = ic3->GetComponent<Transform>();
        Collider* ic3col = ic3->AddComponent<Collider>();
        ic3tr->SetPosition(vector2(576.0f, 384.0f));
        ic3sr->SetTexture(icon3);
        ic3sr->SetScale(vector2(2.0f, 2.0f));
        ic3col->SetSize(vector2(60.0f, 52.0f));

        //cafe icon
        Texture* icon4 = JSHResourcemng::Load<Texture>(L"Cafe"
            , L"..\\Resource\\GameSelect\\Cafe.bmp");
        BackGround* cafe = object::Instantiate<BackGround>(eLayerType::UI);
        SpriteRenderer* cafesr = cafe->AddComponent<SpriteRenderer>();
        Transform* cafetr = cafe->GetComponent<Transform>();
        Collider* cafecol = cafe->AddComponent<Collider>();
        cafetr->SetPosition(vector2(576.0f, 525.0f));
        cafesr->SetTexture(icon4);
        cafesr->SetScale(vector2(2.0f, 2.0f));
        cafesr->SetBmpRGB(255, 0, 255);
        cafecol->SetSize(vector2(70.0f, 74.0f));

        //Icon1 Frame
        Texture* iconframe = JSHResourcemng::Load<Texture>(L"IconFrame"
            , L"..\\Resource\\GameSelect\\\Normal_Frame.bmp");
        BackGround* i1f = object::Instantiate<BackGround>(eLayerType::Effect);
        SpriteRenderer* i1fsr = i1f->AddComponent<SpriteRenderer>();
        Transform* i1ftr = i1f->GetComponent<Transform>();
        i1ftr->SetPosition(vector2(576.0f, 145.0f));
        i1fsr->SetTexture(iconframe);
        i1fsr->SetScale(vector2(2.0f, 2.0f));
        i1fsr->SetBmpRGB(255, 0, 255);

        //Icon2 Frame
        BackGround* i2f = object::Instantiate<BackGround>(eLayerType::Effect);
        SpriteRenderer* i2fsr = i2f->AddComponent<SpriteRenderer>();
        Transform* i2ftr = i2f->GetComponent<Transform>();
        i2ftr->SetPosition(vector2(576.0f, 265.0f));
        i2fsr->SetTexture(iconframe);
        i2fsr->SetScale(vector2(2.0f, 2.0f));
        i2fsr->SetBmpRGB(255, 0, 255);

        //Icon3 Frame
        BackGround* i3f = object::Instantiate<BackGround>(eLayerType::Effect);
        SpriteRenderer* i3fsr = i3f->AddComponent<SpriteRenderer>();
        Transform* i3ftr = i3f->GetComponent<Transform>();
        i3ftr->SetPosition(vector2(576.0f, 385.0f));
        i3fsr->SetTexture(iconframe);
        i3fsr->SetScale(vector2(2.0f, 2.0f));
        i3fsr->SetBmpRGB(255, 0, 255);

        //OK Button
        Texture* OK_Button = JSHResourcemng::Load<Texture>(L"OK_Button"
            , L"..\\Resource\\GameSelect\\OK_Button.bmp");
        BackGround* okbg = object::Instantiate<BackGround>(eLayerType::Effect);
        SpriteRenderer* obsr = okbg->AddComponent<SpriteRenderer>();
        Transform* obtr = okbg->GetComponent<Transform>();
        obsr->SetScale(vector2(2.0f, 2.0f));
        obtr->SetPosition(vector2(576.0f, 144.0f));

        //Cafe Pressed
        Texture* Cafe_Pressed = JSHResourcemng::Load<Texture>(L"Cafe_Pressed"
            , L"..\\Resource\\GameSelect\\Press_OK.bmp");
        BackGround* cp = object::Instantiate<BackGround>(eLayerType::UI);
        SpriteRenderer* cpsr = cp->AddComponent<SpriteRenderer>();
        Transform* cptr = cp->GetComponent<Transform>();

        Animationmng* animationmng = AddComponent<Animationmng>();
        animationmng->CreateAnimation(L"OK_Button", OK_Button, vector2::Zero, vector2(30.0f, 26.0f), 1);
        animationmng->SetScale(vector2(2.0f, 2.0f));

        Texture* OK_Button1 = JSHResourcemng::Load<Texture>(L"Moai"
            , L"..\\Resource\\GameSelect\\Press_OK.bmp");

        Texture* OK_Button2 = JSHResourcemng::Load<Texture>(L"GleeClub"
            , L"..\\Resource\\GameSelect\\Press_OK.bmp");

        Texture* OK_Button3 = JSHResourcemng::Load<Texture>(L"BlueBirds"
            , L"..\\Resource\\GameSelect\\Press_OK.bmp");

        //Texture* Cafe_Pressed = JSHResourcemng::Load<Texture>(L"Cafe"
            //, L"..\\Resource\\GameSelect\\Press_OK.bmp");

        mAnimationmng = AddComponent<Animationmng>();
        mAnimationmng->CreateAnimation(L"Moai", OK_Button1, vector2::Zero, vector2(30.0f, 26.0f), 1);
        mAnimationmng->CreateAnimation(L"GleeClub", OK_Button2, vector2::Zero, vector2(30.0f, 26.0f), 1);
        mAnimationmng->CreateAnimation(L"BlueBirds", OK_Button3, vector2::Zero, vector2(30.0f, 26.0f), 1);
        mAnimationmng->CreateAnimation(L"OK", OK_Button, vector2::Zero, vector2(30.0f, 26.0f), 1);
        mAnimationmng->CreateAnimation(L"Cafe", OK_Button, vector2::Zero, vector2(30.0f, 26.0f), 1);
        mAnimationmng->SetScale(vector2(2.0f, 2.0f));

        //if (mType == eIcontype::Moai)
        //{
        //    mAnimationmng->PlayAnimation(L"Moai");
        //}
    }
    void Icon::Update()
    {
        GameObject::Update();
    }
    void Icon::Render(HDC hdc)
    {
        GameObject::Render(hdc);
    }

    void Icon::OncollisionEnter()
    {
    }

    void Icon::OncollisionExit()
    {
    }
}