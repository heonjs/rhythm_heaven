#include "GleeTeacher.h"
#include "Transform.h"
#include "JSHinput.h"
#include "Time.h"
#include "Animationmng.h"
#include "JSHResourcemng.h"
#include "Object.h"
#include "Texture.h"
#include "Sound.h"

namespace JSH
{
    GleeTeacher::GleeTeacher()
    {
    }
    GleeTeacher::~GleeTeacher()
    {
    }
    void GleeTeacher::Initialize()
    {
        GameObject::Initialize();
        
        Animationmng* animationmng = AddComponent<Animationmng>();
        animationmng->SetScale(vector2(2.0f, 2.0f));

        //Glee Teacher Animation
        Texture* gt = JSHResourcemng::Load<Texture>(L"gleeteacher", L"..\\\Resource\\Ingame\\Glee_Club\\Glee_Teacher.bmp");
        animationmng->CreateAnimation(L"teacher", gt, vector2::Zero, vector2(73.0f, 98.0f), 3);
        animationmng->SetBmpRGB(L"teacher", 151, 151, 151);

        //Together Now Sound
        JSHResourcemng::Load<Sound>(L"TGN", L"..\\Resource\\sound\\Glee_Club\\TogetherNow.wav");

        animationmng->PlayAnimation(L"teacher", true);
    }
    void GleeTeacher::Update()
    {
        GameObject::Update();
    }
    void GleeTeacher::Render(HDC hdc)
    {
        GameObject::Render(hdc);
    }
}