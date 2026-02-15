#pragma once
#include<cmath>
class Vector2 {
	public:
		Vector2(float inX = 0, float inY = 0) :x(inX), y(inY) {}

	public:
		float x, y;

	public:
		// 벡터 합 (a + b)
		friend Vector2 operator+(const Vector2& a,const Vector2& b) {
			return Vector2(a.x + b.x, a.y + b.y);
		}

		// 벡터 차 (a - b)
		friend Vector2 operator-(const Vector2& a,const Vector2& b) {
			return Vector2(a.x - b.x, a.y - b.y);
		}

		friend Vector2 operator*(const Vector2& a, const Vector2& b) {
			return Vector2(a.x * b.x, a.y * b.y);
		}

		friend Vector2 operator*(const Vector2& a, float scalar) {
			return Vector2(a.x * scalar, a.y * scalar);
		}

		friend Vector2 operator*(float scalar, const Vector2& a) {
			return Vector2(a.x * scalar, a.y * scalar);
		}

		Vector2 operator+=(const Vector2 other) {
			x += other.x;
			y += other.y;
			return *this;
		}

		Vector2 operator-=(const Vector2 other) {
			x -= other.x;
			y -= other.y;
			return *this;
		}

		Vector2 operator*=(float scalar) {
			x *= scalar;
			y *= scalar;
			return *this;
		}

		float LengthSq() const {
			return (x * x + y * y);
		}

		float Length() const {
			return sqrtf(LengthSq());
		}

		void Normalize() {
			float length = Length();
			if (length > 0.f) {
				x /= length;
				y /= length;
			}
		}


		// 클래스의 인스턴스 없이 호출하기 위해 static으로 설정
		static Vector2 Normalize(const Vector2& v) {
			Vector2 temp = v;
			temp.Normalize();
			return temp;
		}

};