#include"InputComponent.h"
#include"SDL3/SDL.h"
#include"Vector2.h"
#include"MoveComponent.h"

// 입력 처리는 기능 중에 가장 중요하기에 우선순위를 1로 설정합니다. 
InputComponent::InputComponent(class Actor* owner) :Component(owner,1){}

// 입력 처리
void InputComponent::ProcessInput(const bool* keyState) {

	bPageUp = false;
	bPageDown = false;

	if (keyState[SDL_SCANCODE_PAGEUP]) {
		bPageUp=true;
	}
	if (keyState[SDL_SCANCODE_PAGEDOWN]) {
		bPageDown = true;
	}

	if (mMC) {	// MoveComponent가 있을 때만 활성화

		// 방향을 초기화 합니다.
		Vector2 dir(0, 0);

		// 렌더링 시 y축은 아래로 갈수록 증가합니다. (화면 좌상단이 원점)
		// 따라서 위로 이동 시, y를 감소시키고, 아래로 이동 시, y를 증가시킵니다.
		if (keyState[SDL_SCANCODE_W]) dir.y -= 1;
		if (keyState[SDL_SCANCODE_S]) dir.y += 1;
		if (keyState[SDL_SCANCODE_A]) dir.x -= 1;
		if (keyState[SDL_SCANCODE_D]) dir.x += 1;

		mMC->SetDirection(dir);
	}
}