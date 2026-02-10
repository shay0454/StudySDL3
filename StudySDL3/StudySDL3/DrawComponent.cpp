#include"DrawComponent.h"
#include"SDL3/SDL.h"
#include"Actor.h"
#include"Game.h"

DrawComponent::DrawComponent(Actor* owner, int updateOrder) :Component(owner, updateOrder) {
}

void DrawComponent::Draw(SDL_Renderer* renderer) {
	SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);

	Vector2 pos = GetOwner()->GetPosition();
	float scale = GetOwner()->GetScale();
	// 중앙을 위치로 설정합니다
	SDL_FRect rect = {
		pos.x - mSize.x * scale / 2,
		pos.y - mSize.y * scale / 2,
		mSize.x * scale,
		mSize.y * scale
	};

	// 해당 함수는 좌상단을 기준으로 렌더링 합니다.
	SDL_RenderFillRect(renderer, &rect);
}
