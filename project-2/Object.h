#pragma once
#include "Scene.h"
#include "GameObject.h"
#include "SceneManager.h"

namespace JSH::object
{
    template<typename T>
    static __forceinline T* Instantiate(eLayerType type)
    {
        T* gameobject = new T();
        gameobject->Initialize(); // GameObject���� Initialize�� ���� �ҷ����ش�.
        Scene* scene = SceneManager::GetActiveScene();
        scene->AddGameObject(type, gameobject);

        return gameobject;
    }
}