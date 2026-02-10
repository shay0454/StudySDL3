#include"InputComponent.h"
#include"SDL3/SDL.h"

// 입력 처리는 기능 중에 가장 중요하기에 우선순위를 1로 설정합니다. 
InputComponent::InputComponent(class Actor* owner) :Component(owner,1){}

// 입력 처리
void InputComponent::ProcessInput(const bool* keyState) {
	if (keyState[SDL_SCANCODE_SPACE]) {
		SDL_Log("You Press Space");			// 테스트 용으로 Space 바를 눌렸을 시 결과를 출력합니다.
	}
}