#include <iostream>
#include "Dept.h"
using namespace std;


int main() {
	Dept com(10);   //�� 10���� �ִ� �а�
	com.read();
	int n = countPass(com);
	cout << "60�� �̻��� " << n << "��";
}