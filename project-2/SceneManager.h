#pragma once
#include "Scene.h"

namespace JSH
{
    class SceneManager
    {
    public:
        static void Initialize();
        static void Update();
        static void Render(HDC hdc);
        static void Release();

        template<typename T>
        static T* CreateScene(const wstring& name)
        {
            T* scene = new T();
            scene->SetName(name);
            mScenes.insert(make_pair(name, scene));
            mActiveScene = scene;
            scene->Initialize();

            return scene;
        }

        static Scene* LoadScene(const wstring& name);
        static Scene* GetActiveScene()
        {
            return mActiveScene;
        }

    private:
        //트리(map) 자료구조 : 배열보다 처리속도가 빠르다.
        static map<wstring, Scene*> mScenes;
        static Scene* mActiveScene;
        // wstrind == key, Scene* == value
        // key는 데이터를 검색
        // value는 실제 사용해야하는 데이터
    };
}