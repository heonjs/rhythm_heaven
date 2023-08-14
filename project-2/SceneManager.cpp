#include "SceneManager.h"
#include "TitleScene.h"
#include "SelectScene.h"
#include "JSHinput.h"
#include "GleeClub.h"
#include "GleeClubTitle.h"
#include "GleeClubEnd.h"
#include "MoaiTitle.h"
#include "Moai.h"
#include "MoaiEnd.h"
#include "BlueBirdsTitle.h"
#include "BlueBirds.h"
#include "BlueBirdsEnd.h"
#include "Cafe.h"

namespace JSH
{
    map<wstring, Scene*> SceneManager::mScenes = {};
    Scene* SceneManager::mActiveScene = nullptr;

    void SceneManager::Initialize()
    {
        CreateScene<TitleScene>(L"TitleScene");
        CreateScene<SelectScene>(L"SelectScene");
        CreateScene<GleeClubTitle>(L"GleeClubTitle");
        CreateScene<GleeClub>(L"GleeClub");
        CreateScene<GleeClubEnd>(L"GleeClubEnd");
        CreateScene<MoaiTitle>(L"MoaiTitle");
        CreateScene<Moai>(L"Moai");
        CreateScene<MoaiEnd>(L"MoaiEnd");
        CreateScene<BlueBirdsTitle>(L"BlueBirdsTitle");
        CreateScene<BlueBirds>(L"BlueBirds");
        CreateScene<BlueBirdsEnd>(L"BlueBirdsEnd");
        CreateScene<Cafe>(L"Cafe");
        
        LoadScene(L"TitleScene");
    }

    void SceneManager::Update()
    {
        mActiveScene->Update();
    }

    void SceneManager::Render(HDC hdc)
    {
        mActiveScene->Render(hdc);
    }

    void SceneManager::Release()
    {
        for (auto iter : mScenes)
        {
            delete iter.second;
            iter.second = nullptr;
        }
    }

    Scene* SceneManager::LoadScene(const wstring& name)
    {
        mActiveScene->Exit();

        map<wstring, Scene*>::iterator iter = mScenes.find(name);
        
        if (iter == mScenes.end())
        {
            return nullptr;
        }

        mActiveScene = iter->second;
        mActiveScene->Enter();

        return iter->second;
    }
}