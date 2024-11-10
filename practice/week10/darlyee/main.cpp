#include <iostream>
using namespace std;
#include "printer.h"

int main() {
	int end = 1;

	InkJetPrinter *ijp = new InkJetPrinter("Office V40", "HP", 5, 10);   //��ü ���� ����
	LaserPrinter* lp = new LaserPrinter("SCX-6x45", "�Ｚ����", 3, 20);   //��ü ���� ����

	cout << "���� �۵� ���� 2���� �����ʹ� �Ʒ��� ����." << endl;
	cout << "��ũ�� : ";
	ijp->showIJPinfo();   //���� ���
	cout << "������ : ";
	lp->showLPinfo();   //���� ���

	while (end) {
		int what, pages;
		cout << endl << "������(1:��ũ��, 2:������)�� �ż� �Է�>>";
		cin >> what >> pages;
		if (what == 1) {
			if (pages <= ijp->getavailableCount())
				ijp->printInkJet(pages);
			else
				cout << "������ �����Ͽ� ����Ʈ�� �� �����ϴ�."<<endl;
		}
		else if(what == 2) {
			if (pages <= lp->getavailableCount())
				lp->printLaser(pages);
			else
				cout << "������ �����Ͽ� ����Ʈ�� �� �����ϴ�."<<endl;
		}

		ijp->showIJPinfo();
		lp->showLPinfo();


		//�ߴ� ����
		string ing = "";
		cout << "��� ����Ʈ �Ͻðڽ��ϱ�(y/n)>>";
		cin >> ing;
		if (ing == "n")
			end = 0;
	}
	delete lp;
	delete ijp;
}