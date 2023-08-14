#pragma once
#include "Entity.h"
#include "GameObject.h"

namespace JSH
{
	class Layer : public Entity
	{
	public:
		Layer();
		virtual ~Layer();

		virtual void Initialize();
		virtual void Update();
		virtual void Render(HDC hdc);

		void AddGameObject(GameObject* gameobj)
		{
			mGameObjects.push_back(gameobj);
		}
        vector<GameObject*>& GetGameObjects()
        { 
            return mGameObjects;
        }

	private:
		vector<GameObject*> mGameObjects;
	};

}