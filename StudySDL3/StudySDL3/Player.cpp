#include"Player.h"
#include"Game.h"
#include"Vector2.h"
#include"InputComponent.h"
#include"MoveComponent.h"
#include"DrawComponent.h"

Player::Player(Game* game) 
	:Actor(game),
	mIC(nullptr),
	mDC(nullptr){
	
	mIC = new InputComponent(this);
	mDC = new DrawComponent(this);

	SetPosition(Vector2(500.f, 386.f));
	mDC->SetSize(Vector2(64.f,64.f));
}

void Player::UpdateActor(float deltaTime) {

	// InputComponent가 있을 때만 활성화 됩니다.
	if (mIC) {
		// 현재 스케일을 가져옵니다.
		float currentScale = GetScale();

		if (mIC->GetPageUp()) {
			currentScale+=1.f * deltaTime;
		}
		if (mIC->GetPageDown()) {
			currentScale -= 1.f * deltaTime;
		}

		// 최대 스케일과 최소 스케일에 제한을 두기 위해 Clamp를 사용.
		currentScale = SDL_clamp(currentScale, 0.1f, 5.0f);

		// 변경된 스케일로 설정합니다.
		SetScale(currentScale);
	}
}