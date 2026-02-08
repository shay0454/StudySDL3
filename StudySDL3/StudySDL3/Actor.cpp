#include"Actor.h"
#include"Game.h"
#include"Component.h"

// 액터의 상태와 게임 객체 변수 저장, 그 외의 자잘한 기능을 수행합니다..
Actor::Actor(Game* game) :mState(EActive),mGame(game),mPosition(Vector2(0,0)){
	mGame->AddActor(this);
}

// 액터의 소멸 시, 게임 객체의 액터 벡터에 해당 액터를 제거합니다.
Actor::~Actor(){
	mGame->RemoveActor(this);
}

// 업데이트
// 액터가 살아있을 때, 가진 컴포넌트와 자기 자신(Actor 상속 객체)을 업데이트 합니ㅏㄷ.
void Actor::Update(float deltaTime) {				
	if (mState == EActive) {						
		UpdateComponents(deltaTime);
		UpdateActor(deltaTime);
	}
}

// 컴포넌트 업데이트
void Actor::UpdateComponents(float deltaTime) {
	for (auto comp : mComponents) {
		comp->Update(deltaTime);					// 자기가 가진 컴포넌트들을 모두 업데이트 합니다.
	}
}

// 자기 자신(Actor 상속 객체)을 업데이트 합니다.
void Actor::UpdateActor(float deltaTime){}

// 컴포넌트 추가
void Actor::AddComponent(Component* component) {
	int myOrder = component->GetUpdateOrder();		// 컴포넌트의 업데이트 순위를 가져옵니다.
	auto iter = mComponents.begin();
	for (; iter != mComponents.end(); ++iter) {
		if (myOrder < (*iter)->GetUpdateOrder()) {	// 순위에 맞는 자리를 찾습니다.
			break;
		}
	}

	mComponents.insert(iter, component);			// 올바른 자리에 삽입하여 업데이트 순서를 유지합니다.
}

// 컴포넌트 제거
void Actor::RemoveComponent(Component* component) {
	auto iter = find(mComponents.begin(), mComponents.end(), component);	// 
	if (iter != mComponents.end()) {
		mComponents.erase(iter);											// erase�� ������ ������ ���·� �����մϴ�.
	}
}