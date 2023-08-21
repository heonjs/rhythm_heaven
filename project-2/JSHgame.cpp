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

		//������ ũ�⸸�� �簢�� ����
		RECT rect = { 0,0,mWidth,mHeight };
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		SetWindowPos(mHWND
			, nullptr, 0, 0
			, rect.right - rect.left
			, rect.bottom - rect.top
			, 0);
		ShowWindow(mHWND, true);

		//������ �ػ󵵿� ������ BitMap ����
		mBackBuffer = CreateCompatibleBitmap(mHDC, mWidth, mHeight);

		//���� ������ BitMap�� ����Ű�� DC����
		mBackHDC = CreateCompatibleDC(mHDC);

		//���� ������ BitMap�� DC�� ���� ����
		HBITMAP defaultBitmap
			= (HBITMAP)SelectObject(mBackHDC, mBackBuffer);

		//Initailize �� ������ ������ ��Ʈ���� ����
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
		//create�� ��Ʈ���� ũ��+1��ŭ �Ͼ������ �����ش�
		Rectangle(mBackHDC, -1, -1, mWidth + 1, mHeight + 1);

		Time::Render(mBackHDC);

        SceneManager::Render(mBackHDC);
        Collidermng::Render(mBackHDC);

		//�� ��Ʈ�ʿ��� ���� ����
		//mScene->Render(mBackHDC);

		//create�� ��Ʈ���� ���� ��Ʈ�ʿ� ����
		BitBlt(mHDC, 0, 0, mWidth, mHeight
			, mBackHDC, 0, 0, SRCCOPY);
	}
    void game::Release()
    {
    }
}