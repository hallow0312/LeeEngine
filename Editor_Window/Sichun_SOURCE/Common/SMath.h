#pragma once
#include"cmath"
namespace Sichun::math
{
	struct Vector2
	{
		static Vector2 One;
		static Vector2 Zero;

		float x;
		float y;

		Vector2()
			: x(0.0f)
			, y(0.0f)
		{

		}

		Vector2(float _x, float _y)
			: x(_x)
			, y(_y)
		{

		}
		float Magnitude() const
		{
			return std::sqrt(x * x + y * y);
		}

		void Normalize()
		{
			float mag = Magnitude();
			if (mag > 0.00001f)
			{
				x /= mag;
				y /= mag;
			}
		}
		Vector2 operator+(Vector2 other)
		{
			return Vector2(x + other.x, y + other.y);
		}
		Vector2 operator-(Vector2 other)
		{
			return Vector2(x - other.x, y - other.y);
		}
		Vector2 operator/(int other)
		{
			return Vector2(x / other, y / other);
		}
		Vector2 operator*(Vector2 other)
		{
			return Vector2(x * other.x, y * other.y);
		}
		Vector2 operator*(float scalar)
		{
			return Vector2(x * scalar, y * scalar);
		}
		Vector2& operator+=(const Vector2& rhs) { x += rhs.x; y += rhs.y; return *this; }
		bool operator==(const Vector2& other) const
		{
			return x == other.x && y == other.y;
		}
	};

}

