#pragma once
#include"cmath"
namespace Sichun::math
{
#define  PI  3.141592f
	struct Vector2
	{
		static Vector2 One;
		static Vector2 Zero;
		static Vector2 Forward;
		static Vector2 Backward;
		static Vector2 Right;
		static Vector2  Left;
		float x;
		float y;
		Vector2 Rotate(float degree) const
		{
			float radian = (degree / 180.0f) * PI;
			Vector2 normalized = this->Normalize();
			float x = cosf(radian) * normalized.x - sinf(radian) * normalized.y;
			float y = sinf(radian) * normalized.x + cosf(radian) * normalized.y;
			return Vector2(x, y);
		}
		Vector2 Normalize() const
		{
			float mag = Length();
			if (mag > 0.00001f)
			{
				return Vector2(x / mag, y / mag);
			}
			return Vector2(0, 0);
		}
		float Dot(const Vector2& other) const
		{
			return x * other.x + y * other.y;
		}

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
		void Clear()
		{
			x = 0.0f, y = 0.0f;
		}

		float Length() const
		{
			return std::sqrt(x * x + y * y);
		}
		
		float Cross(Vector2 &v)
		{
			return x * v.y - y * v.x;
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
		Vector2 operator/(float scalar)
		{
			return Vector2(x / scalar, y / scalar);
		}

		Vector2 operator*(Vector2 other)
		{
			return Vector2(x * other.x, y * other.y);
		}
		Vector2 operator*(float scalar)
		{
			return Vector2(x * scalar, y * scalar);
		}
		Vector2& operator*=(float scalar) { x *= scalar; y *= scalar; return *this; }
		Vector2& operator+=(const Vector2& rhs) { x += rhs.x; y += rhs.y; return *this; }
		bool operator==(const Vector2& other) const
		{
			return x == other.x && y == other.y;
		}
		Vector2 operator-() const
		{
			return Vector2(-x, -y);
		}
	};


}

