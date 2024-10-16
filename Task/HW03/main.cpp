#include <iostream>
#include "Dept.h"
using namespace std;


int main() {
	Dept com(10);
	com.read();
	int n = countPass(com);
	cout << "60점 이상은 " << n << "명";
}
