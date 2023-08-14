#include "GameObject.h"
#include "Transform.h"
#include "SpriteRenderer.h"

namespace JSH
{
	GameObject::GameObject()
	{
        AddComponent<Transform>();
	}
	GameObject::~GameObject()
	{
        for (Component* comp : mComponents)
        {
            delete comp;
            comp = nullptr;
        }
	}
	void GameObject::Initialize()
	{
	}
	void GameObject::Update()
	{
		for (Component* comp : mComponents)
		{
			comp->Update();
		}
	}
	void GameObject::Render(HDC hdc)
	{
		for (Component* comp : mComponents)
		{
			comp->Render(hdc);
		}
	}
    void GameObject::OnColliderEnter(Collider* other)
    {
    }
    void GameObject::OnColliderStay(Collider* other)
    {
    }
    void GameObject::OnColliderExit(Collider* other)
    {
    }
}