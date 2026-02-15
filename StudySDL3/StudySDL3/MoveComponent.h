#pragma once
#include"Component.h"
#include"Vector2.h"

// 설정된 방향에 속력을 붙여 이동시킵니다.
class MoveComponent : public Component {
public:
	MoveComponent(class Actor* owner, float speed = 200.f);	// speed : 초당 이동 거리

	void Update(float deltaTime) override;					// 위치 갱신

	void SetSpeed(float speed) { mSpeed = speed; }			// 초당 이동 거리 설정
	float GetSpeed() const { return mSpeed; }

	void SetDirection(const Vector2& dir);					// 이동 방향 설정

	Vector2 GetVelocity() const { return mVelocity; }

private:
	float mSpeed;											// 초당 이동 속력
	Vector2 mVelocity;										// 초당 이동 벡터 (방향 * Speed)
};
