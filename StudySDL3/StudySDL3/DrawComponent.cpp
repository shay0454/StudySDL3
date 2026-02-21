#include"DrawComponent.h"
#include"SDL3/SDL.h"
#include"Actor.h"
#include"Game.h"

// 기본 색을 초록으로 설정
DrawComponent::DrawComponent(Actor* owner, int updateOrder) :Component(owner, updateOrder), mColor{0,255,0,255} {
}

void DrawComponent::Draw(SDL_Renderer* renderer) {
	// 색깔 설정
	SDL_SetRenderDrawColor(renderer, mColor.r, mColor.g, mColor.b, mColor.a);

	Vector2 pos = GetOwner()->GetPosition();

	// 크기 및 스케일을 가져와 렌더링할 크기 설정
	Vector2 mSize = GetOwner()->GetSize();
	float scale = GetOwner()->GetScale();

	// 중앙을 위치로 설정합니다
	SDL_FRect rect = {
		pos.x - mSize.x * scale / 2,
		pos.y - mSize.y * scale / 2,
		mSize.x * scale,
		mSize.y * scale
	};

	// 해당 함수는 좌상단 기준으므로 중앙을 위치로 설정합니다.
	SDL_RenderFillRect(renderer, &rect);
}
