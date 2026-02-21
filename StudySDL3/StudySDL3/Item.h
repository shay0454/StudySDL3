#pragma once
#include"Actor.h"

class Item : public Actor {
	public:
		Item(class Game* game);
		~Item();

		void OnCollision(Actor* other) override;

	private:
		class DrawComponent* mDC;		// 렌더링 컴포넌트
		class CollisionComponent* mCC;	// 충돌 처리 컴포넌트

};