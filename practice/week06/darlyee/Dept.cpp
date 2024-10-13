#include <iostream>
#include "Dept.h"
using namespace std;

Dept::Dept(int size) {   //생성자
	this->size = size;
	scores = new int[size];
}

Dept::Dept(const Dept& dept) {
	this->size = dept.size;
	this->scores = new int[this->size];  // 새로운 메모리 공간 할당
	// 원본 객체의 배열 내용을 복사
	for (int i = 0; i < this->size; i++)
		(this->scores)[i] = dept.scores[i];
}

Dept::~Dept() {
	if (scores)
		delete[] scores;
}


int Dept::getSize() {
	return size;
}

//
void Dept::read() {
	cout << size << "개 점수 입력>>";
	for(int i=0;i<size;i++)
		cin >> scores[i];
}

//
bool Dept::isOver60(int index) {
	return scores[index] > 60;
}


int countPass(Dept dept) {
	int count = 0;
	for (int i = 0; i < dept.getSize(); i++) {
		if (dept.isOver60(i))
			count++;
	}
	return count;
}