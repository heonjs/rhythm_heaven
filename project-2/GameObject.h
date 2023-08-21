#pragma once
#include "Entity.h"
#include "Component.h"

namespace JSH
{
	class GameObject : public Entity
	{
	public:
		GameObject();
		virtual ~GameObject();

		virtual void Initialize();
		virtual void Update();
        virtual void Render(HDC hdc);

        template <typename T>
        T* GetComponent()
        {
            T* comp = nullptr;
            for (Component* c : mComponents)
            {
                // 자식타입과 T타입이 일치한다면
                // 주소를 반환 그렇지않다면 nullptr 반환
                comp = dynamic_cast<T*>(c);
                if (comp != nullptr)
                {
                    return comp;
                }
            }

            return comp;
        }

        template <typename T>
        T* AddComponent()
        {
            T* comp = new T();
            mComponents.push_back(comp);
            comp->SetOwner(this);

            return comp;
        }

        virtual void OnColliderEnter(class Collider* other);
        virtual void OnColliderStay(class Collider* other);
        virtual void OnColliderExit(class Collider* other);

        void SetLayerType(eLayerType LayerType) { mLayerType = LayerType; }
        eLayerType GetLayerType() { return mLayerType; }


	private:
		vector<Component*> mComponents;
        eLayerType mLayerType;
	};
}