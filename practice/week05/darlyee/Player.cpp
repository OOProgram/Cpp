#include <iostream>
#include "Player.h"
using namespace std;

Player::Player() {
	name = "";
}

string Player::getName() {
	return name;
}

void Player::setName(string name){
	this->name = name;
}