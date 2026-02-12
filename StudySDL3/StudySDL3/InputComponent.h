#pragma once
#include"Component.h"

class InputComponent : public Component {
public:
	InputComponent(class Actor* owner);

	void ProcessInput(const bool* keyState) override;

	void SetMoveComponent(class MoveComponent* component) { mMC = component; }

	bool GetPageUp()const { return bPageUp; }
	bool GetPageDown() const { return bPageDown; }

private:
	bool bPageUp;
	bool bPageDown;
};