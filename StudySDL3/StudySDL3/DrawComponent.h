#pragma once
#include"Component.h"
#include"Vector2.h"

class DrawComponent :public Component {
	public:
		DrawComponent(class Actor* owner, int updateOrder=100);

		void Draw(class SDL_Renderer* renderer) override;	// 렌더링


	private:
};
