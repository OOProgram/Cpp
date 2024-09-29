#include <iostream>
using namespace std;

#include "Ram.h"

Ram::Ram() {
	for (int i = 0; i < 100 * 1024; i++)
		mem[i] = 0;
	size = 100 * 1024;
}

Ram::~Ram() {
	cout << "메모리 제거됨";
}

//address 주소의 메모리 바이트 리턴
char Ram::read(int address) {
	return mem[address];
}

//address 주소에 한 바이트로 value 저장
void Ram::write(int address, char value) {
	mem[address] = value;
}