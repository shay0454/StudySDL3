#include"CollisionComponent.h"
#include"Actor.h"
#include"Vector2.h"

// 크기를 액터한테 받아 충돌 범위를 설정합니다. 
// 이를 위해 액터의 크기를 설정 후 CollisionComponent를 추가해야함
CollisionComponent::CollisionComponent(Actor* owner, int TopdateOrder) 
	:Component(owner,TopdateOrder),mCollisionSize(this->GetOwner()->GetSize()){}

bool CollisionComponent::Intersect(const CollisionComponent& other) const {
	Actor* A = this->GetOwner();
	float AScale = A->GetScale();
	Vector2 ASize = mCollisionSize;
	
	Actor* B = other.GetOwner();
	float BScale = B->GetScale();
	Vector2 BSize = other.mCollisionSize;

	// 위치가 중앙을 기준이므로 각 방향으로 크기의 절반만큼 확장
	float ARight = A->GetPosition().x + ASize.x / 2 * AScale;
	float ALeft = A->GetPosition().x - ASize.x / 2 * AScale;
	float ATop = A->GetPosition().y - ASize.y / 2 * AScale;
	float ABottom = A->GetPosition().y + ASize.y / 2 * AScale;

	float BRight = B->GetPosition().x + BSize.x / 2 * BScale;
	float BLeft = B->GetPosition().x - BSize.x / 2 * BScale;
	float BTop = B->GetPosition().y - BSize.y / 2 * BScale;
	float BBottom = B->GetPosition().y + BSize.y / 2 * BScale;

	// y축이 아래로 증가 ( Top < Bottom )
	return (
		ALeft < BRight &&
		ARight > BLeft &&
		ABottom > BTop &&	
		ATop < BBottom
	);
}