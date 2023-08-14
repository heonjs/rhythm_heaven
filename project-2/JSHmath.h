#pragma once
#include <cmath>

namespace JSH::math
{
#define PI = 3.141592;

	struct vector2
	{
        static vector2 Zero;
        static vector2 One;
        static vector2 Right;
        static vector2 Up;

		float x;
		float y;

		vector2()
			: x(0.0f)
			, y(0.0f)
		{
		}

        vector2(float _x, float _y)
            : x(_x)
            , y(_y)
        {
        }

        vector2 operator+(const vector2 other)
        {
            vector2 temp;
            temp.x = x + other.x;
            temp.y = y + other.y;
            return temp;
        }

        vector2 operator-(const vector2 other)
        {
            vector2 temp;
            temp.x = x - other.x;
            temp.y = y - other.y;
            return temp;
        }

        vector2 operator/(const float value)
        {
            vector2 temp;
            temp.x = x / value;
            temp.y = y / value;
            return temp;
        }
	};
}