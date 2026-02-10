#include"Player.h"
#include"Game.h"
#include"Vector2.h"
#include"InputComponent.h"
#include"DrawComponent.h"

Player::Player(Game* game) :Actor(game){
	mIC = new InputComponent(this);

}