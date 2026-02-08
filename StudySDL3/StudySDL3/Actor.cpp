#include"Actor.h"
#include"Game.h"
#include"Component.h"

// ������ ���¿� ���� ��ü ���� ���� �ʱ�ȭ �մϴ�.
Actor::Actor(Game* game) :mState(EActive),mGame(game),mPosition(Vector2(0,0)){
	mGame->AddActor(this);
}

Actor::~Actor(){
	mGame->RemoveActor(this);
}

// ������Ʈ
// ������ ���°� EActive �� ��, ������Ʈ�� ��ӹ��� ������ ���͸� ������Ʈ �մϴ�.
void Actor::Update(float deltaTime) {				
	if (mState == EActive) {						
		UpdateComponents(deltaTime);
		UpdateActor(deltaTime);
	}
}

// ������Ʈ ������Ʈ
void Actor::UpdateComponents(float deltaTime) {
	for (auto comp : mComponents) {
		comp->Update(deltaTime);					// ������ �������� ������Ʈ �մϴ�.
	}
}

// ���� ������Ʈ
void Actor::UpdateActor(float deltaTime){}

// ������Ʈ �߰�
void Actor::AddComponent(Component* component) {
	int myOrder = component->GetUpdateOrder();		// ������Ʈ �켱 ������ �����ɴϴ�.
	auto iter = mComponents.begin();
	for (; iter != mComponents.end(); ++iter) {
		if (myOrder < (*iter)->GetUpdateOrder()) {	// �ڽź��� �켱������ ���� ������Ʈ�� ��ġ�� ã���ϴ�.
			break;
		}
	}

	mComponents.insert(iter, component);			// �ش� ��ġ�� �����Ͽ�, ���� ���¸� �����մϴ�.
}

// ������Ʈ ����
void Actor::RemoveComponent(Component* component) {
	auto iter = find(mComponents.begin(), mComponents.end(), component);	// �ش� ������Ʈ�� ��ġ�� ã���ϴ�.
	if (iter != mComponents.end()) {
		mComponents.erase(iter);											// erase�� ������ ������ ���·� �����մϴ�.
	}
}