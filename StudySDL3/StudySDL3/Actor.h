#pragma once
#include<vector>

class Actor {
	public:
		enum State {
			EActive, EPaused, EDead							// 액터의 상태를 기록하기 위한 enum
		};
		// game의 기능을 사용하기 위해 매개변수로 가져옵니다.
		Actor(class Game* game);
		virtual ~Actor();

		void Update(float deltaTime);				// game에게서 엑터 업데이트를 명령 시 수행하기 위한 함수입니다.
		void UpdateComponents(float deltaTime);		// 액터가 가진 컴포넌트들을 업데이트 합니다.
		virtual void UpdateActor(float deltaTime);	// 액터 자체를 업데이트 합니다.

	public:
		void AddComponent(class Component* component);		// 컴포넌트를 추가합니다.
		void RemoveComponent(class Component* component);	// 컴포넌트를 제거합니다.

		void SetState(State state) { mState = state; }		
		State GetState() const { return mState; }			

	private:
		State mState;										// 액터의 상태에 따라 작동을 변경하기 위해 사용합니다.
		std::vector<class Component*> mComponents;			// 컴포넌트를 업데이트 하기 위한 벡터
		class Game* mGame;									// 게임 시스템의 기능을 사용하기 위한 변수

		float mX, mY;										// 월드 좌표
};

