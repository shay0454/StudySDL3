#pragma once
class Vector2 {
	public:
		Vector2(float inX = 0, float inY = 0) :x(inX), y(inY) {}

	public:
		float x, y;

	public:
		// º¤ÅÍ ÇÕ (a + b)
		friend Vector2 operator+(const Vector2& a,const Vector2& b) {
			return Vector2(a.x + b.x, a.y + b.y);
		}

		// º¤ÅÍ Â÷ (a - b)
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
			this->x += other.y;
			this->y += other.y;
			return *this;
		}

		Vector2 operator-=(const Vector2 other) {
			this->x -= other.y;
			this->y -= other.y;
			return *this;
		}

		Vector2 operator*=(float scalar) {
			this->x *= scalar;
			this->y *= scalar;
			return *this;
		}

};