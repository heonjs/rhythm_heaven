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
        gameobject->Initialize(); // GameObject에서 Initialize를 같이 불러와준다.
        Scene* scene = SceneManager::GetActiveScene();
        scene->AddGameObject(type, gameobject);

        return gameobject;
    }
}