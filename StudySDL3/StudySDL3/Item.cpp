#include"Item.h"
#include"Game.h"
#include"DrawComponent.h"
#include"CollisionComponent.h"
#include"Player.h"

Item::Item(Game* game)
	:Actor(game),
	mDC(nullptr),
	mCC(nullptr) 
{
	mDC = new DrawComponent(this);
	// Item의 색을 빨강으로 설정
	mDC->SetColor({ 255, 0, 0, 0 });

	SetPosition(Vector2(1024*SDL_randf(),512*SDL_randf()));		// 위치 설정
	SetSize(Vector2(32.f, 32.f));		// 크기 설정

	// 생성 시에 사이즈를 가져오므로 사이즈 설정 후에 추가
	mCC = new CollisionComponent(this);	

	game->AddCollider(mCC);
}

Item::~Item() {
	GetGame()->RemoveCollider(mCC);
}

void Item::OnCollision(Actor* other) {
	// 상대가 Player인지를 dynamic_cast로 확인ㅇ
	// 변환을 실패할 경우 false로 판별
	if (dynamic_cast<Player*>(other)) {
		SetState(EDead);
	}
}