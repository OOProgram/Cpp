#include <iostream>
using namespace std;

#include "printer.h"

Printer::Printer() {
	availableCount = 0;
	printedCount = 0;
	model = "";
	manufacturer = "";
}

//��ũ�� ������ ������
InkJetPrinter::InkJetPrinter(string model,string manufacturer,int availableCount, int availableInk) {
	this->model = model;
	this->manufacturer = manufacturer;
	this->availableCount = availableCount;
	this->availableInk = availableInk;
}

//������ ������ ������
LaserPrinter::LaserPrinter(string model, string manufacturer, int availableCount, float availableToner) {
	this->model = model;
	this->manufacturer = manufacturer;
	this->availableCount = availableCount;
	this->availableToner = availableToner;
}

//������ �Ҹ���
Printer::~Printer() {}

//��ũ�� ������ �Ҹ���
InkJetPrinter::~InkJetPrinter() {}

//������ ������ �Ҹ���
LaserPrinter::~LaserPrinter() {}


//�����ͷ� ����Ʈ..?
void Printer::print(int pages) {
	cout << "����Ʈ�Ͽ����ϴ�." << endl;
	availableCount -= pages;
}

//��ũ�� �����ͷ� ����Ʈ
void InkJetPrinter::printInkJet(int pages) {
	print(pages);   //Printer�� ��ӹ޾����Ƿ�
	availableInk -= pages;
}

//������ �����ͷ� ����Ʈ
void LaserPrinter::printLaser(int pages) {
	print(pages);   //Printer�� ��ӹ޾����Ƿ�
	availableToner -= pages*0.5;
}



//��ũ�� ������ ���� ���
void InkJetPrinter::showIJPinfo() {
	cout << model << ", " << manufacturer << ", ���� ���� " << availableCount << "��, ���� ��ũ " << availableInk<<endl;
}

//������ ������ ���� ���
void LaserPrinter::showLPinfo() {
	cout << model << ", " << manufacturer << ", ���� ���� " << availableCount << "��, ���� ��� " << availableToner<<endl;
}

int Printer::getavailableCount() {
	return availableCount;
}