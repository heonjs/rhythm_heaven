#include "Scene.h"
#include "SpriteRenderer.h"

namespace JSH
{
	Scene::Scene()
	{
		mLayers.resize((int)eLayerType::End);
	}

	Scene::~Scene()
	{
	}

	void Scene::Initialize()
	{
		
	}

	void Scene::Update()
	{
		for (Layer& layer : mLayers)
		{
			layer.Update();
		}
	}

	void Scene::Render(HDC hdc)
	{
		for (Layer& layer : mLayers)
		{
			layer.Render(hdc);
		}
	}
}