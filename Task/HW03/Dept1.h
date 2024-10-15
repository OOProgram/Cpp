#pragma once
#include <iostream>

class Dept {
	int size;   //scores 배열의 크기
	int* scores;   //동적 할당 받을 정수 배열의 주소
public:
	Dept(int size);   //생성자
	~Dept();   //소멸자
	int getSize();
	void read();   //size만큼 키보드에서 정수를 읽어 scores 배열에 저장
	bool isOver60(int index);
};

int countPass(Dept& dept);