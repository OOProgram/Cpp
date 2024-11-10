#include <iostream>
using namespace std;
#include "printer.h"

int main() {
	int end = 1;

	InkJetPrinter *ijp = new InkJetPrinter("Office V40", "HP", 5, 10);   //객체 동적 생성
	LaserPrinter* lp = new LaserPrinter("SCX-6x45", "삼성전자", 3, 20);   //객체 동적 생성

	cout << "현재 작동 중인 2대의 프린터는 아래와 같다." << endl;
	cout << "잉크젯 : ";
	ijp->showIJPinfo();   //정보 출력
	cout << "레이저 : ";
	lp->showLPinfo();   //정보 출력

	while (end) {
		int what, pages;
		cout << endl << "프린터(1:잉크젯, 2:레이저)와 매수 입력>>";
		cin >> what >> pages;
		if (what == 1) {
			if (pages <= ijp->getavailableCount())
				ijp->printInkJet(pages);
			else
				cout << "용지가 부족하여 프린트할 수 없습니다."<<endl;
		}
		else if(what == 2) {
			if (pages <= lp->getavailableCount())
				lp->printLaser(pages);
			else
				cout << "용지가 부족하여 프린트할 수 없습니다."<<endl;
		}

		ijp->showIJPinfo();
		lp->showLPinfo();


		//중단 조건
		string ing = "";
		cout << "계속 프린트 하시겠습니까(y/n)>>";
		cin >> ing;
		if (ing == "n")
			end = 0;
	}
	delete lp;
	delete ijp;
}