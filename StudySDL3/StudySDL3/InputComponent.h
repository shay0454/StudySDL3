#pragma once
#include"Component.h"

class InputComponent : public Component {
public:
	InputComponent(class Actor* owner);

	void ProcessInput(const bool* keyState) override;

	// 조작할 MoveComponent를 외부에서 주입
	// MoveComponent가 없거나 교체가 필요한 경우를 대비
	void SetMoveComponent(class MoveComponent* component) { mMC = component; }

	bool GetPageUp()const { return bPageUp; }
	bool GetPageDown() const { return bPageDown; }

private:
	bool bPageUp;
	bool bPageDown;
	class MoveComponent* mMC;	// 입력 처리를 전달할 MoveComponent
};