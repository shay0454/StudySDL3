#include"Component.h"
#include"Actor.h"

// �ڽŸ� ������ �ִ� ���͸� �����ϰ� �ڽ��� �켱������ �ʱ�ȭ �մϴ�.
Component::Component(Actor* owner, int updateOrder) :mOwner(owner), mUpdateOrder(updateOrder) {
	mOwner->AddComponent(this);
}

Component::~Component() {
	mOwner->RemoveComponent(this);
}


// ������Ʈ ������Ʈ
void Component::Update(float deltaTime) {}
