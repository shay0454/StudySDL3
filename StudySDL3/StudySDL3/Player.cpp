#include"Player.h"
#include"Game.h"
#include"Vector2.h"
#include"InputComponent.h"
#include"MoveComponent.h"
#include"DrawComponent.h"
#include"CollisionComponent.h"
#include"Item.h"

Player::Player(Game* game) 
	:Actor(game),
	mIC(nullptr),
	mMC(nullptr),
	mDC(nullptr){
	
	mIC = new InputComponent(this);
	mMC = new MoveComponent(this);

	mIC->SetMoveComponent(mMC);				// 입력에 따른 이동 컴포넌트 설정

	mDC = new DrawComponent(this);			

	
	SetPosition(Vector2(500.f, 386.f));		// 위치 설정
	SetSize(Vector2(64.f,64.f));			// 크기 설정

	mCC = new CollisionComponent(this);		// 충돌 처리 추가
	game->AddCollider(mCC);					// 게임 시스템에 충돌 처리 등록	

}

// 소멸 시에 가지고 있는 CollisionComponent를 게임 시스템에서 제거
Player::~Player() {
	GetGame()->RemoveCollider(mCC);
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

void Player::OnCollision(Actor* other) {
	// 상대가 Item인지를 dynamic_cast로 확인
	// 변환을 실패할 경우 false로 판별
	if (dynamic_cast<Item*>(other)) {
		SDL_Log("You Got Item");
	}
}
