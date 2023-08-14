#include "Layer.h"

namespace JSH
{
	Layer::Layer()
	{
	}
	Layer::~Layer()
	{
        for (GameObject* obj : mGameObjects)
        {
            delete obj;
            obj = nullptr;
        }
	}
	void Layer::Initialize()
	{
	}
	void Layer::Update()
	{
		for (GameObject* obj : mGameObjects)
		{
			obj->Update();
		}
	}
	void Layer::Render(HDC hdc)
	{
		for (GameObject* obj : mGameObjects)
		{
			obj->Render(hdc);
		}
	}
}