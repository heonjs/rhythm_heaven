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
        //Ʈ��(map) �ڷᱸ�� : �迭���� ó���ӵ��� ������.
        static map<wstring, Scene*> mScenes;
        static Scene* mActiveScene;
        // wstrind == key, Scene* == value
        // key�� �����͸� �˻�
        // value�� ���� ����ؾ��ϴ� ������
    };
}