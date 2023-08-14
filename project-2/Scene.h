#pragma once
#include "Entity.h"
#include "Layer.h"

namespace JSH
{
	using namespace JSH::enums;
	class Scene : public Entity
	{
	public:
		Scene();
		virtual ~Scene();

		virtual void Initialize();
		virtual void Update();
		virtual void Render(HDC hdc);

        void AddGameObject(eLayerType type, GameObject* gameobj)
        {
            mLayers[(int)type].AddGameObject(gameobj);
        }

        Layer& GetLayer(eLayerType type)
        {
            return mLayers[(UINT)type];
        }

        virtual void Enter() = 0;
        virtual void Exit() = 0;

	private:
		vector<Layer> mLayers;
	};
}