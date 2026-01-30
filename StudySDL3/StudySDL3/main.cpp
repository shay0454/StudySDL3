#include<SDL3/SDL.h>
#include "game.h"
int main(int argc, char** argv) {
	Game game;				// 게임 클래스 객체를 생성합니다.
	if(game.Initialize()){	// 객체 초기화 후,
		game.RunLoop();			// 루프를 돌립니다.
	}
}