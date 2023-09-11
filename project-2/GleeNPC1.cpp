#include "GleeNPC1.h"
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
    float GleeNPC1::mPlayTime = 0.0f;
    float GleeNPC1::miTime = 0.0f;

    GleeNPC1::GleeNPC1()
    {
    }
    GleeNPC1::~GleeNPC1()
    {
    }
    void GleeNPC1::Initialize()
    {
        GameObject::Initialize();

        Animationmng* gn1 = AddComponent<Animationmng>();
        gn1->SetScale(vector2(2.0f, 2.0f));

        //Glee NPC2 Sound
        JSHResourcemng::Load<Sound>(L"NPC1_Idle", L"..\\Resource\\sound\\Glee_Club\\NPC_1_Idle.wav");

        //NPC1 AH Sound
        JSHResourcemng::Load<Sound>(L"NPC1_AH", L"..\\Resource\\sound\\Glee_Club\\Glee_AH.wav");

        //Glee Idle
        Texture* Gleeidle = JSHResourcemng::Load<Texture>(L"Gleeidle", L"..\\Resource\\Ingame\\Glee_Club\\Glee_Idle.bmp");
        gn1->CreateAnimation(L"Gleeidle", Gleeidle, vector2(0.0f, 0.0f), vector2(48.0f, 72.0f), 3);
        gn1->SetBmpRGB(L"Gleeidle", 151, 151, 151);

        //Glee normal
        Texture* Gleetouch = JSHResourcemng::Load<Texture>(L"Gleenormal", L"..\\Resource\\Ingame\\Glee_Club\\Glee_normal.bmp");
        gn1->CreateAnimation(L"Gleenormal", Gleetouch, vector2(0.0f, 0.0f), vector2(47.0f, 73.0f), 2);
        gn1->SetBmpRGB(L"Gleenormal", 151, 151, 151);

        //Glee Close Mouth
        Texture* Gleeclose = JSHResourcemng::Load<Texture>(L"Gleeclose", L"..\\Resource\\Ingame\\Glee_Club\\Glee_Close.bmp");
        gn1->CreateAnimation(L"Gleeclose", Gleeclose, vector2(0.0f, 0.0f), vector2(48.0f, 72.0f), 3, vector2(0.0f, 0.0f), 0.05f);
        gn1->SetBmpRGB(L"Gleeclose", 151, 151, 151);

        //Glee Open Mouth
        gn1->CreateAnimationFolder(L"Gleeopen", L"..\\Resource\\Ingame\\Glee_Club\\Glee_Open", vector2(0.0f, 0.0f), 0.05f);
        gn1->SetBmpRGB(L"Gleeopen", 151, 151, 151);

        //Glee AH
        Texture* GleeAH = JSHResourcemng::Load<Texture>(L"GleeAH", L"..\\Resource\\Ingame\\Glee_Club\\Glee_AH.bmp");
        gn1->CreateAnimation(L"GleeAH", GleeAH, vector2(0.0f, 0.0f), vector2(52.5f, 82.0f), 8, vector2::Zero, 0.05f);
        gn1->SetBmpRGB(L"GleeAH", 151, 151, 151);

        //Glee Fail
        Texture* Gleefail = JSHResourcemng::Load<Texture>(L"Gleefail", L"..\\Resource\\Ingame\\Glee_Club\\Glee_fail.bmp");
        gn1->CreateAnimation(L"Gleefail", Gleefail, vector2(0.0f, 0.0f), vector2(48.0f, 72.0f), 3);
        gn1->SetBmpRGB(L"Gleefail", 151, 151, 151);

        gn1->PlayAnimation(L"Gleenormal", true);
    }
    void GleeNPC1::Update()
    {
        GameObject::Update();

        mPlayTime += Time::DeltaTime();
        miTime = floor(mPlayTime * 100) / 100;

        //Pattern 1
        if (miTime == 12.5f)
        {
            Opening();
        }
        if (miTime == 12.6f)
        {
            Idle();
        }
        if (miTime == 13.2f)
        {
            Closing();
        }
        if (miTime == 13.3f)
        {
            Touch();
        }

        //Pattern 2
        if (miTime == 20.2f)
        {
            Opening();
        }
        if (miTime == 20.3f)
        {
            Idle();
        }
        if (miTime == 20.9f)
        {
            Closing();
        }
        if (miTime == 21.0f)
        {
            Touch();
        }
        if (miTime == 23.5f)
        {
            AH();
        }
        if (miTime == 23.8f)
        {
            Touch();
        }

        //Pattern 3
        if (miTime == 28.0f)
        {
            Opening();
        }
        if (miTime == 28.1f)
        {
            Idle();
        }
        if (miTime == 28.7f)
        {
            Closing();
        }
        if (miTime == 28.8f)
        {
            Touch();
        }

        //Pattern 4
        if (miTime == 35.7f)
        {
            Opening();
        }
        if (miTime == 35.8f)
        {
            Idle();
        }
        if (miTime == 36.5f)
        {
            Closing();
        }
        if (miTime == 36.6f)
        {
            Touch();
        }

        //Pattern 5
        if (miTime == 39.2f)
        {
            Opening();
        }
        if (miTime == 39.3f)
        {
            Idle();
        }
        if (miTime == 40.5f)
        {
            Closing();
        }
        if (miTime == 40.6f)
        {
            Touch();
        }
    }
    void GleeNPC1::Render(HDC hdc)
    {
        GameObject::Render(hdc);
    }

    void GleeNPC1::Idle()
    {
        Animationmng* animationmng = GetComponent<Animationmng>();
        animationmng->FindAnimation(L"Gleeidle");
        Sound* sound = JSHResourcemng::Find<Sound>(L"NPC1_Idle");

        animationmng->PlayAnimation(L"Gleeidle", true);
        sound->Play(true);
    }
    void GleeNPC1::Touch()
    {
        Animationmng* animationmng = GetComponent<Animationmng>();
        animationmng->FindAnimation(L"Gleenormal");

        animationmng->PlayAnimation(L"Gleenormal", true);
    }
    void GleeNPC1::Closing()
    {
        Animationmng* animationmng = GetComponent<Animationmng>();
        animationmng->FindAnimation(L"Gleeclose");
        Sound* sound = JSHResourcemng::Find<Sound>(L"NPC1_Idle");

        animationmng->PlayAnimation(L"Gleeclose", false);
        sound->Stop(true);
    }
    void GleeNPC1::Opening()
    {
        Animationmng* animationmng = GetComponent<Animationmng>();
        animationmng->FindAnimation(L"Gleeopen");

        animationmng->PlayAnimation(L"Gleeopen", false);
    }
    void GleeNPC1::AH()
    {
        Animationmng* animationmng = GetComponent<Animationmng>();
        animationmng->FindAnimation(L"GleeAH");
        Sound* sound = JSHResourcemng::Find<Sound>(L"NPC1_AH");

        animationmng->PlayAnimation(L"GleeAH", false);
        sound->Play(false);
    }
    void GleeNPC1::Fail()
    {
        Animationmng* animationmng = GetComponent<Animationmng>();
    }
}