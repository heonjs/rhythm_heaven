#pragma once
#include "include.h"

namespace JSH
{
    using namespace math;
	enum class eKeyCode
	{
		Q, W, E, R, T, Y, U, I, O, P,
		A, S, D, F, G, H, J, K, L,
		Z, X, C, V, B, N, M, space,
        Lbutton, Rbutton,
		End
	};
	enum class eKeyState
	{
		Down,
		Up,
		Pressed,
		None
	};

	class input
	{
	public:
		struct Key
		{
			eKeyCode Code;
			eKeyState State;
			bool bPressed;
		};

		static void Initailize();
		static void Update();

		__forceinline static bool GetKeyDown(eKeyCode code)
		{
			return mKeys[(int)code].State == eKeyState::Down;
		}
		__forceinline static bool GetKeyUp(eKeyCode code)
		{
			return mKeys[(int)code].State == eKeyState::Up;
		}
		__forceinline static bool GetKey(eKeyCode code)
		{
			return mKeys[(int)code].State == eKeyState::Pressed;
		}
        __forceinline static bool GetKeyNone(eKeyCode code)
        {
            return mKeys[(int)code].State == eKeyState::None;
        }

        static vector2 GetMousepos()
        {
            return mMousePos;
        }

	private:
		static vector<Key> mKeys;
        static vector2 mMousePos;
        static vector2 PrevMousePos;
        static float mTime;
        static float PrevTime;	
    };
}