#pragma once
#include"SDL3/SDL.h"
class Component {
	public:
		// Actor.h의 기능을 쓰기 위해 자기를 가진 액터를 가져와 저장, 업데이트에 우선 순위를 두어 실행 순서 제어
		Component(class Actor* owner, int updateOrder = 100);	
		~Component();

		virtual void Update(float deltaTime);				// 컴포넌트 업데이트
	
		virtual void ProcessInput(const bool* keyState) {}	// 입력 처리 (InputCompnent에서 오버라이드)
		virtual void Draw(SDL_Renderer* renderer) {}		// 랜더링 처리 (DrawComponent에서 오버라이드)

		int GetUpdateOrder() const { return mUpdateOrder; }	// 업데이트 순위 반환

	public:
		class Actor* GetOwner()const { return mOwner; }

	private:
		class Actor* mOwner;				// 자기를 가지고 있는 액터
		int mUpdateOrder;					// 우선 순위를 두어, 실행 순서를 제어합니다. (낮을수록 우선)
};

