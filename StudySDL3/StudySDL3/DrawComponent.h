#pragma once
#include"Component.h"
#include"Vector2.h"

class DrawComponent :public Component {
	public:
		DrawComponent(class Actor* owner, int updateOrder=100);

		void Draw(class SDL_Renderer* renderer) override;	// 렌더링

		void SetSize(class Vector2 size) { mSize = size; }
		Vector2 GetSize() const { return mSize; }

	private:
		Vector2 mSize;								// 렌더링 할 크기
};
