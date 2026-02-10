#pragma once
#include"Component.h"

class InputComponent : public Component {
public:
	InputComponent(class Actor* owner);

	void ProcessInput(const bool* keyState) override;

private:
};