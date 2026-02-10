#include"Player.h"
#include"Game.h"
#include"Vector2.h"
#include"InputComponent.h"
#include"DrawComponent.h"

Player::Player(Game* game) :Actor(game){
	mIC = new InputComponent(this);
	mDC = new DrawComponent(this);

	SetPosition(Vector2(500.f, 386.f));
	mDC->SetSize(Vector2(64.f,64.f));
}