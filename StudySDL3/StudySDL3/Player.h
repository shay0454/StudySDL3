#pragma once
#include"Actor.h"

class Player :public Actor {
	public:
		Player(class Game* game);
		~Player();

		void UpdateActor(float deltaTime) override;

		void OnCollision(Actor* other) override;

	private:
		class InputComponent* mIC;		// 입력 처리 컴포넌트
		class MoveComponent* mMC;		// 이동 처리 컴포넌트
		class DrawComponent* mDC;		// 렌더링 컴포넌트
		class CollisionComponent* mCC;	// 충돌 처리 컴포넌트
};
