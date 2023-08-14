#pragma once
#include "Component.h"

namespace JSH
{
	using namespace math;

	class Transform : public Component
	{
	public:
		Transform();
		virtual ~Transform();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;

		void SetPosition(vector2 position)
		{
			mPosition = position;
		}

		vector2 GetPosition()
		{
			return mPosition;
		}

	private:
		vector2 mPosition;
	};
}