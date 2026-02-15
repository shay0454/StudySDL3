#include"MoveComponent.h"
#include"Actor.h"

MoveComponent::MoveComponent(Actor* owner,float speed)
	:Component(owner,40),mVelocity(0,0),mSpeed(speed) {}

// 방향에 따른 속도를 설정합니다.
void MoveComponent::SetDirection(const Vector2& dir) {
	mVelocity = dir * mSpeed;
}

// 위치를 업데이트 합니다.
void MoveComponent::Update(float deltaTime) {
	GetOwner()->SetPosition(
		GetOwner()->GetPosition() + mVelocity * deltaTime
	); // deltaTime을 곱해 이번 프레임 이동량을 계산
}
