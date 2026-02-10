#pragma once
#include"Actor.h"

class Player :public Actor {
	public:
		Player(class Game* game);

	private:
		class InputComponent* mIC;	// 입력 처리 컴포넌트
};
