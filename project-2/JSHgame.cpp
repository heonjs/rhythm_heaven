#include "JSHgame.h"
#include "JSHinput.h"
#include "Time.h"
#include "SceneManager.h"
#include "TitleScene.h"
#include "Soundmng.h"
#include "Collidermng.h"

namespace JSH
{
	game::game()
		: mHWND(NULL)
		, mHDC(NULL)
		,mWidth(0)
		,mHeight(0)
		,mBackBuffer(NULL)
		,mBackHDC(NULL)
	{
	}

	game::~game()
	{
	}

	void game::Initialize(HWND hwnd)
	{
		mHWND = hwnd;
		mHDC = GetDC(mHWND);
		mWidth = 768;
		mHeight = 576;

		//지정한 크기만한 사각형 생성
		RECT rect = { 0,0,mWidth,mHeight };
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		SetWindowPos(mHWND
			, nullptr, 0, 0
			, rect.right - rect.left
			, rect.bottom - rect.top
			, 0);
		ShowWindow(mHWND, true);

		//윈도우 해상도와 동일한 BitMap 생성
		mBackBuffer = CreateCompatibleBitmap(mHDC, mWidth, mHeight);

		//새로 생성한 BitMap을 가르키는 DC생성
		mBackHDC = CreateCompatibleDC(mHDC);

		//새로 생성한 BitMap과 DC를 서로 연결
		HBITMAP defaultBitmap
			= (HBITMAP)SelectObject(mBackHDC, mBackBuffer);

		//Initailize 할 때마다 생성한 비트맵을 삭제
		DeleteObject(defaultBitmap);

		Time::Initailize();
		input::Initailize();
        Soundmng::Initialize();
        SceneManager::Initialize();
        Collidermng::Initialize();
	}

	void game::Run()
	{
		Update();
		Render();
	}

	void game::Update()
	{
		Time::Update();
		input::Update();

        SceneManager::Update();
        Collidermng::Update();
	}

	void game::Render()
	{
		//create된 비트맵의 크기+1만큼 하얀색으로 지워준다
		Rectangle(mBackHDC, -1, -1, mWidth + 1, mHeight + 1);

		Time::Render(mBackHDC);

        SceneManager::Render(mBackHDC);
        Collidermng::Render(mBackHDC);

		//새 비트맵에서 원을 생성
		//mScene->Render(mBackHDC);

		//create된 비트맵을 기존 비트맵에 복사
		BitBlt(mHDC, 0, 0, mWidth, mHeight
			, mBackHDC, 0, 0, SRCCOPY);
	}
    void game::Release()
    {
    }
}