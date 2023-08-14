#pragma once
#include "include.h"

namespace JSH
{
	class Entity
	{
	public:
		Entity();
		virtual ~Entity();

		void SetName(const wstring& name)
		{
			mName = name;
		}

		wstring& GetName()
		{
			return mName;
		}

	private:
		wstring mName;
	};
}