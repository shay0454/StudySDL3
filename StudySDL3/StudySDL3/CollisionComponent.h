#pragma once
#include"Component.h"
#include"Vector2.h"

class CollisionComponent : public Component {
	public:
		// MoveComponent보다 UpdateOrder값이 낮아 먼저 실행
		CollisionComponent(class Actor* owner, int UpdateOrder = 30);

		// 박스형 충돌 처리, 충돌 시 true 반환
		bool Intersect(const CollisionComponent& other) const;

		void SetCollisionSize(Vector2 size) { mCollisionSize = size; }
		Vector2 GetCollisionSize() const { return mCollisionSize; }

	private:
		Vector2 mCollisionSize;	// 충돌 박스 (중심 기준으로 절반 범위)
};
