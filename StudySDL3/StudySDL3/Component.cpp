#include"Component.h"

// 자신를 가지고 있는 액터를 저장하고 자신의 우선순위를 초기화 합니다.
Component::Component(Actor* owner, int updateOrder) :mOwner(owner), mUpdateOrder(updateOrder) {}

Component::~Component() {}

// 컴포넌트 업데이트
void Component::Update(float deltaTime) {}

