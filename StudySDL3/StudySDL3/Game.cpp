#include"Game.h"
#include<SDL3/SDL.h>

Game::Game() {}

// 초기화
bool Game::Initialize() {
	//SDL 초기화
	bool sdlResult = SDL_Init(SDL_INIT_VIDEO);
	if (sdlResult == false) {
		SDL_Log("Unable to initialize SDL : %s", SDL_GetError());
		return false;
	}

	//Window 생성
	mWindow = SDL_CreateWindow("Game Programming", 1024, 768, 0);
	if (!mWindow) {
		SDL_Log("Failed to create window : %s", SDL_GetError());
	}

	return true;
}

// 게임 루프
void Game::RunLoop() {
	while (mIsRunning) {
		ProcessInput();			// 입력을 처리합니다.
		UpdateGame();			// 게임을 업데이트합니다.
		GenerateOutput();		// 업데이트 결과를 출력합니다.
	}
}

// 게임 종료
void Game::Shutdown() {
	SDL_DestroyWindow(mWindow);	// 메모리 및 운영체제 자원 반환
	SDL_Quit();					// 서브시스템 종료 및 지원 강제 해제
}

void Game::ProcessInput()
{
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_EVENT_QUIT:
			mIsRunning = false;
			break;
		}
	}
}

void Game::UpdateGame()
{
}

void Game::GenerateOutput()
{
}
