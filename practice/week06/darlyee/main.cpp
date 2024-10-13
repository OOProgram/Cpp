#include <iostream>
#include "Dept.h"
using namespace std;


int main() {
	Dept com(10);   //총 10명이 있는 학과
	com.read();
	int n = countPass(com);
	cout << "60점 이상은 " << n << "명";
}