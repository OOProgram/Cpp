#pragma once
#include <iostream>
#include "Player.h"
using namespace std;

class GamblingGame {
public:
	Player playerArr[2];
	GamblingGame();
	void play();
};