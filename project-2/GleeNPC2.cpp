#include "GleeNPC2.h"
#include "Transform.h"
#include "JSHinput.h"
#include "Time.h"
#include "Animationmng.h"
#include "Object.h"
#include "GleePlayer.h"
#include "JSHResourcemng.h"
#include "Texture.h"
#include "Sound.h"

namespace JSH
{
    float GleeNPC2::mPlayTime = 0.0f;
    float GleeNPC2::miTime = 0.0f;

    GleeNPC2::GleeNPC2()
    {
    }
    GleeNPC2::~GleeNPC2()
    {
    }
    void GleeNPC2::Initialize()
    {
        GameObject::Initialize();

        Animationmng* gn2 = AddComponent<Animationmng>();
        gn2->SetScale(vector2(2.0f, 2.0f));

        //Glee NPC2 Sound
        JSHResourcemng::Load<Sound>(L"NPC2_Idle", L"..\\Resource\\sound\\Glee_Club\\NPC_2_Idle.wav");

        //NPC2 AH Sound
        JSHResourcemng::Load<Sound>(L"NPC2_AH", L"..\\Resource\\sound\\Glee_Club\\Glee_AH.wav");

        //Glee Idle
        Texture* Gleeidle = JSHResourcemng::Load<Texture>(L"Gleeidle", L"..\\Resource\\Ingame\\Glee_Club\\Glee_Idle.bmp");
        gn2->CreateAnimation(L"Gleeidle", Gleeidle, vector2(0.0f, 0.0f), vector2(48.0f, 72.0f), 3);
        gn2->SetBmpRGB(L"Gleeidle", 151, 151, 151);

        //Glee normal
        Texture* Gleetouch = JSHResourcemng::Load<Texture>(L"Gleenormal", L"..\\Resource\\Ingame\\Glee_Club\\Glee_normal.bmp");
        gn2->CreateAnimation(L"Gleenormal", Gleetouch, vector2(0.0f, 0.0f), vector2(47.0f, 73.0f), 2);
        gn2->SetBmpRGB(L"Gleenormal", 151, 151, 151);

        //Glee Close Mouth
        Texture* Gleeclose = JSHResourcemng::Load<Texture>(L"Gleeclose", L"..\\Resource\\Ingame\\Glee_Club\\Glee_Close.bmp");
        gn2->CreateAnimation(L"Gleeclose", Gleeclose, vector2(0.0f, 0.0f), vector2(48.0f, 72.0f), 3, vector2(0.0f, 0.0f), 0.05f);
        gn2->SetBmpRGB(L"Gleeclose", 151, 151, 151);

        //Glee Open Mouth
        gn2->CreateAnimationFolder(L"Gleeopen", L"..\\Resource\\Ingame\\Glee_Club\\Glee_Open", vector2(0.0f, 0.0f), 0.05f);
        gn2->SetBmpRGB(L"Gleeopen", 151, 151, 151);

        //Glee AH
        Texture* GleeAH = JSHResourcemng::Load<Texture>(L"GleeAH", L"..\\Resource\\Ingame\\Glee_Club\\Glee_AH.bmp");
        gn2->CreateAnimation(L"GleeAH", GleeAH, vector2(0.0f, 0.0f), vector2(52.5f, 82.0f), 8, vector2::Zero, 0.05f);
        gn2->SetBmpRGB(L"GleeAH", 151, 151, 151);

        //Glee Fail
        Texture* Gleefail = JSHResourcemng::Load<Texture>(L"Gleefail", L"..\\Resource\\Ingame\\Glee_Club\\Glee_fail.bmp");
        gn2->CreateAnimation(L"Gleefail", Gleefail, vector2(0.0f, 0.0f), vector2(48.0f, 72.0f), 3);
        gn2->SetBmpRGB(L"Gleefail", 151, 151, 151);

        gn2->PlayAnimation(L"Gleenormal", true);
    }
    void GleeNPC2::Update()
    {
        GameObject::Update();

        mPlayTime += Time::DeltaTime();
        miTime = floor(mPlayTime * 100) / 100;

        //Pattern 1
        if (miTime == 13.4f)
        {
            Opening();
        }
        if (miTime == 13.5f)
        {
            Idle();
        }
        if (miTime == 14.1f)
        {
            Closing();
        }
        if (miTime == 14.2f)
        {
            Touch();
        }

        //Pattern 2
        if (miTime == 21.1f)
        {
            Opening();
        }
        if (miTime == 21.2f)
        {
            Idle();
        }
        if (miTime == 21.8f)
        {
            Closing();
        }
        if (miTime == 21.9f)
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
        if (miTime == 28.9f)
        {
            Opening();
        }
        if (miTime == 29.0f)
        {
            Idle();
        }
        if (miTime == 29.6f)
        {
            Closing();
        }
        if (miTime == 29.7f)
        {
            Touch();
        }

        //Pattern 4
        if (miTime == 36.7f)
        {
            Opening();
        }
        if (miTime == 36.8f)
        {
            Idle();
        }
        if (miTime == 37.4f)
        {
            Closing();
        }
        if (miTime == 37.5f)
        {
            Touch();
        }

        //Pattern 5
        if (miTime == 40.6f)
        {
            Opening();
        }
        if (miTime == 40.7f)
        {
            Idle();
        }
        if (miTime == 41.9f)
        {
            Closing();
        }
        if (miTime == 42.0f)
        {
            Touch();
        }
    }
    void GleeNPC2::Render(HDC hdc)
    {
        GameObject::Render(hdc);
    }

    void GleeNPC2::Idle()
    {
        Animationmng* animationmng = GetComponent<Animationmng>();
        animationmng->FindAnimation(L"Gleeidle");
        Sound* sound = JSHResourcemng::Find<Sound>(L"NPC2_Idle");

        animationmng->PlayAnimation(L"Gleeidle", true);
        sound->Play(true);
    }
    void GleeNPC2::Touch()
    {
        Animationmng* animationmng = GetComponent<Animationmng>();
        animationmng->FindAnimation(L"Gleenormal");

        animationmng->PlayAnimation(L"Gleenormal", true);
    }
    void GleeNPC2::Closing()
    {
        Animationmng* animationmng = GetComponent<Animationmng>();
        animationmng->FindAnimation(L"Gleeclose");
        Sound* sound = JSHResourcemng::Find<Sound>(L"NPC2_Idle");

        animationmng->PlayAnimation(L"Gleeclose", false);
        sound->Stop(true);
    }
    void GleeNPC2::Opening()
    {
        Animationmng* animationmng = GetComponent<Animationmng>();
        animationmng->FindAnimation(L"Gleeopen");

        animationmng->PlayAnimation(L"Gleeopen", false);
    }
    void GleeNPC2::AH()
    {
        Animationmng* animationmng = GetComponent<Animationmng>();
        animationmng->FindAnimation(L"GleeAH");
        Sound* sound = JSHResourcemng::Find<Sound>(L"NPC2_AH");

        animationmng->PlayAnimation(L"GleeAH", false);
        sound->Play(false);
    }
    void GleeNPC2::Fail()
    {
        Animationmng* animationmng = GetComponent<Animationmng>();
    }
}