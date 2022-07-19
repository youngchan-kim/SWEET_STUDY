#include <cmath>

#ifndef ENGINE_MATH_H
#define ENGINE_MATH_H

namespace ENGINE
{
	struct Vector2
	{
		float x, y;

		Vector2() : x(0), y(0) {}
		Vector2(float x, float y) : x(x), y(y) {}

		Vector2 operator-() const { /* ���� ���� �ϱ� */ }

		Vector2 operator*(const float& value) const { /* ���� ���� �ϱ� */ }
		Vector2 operator/(const float& value) const { /* ���� ���� �ϱ� */ }
		Vector2 operator*=(const float& value) { /* ���� ���� �ϱ� */ }
		Vector2 operator/=(const float& value) { /* ���� ���� �ϱ� */ }

		Vector2 operator+(const Vector2& v) const { /* ���� ���� �ϱ� */ }
		Vector2 operator-(const Vector2& v) const { /* ���� ���� �ϱ� */ }
		Vector2 operator+=(const Vector2& v) { /* ���� ���� �ϱ� */ }
		Vector2 operator-=(const Vector2& v) { /* ���� ���� �ϱ� */ }

	};

	inline bool operator== (const Vector2& lhs, const Vector2& rhs) { /* ���� ���� �ϱ� */ }
	inline bool operator!= (const Vector2& lhs, const Vector2& rhs) { /* ���� ���� �ϱ� */ }

	const float Epsilon = 0.0001f;

	inline bool Equal(float lhs, float rhs) { return (std::abs(lhs - rhs) <= Epsilon); }

#ifndef clamp
#define clamp(v, a, b) (a < b) ? min(max(v, a), b) : min(max(v, b), a)
#endif // !clamp

	int Repeat(int value, const int& max);
}

#endif // !ENGINE_MATH_H