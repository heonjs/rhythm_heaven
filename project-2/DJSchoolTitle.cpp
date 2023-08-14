#include "DJSchoolTitle.h"
#include "SpriteRenderer.h"
#include "Object.h"
#include "JSHinput.h"
#include "Texture.h"
#include "JSHResourcemng.h"
#include "BackGround.h"
#include "Transform.h"
#include "Time.h"

namespace JSH
{
    DJSchoolTitle::DJSchoolTitle()
    {
    }
    DJSchoolTitle::~DJSchoolTitle()
    {
    }
    void DJSchoolTitle::Initialize()
    {
        // DJ School Title
        Texture* texture1 = JSHResourcemng::Load<Texture>(L"Left DJ"
            , L"..\\Resource\\Ingame\\DJSchool\\Title_Dj_School.bmp");
       
        BackGround* dj1 = object::Instantiate<BackGround>(eLayerType::Ingame);
        SpriteRenderer* dj1sr = dj1->AddComponent<SpriteRenderer>();
        Transform* dj1tr = dj1->GetComponent<Transform>();
        dj1tr->SetPosition(vector2(192.0f, 288.0f));
        dj1sr->SetTexture(texture1);
        dj1sr->SetScale(vector2(2.0f, 2.25f));

        // Dj School TouchScreen
        Texture* texture2 = JSHResourcemng::Load<Texture>(L"Right DJ"
            , L"..\\Resource\\Ingame\\Loading.bmp");

        BackGround* dj2 = object::Instantiate<BackGround>(eLayerType::TouchScreen);
        SpriteRenderer* dj2sr = dj2->AddComponent<SpriteRenderer>();
        Transform* dj2tr = dj2->GetComponent<Transform>();
        dj2tr->SetPosition(vector2(576.0f, 288.0f));
        dj2sr->SetTexture(texture2);
        dj2sr->SetScale(vector2(2.0f, 2.25f));
    }
    void DJSchoolTitle::Update()
    {
        static float mTime = 0.0f;
        mTime += Time::DeltaTime();
        if (mTime >= 2.0f)
        {
            mTime = 0.0f;
            SceneManager::LoadScene(L"DJSchool");
        }
        
        Scene::Update();
    }
    void DJSchoolTitle::Render(HDC hdc)
    {
        Scene::Render(hdc);
    }
}