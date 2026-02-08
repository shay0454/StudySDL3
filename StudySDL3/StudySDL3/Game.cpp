#include"Game.h"
#include<SDL3/SDL.h>
#include"Actor.h"
#include<algorithm>

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

	//랜더러 생성
	mRenderer = SDL_CreateRenderer(mWindow, NULL);
	if (!mRenderer) {
		SDL_Log("Failed to create renderer : %s", SDL_GetError());
	}

	//틱 초기화
	mTicksCount = SDL_GetTicksNS();

	mIsRunning = true;

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

// 입력 처리
void Game::ProcessInput()
{
	SDL_Event event;

	// 이벤트 큐에서 가져와 처리
	while (SDL_PollEvent(&event)) {
		switch (event.type) {	
		case SDL_EVENT_QUIT:	// 창의 X를 클릭했을 때
			mIsRunning = false;	// 루프를 종료하여 게임을 끝냅니다. 
			break;
		}
	}

	const bool* state = SDL_GetKeyboardState(NULL); // 키보드의 상태를 가져옵니다.
	if (state[SDL_SCANCODE_ESCAPE]) {				// 해당 키가 ESC일 시
		mIsRunning = false;							// 루프를 종료하여 게임을 끝냅니다.
		return;
	}

	float mX, mY;
	const Uint32 MouseState = SDL_GetMouseState(&mX,&mY);	// 마우스의 상태를 가져오고, 포인터의 위치를 저장합니다.
	if (MouseState & SDL_BUTTON_MASK(SDL_BUTTON_RIGHT)) {	// 비트마스킹 기법으로 Mask된 버튼의 상태를 확인합니다.
		mIsRunning = false;									// 루프를 종료하여 게임을 끝냅니다.
		return;
	}
}

void Game::UpdateGame(){
	// deltaTime 계산
	Uint64 currentTicks = SDL_GetTicksNS();								// 현재 시간을 가져옵니다.
	Uint64 elapsedNS = currentTicks - mTicksCount;						// 틱 차이로 시간 계산
	if (elapsedNS < TARGET_Frame) {										// 목표한 프레임보다 작동이 빠르면
		SDL_DelayNS(TARGET_Frame - elapsedNS);							// 딜레이를 주어 목표 프레임을 유지합니다.
		currentTicks = SDL_GetTicksNS();								// 실제 경과 시간 재계산합니다.
	}
	float deltaTime = (float)(currentTicks - mTicksCount) / NANOSECOND;	// 시간 차 계산

	deltaTime = SDL_clamp(deltaTime, 0.0f, 0.05f);						// 터널링 방치를 위한 프레임 타임 제한
	mTicksCount = currentTicks;

	// 액터 업데이터
	mUpdateActors = true;								// 업데이트 시에 액터 추가, 제거를 방지합니다.
	for (Actor* mActor : mActors) {
		mActor->Update(deltaTime);						// 각각의 액터를 업데이트 합니다.
	}
	mUpdateActors = false;								// 업데이트가 완료되어, 액터 추가, 제거를 허용합니다.

	// 대기열 액터 이동
	for (Actor* pending : mPendingActors) {
		mActors.emplace_back(pending);					// 대기열 액터를 실제 액터 공간으로 가져옵니다.
	}
	mPendingActors.clear();								// 대기열 액터들을 다 넣었으므로 clear시킵니다.

	// 액터 죽음 확인
	std::vector<Actor*> deadActors;
	for (Actor* actor : mActors) {
		if (actor->GetState() == Actor::EDead) {		// 상태를 확인하여 죽은 액터를 찾습니다.
			deadActors.emplace_back(actor);				// 따로 벡터에 담습니다.
		}
	}

	// 죽은 액터 처리
	for (Actor* actor : deadActors) {
		RemoveActor(actor);								// 게임 시스템 내 액터 벡터에서 해당 액터를 제거합니다.
		delete actor;									// 액터를 지웁니다. ( 이때, 컴포넌트 등을 제거합니다.)
	}

}

// 결과 출력
void Game::GenerateOutput()
{
	SDL_SetRenderDrawColor(mRenderer, 0, 0, 255, 255);	// 채울 색을 결정합니다.
	SDL_RenderClear(mRenderer);							// 버퍼의 내용를 지웁니다.

	// 화면 색칠
	SDL_FRect A = { 0,0,1024,768 };
	SDL_RenderFillRect(mRenderer, &A);					// Rect를 만듭니다.


	SDL_RenderPresent(mRenderer);						// 변경한 백버퍼와 교체합니다.
}

// 액터 추가
void Game::AddActor(Actor* actor) {
	if (mUpdateActors) {								
		mPendingActors.emplace_back(actor);				// 액터가 업데이트 중일 시, 대기열 액터 벡터에 추가
	} else {
		mActors.emplace_back(actor);					// 액터가 업데이트 중이 아닐 시, 액터 벡터에 바로 추가
	}
}

// 액터 제거
void Game::RemoveActor(Actor* actor) {
	// 대기열 액터 벡터에서 해당 액터를 찾아 제거
	auto iter = find(mPendingActors.begin(), mPendingActors.end(), actor);	
	if (iter != mPendingActors.end()) {										
		std::iter_swap(iter, mPendingActors.end() - 1);		// swap 후 pop으로 효율적으로 제거
		mPendingActors.pop_back();							
	}

	// 액터 벡터에서 해당 액터를 찾아 제거
	iter = find(mActors.begin(), mActors.end(), actor);		
	if (iter != mActors.end()) {											
		std::iter_swap(iter, mActors.end() - 1);			// swap 후 pop으로 효율적으로 제거
		mActors.pop_back();									
	}

}