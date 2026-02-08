#include"Component.h"
#include"Actor.h"

// 자기를 가지고 있는 액터를 저장하고, 자신의 순위를 저장합니다.
Component::Component(Actor* owner, int updateOrder) :mOwner(owner), mUpdateOrder(updateOrder) {
	mOwner->AddComponent(this);
}

// 소멸 시, 액터의 컴포넌트 벡터에 해당 컴포넌트를 제거합니다.
Component::~Component() {
	mOwner->RemoveComponent(this);
}


// 컴포넌트 업데이트
void Component::Update(float deltaTime) {}
