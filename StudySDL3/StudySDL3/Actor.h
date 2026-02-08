#pragma once
#include<vector>
#include"Component.h"
#include"Vector2.h"

class Actor {
	public:
		enum State {
			EActive, EPaused, EDead							// 액터의 상태를 기록하기 위한 Enum
		};
		// game의 기능을 사용하기 위해 매개변수로 가져옵니다
		Actor(class Game* game);
		virtual ~Actor();

		void Update(float deltaTime);				// game.h에서 액터의 업데이트를 하기 위한 함수입니다.
		void UpdateComponents(float deltaTime);		// 액터가 가진 컴포넌트들을 업데이트 합니다.
		virtual void UpdateActor(float deltaTime);	// 액터 자체를 업데이트 합니다.

	public:
		void AddComponent(class Component* component);		// 컴포넌트를 추가합니다.
		void RemoveComponent(class Component* component);	// 컴포넌트를 제거합니다.

		void SetState(State state) { mState = state; }		
		State GetState() const { return mState; }			

	private:
		State mState;										// 액터의 상태에 따라 기능 수행가능한 지 확인합니다.
		std::vector<Component*> mComponents;			// 가지고 있는 컴포넌트 벡터, 업데이트를 위해 벡터로 구성
		class Game* mGame;									// game.h내의 기능을 사용하기 위한 변수

		Vector2 mPosition;									// 월드 좌표
};

