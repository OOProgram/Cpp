#pragma once
#include <iostream>
using namespace std;

class Player {
	string name;
public:
	Player();
	void setName(string name);
	string getName();
};