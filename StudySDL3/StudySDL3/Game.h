#pragma once
#ifndef GAME_H	// game.h 헤더 파일이 포함 안 되었을 경우에만 포합시킵니다.
#define GAME_H	// game.h 정의

#include<SDL3/SDL.h>

#define FPS 60
#define NANOSECOND 1000000000
#define TARGET_Frame NANOSECOND / FPS


class Game {
public:
	Game();				// 생성자
	bool Initialize();	// 초기화
	void RunLoop();		// 게임 루프
	void Shutdown();	// 게임 종료
private:
	void ProcessInput();	// 입력 처리
	void UpdateGame();		// 게임 업데이트
	void GenerateOutput();	// 게임 로직 처리

	class SDL_Window* mWindow;
	class SDL_Renderer* mRenderer;

	Uint64 mTicksCount;

	bool mIsRunning;
};
#endif // !GAME_H
