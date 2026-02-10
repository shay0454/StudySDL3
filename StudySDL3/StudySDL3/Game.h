#pragma once
#include<SDL3/SDL.h>
#include<vector>

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

public:
	void AddActor(class Actor* actor);		// 액터 추가
	void RemoveActor(class Actor* actor);	// 액터 제거

private:
	class SDL_Window* mWindow;
	class SDL_Renderer* mRenderer;

	Uint64 mTicksCount;

	bool mIsRunning;

	std::vector<class Actor*> mActors;			// 실제로 있는 액터들로 액터들을 업데이트 하기 위한 벡터
	std::vector<class Actor*> mPendingActors;	// 업데이트 중일 때 crash를 방지하기 위해 있는 대기열 액터 벡터
	bool mUpdateActors;							// 업데이트 중인지를 확인하기 위한 변수

	class Player* mPlayer;

};
