#include"Actor.h"
#include"Game.h"
#include"Component.h"

// 액터의 상태와 게임 객체 변수 등을 초기화 합니다.
Actor::Actor(Game* game) :mState(EActive),mGame(game),mX(0),mY(0){}

Actor::~Actor(){}

// 업데이트
// 액터의 상태가 EActive 일 때, 컴포넌트와 상속받은 각각의 액터를 업데이트 합니다.
void Actor::Update(float deltaTime) {				
	if (mState == EActive) {						
		UpdateComponents(deltaTime);
		UpdateActor(deltaTime);
	}
}

// 컴포넌트 업데이트
void Actor::UpdateComponents(float deltaTime) {
	for (auto comp : mComponents) {
		comp->Update(deltaTime);					// 각각의 컴포들을 업데이트 합니다.
	}
}

// 액터 업데이트
void Actor::UpdateActor(float deltaTime){}

// 컴포넌트 추가
void Actor::AddComponent(Component* component) {
	int myOrder = component->GetUpdateOrder();		// 업데이트 우선 순위를 가져옵니다.
	auto iter = mComponents.begin();
	for (; iter != mComponents.end(); ++iter) {
		if (myOrder < (*iter)->GetUpdateOrder()) {	// 자신보다 우선순위가 낮은 컴포넌트의 위치를 찾습니다.
			break;
		}
	}

	mComponents.insert(iter, component);			// 해당 위치에 삽입하여, 정렬 상태를 유지합니다.
}

// 컴포넌트 제거
void Actor::RemoveComponent(Component* component) {
	auto iter = find(mComponents.begin(), mComponents.end(), component);	// 해당 컴포넌트의 위치를 찾습니다.
	if (iter != mComponents.end()) {
		mComponents.erase(iter);											// erase로 순서를 유지한 상태로 제거합니다.
	}
}
