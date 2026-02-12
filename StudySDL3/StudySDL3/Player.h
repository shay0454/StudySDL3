#pragma once
#include"Actor.h"

class Player :public Actor {
	public:
		Player(class Game* game);
		void UpdateActor(float deltaTime) override;

	private:
		class InputComponent* mIC;	// 입력 처리 컴포넌트
		class DrawComponent* mDC;	// 렌더링 컴포넌트
};
