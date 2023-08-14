#pragma once
#include "Include.h"
#include "Scene.h"

namespace JSH
{
	using namespace math;

	class game
	{
	public:
		game();
		~game();

		void Initialise(HWND hwnd);
		void Run();
		void Update();
		void Render();
        void Release();

        HWND GetHWND()
        {
            return mHWND;
        }
        HDC GetHDC()
        {
            return mHDC;
        }

	private:
		HWND mHWND;
		HDC mHDC;
		UINT mWidth;
		UINT mHeight;

		HDC mBackHDC; //create�� ��Ʈ�ʿ��� �����ϴ� HDC
		HBITMAP mBackBuffer;
	};
}