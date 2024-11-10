#include <iostream>
using namespace std;

#include "printer.h"

Printer::Printer() {
	availableCount = 0;
	printedCount = 0;
	model = "";
	manufacturer = "";
}

//잉크젯 프린터 생성자
InkJetPrinter::InkJetPrinter(string model,string manufacturer,int availableCount, int availableInk) {
	this->model = model;
	this->manufacturer = manufacturer;
	this->availableCount = availableCount;
	this->availableInk = availableInk;
}

//레이저 프린터 생성자
LaserPrinter::LaserPrinter(string model, string manufacturer, int availableCount, float availableToner) {
	this->model = model;
	this->manufacturer = manufacturer;
	this->availableCount = availableCount;
	this->availableToner = availableToner;
}

//프린터 소멸자
Printer::~Printer() {}

//잉크젯 프린터 소멸자
InkJetPrinter::~InkJetPrinter() {}

//레이저 프린터 소멸자
LaserPrinter::~LaserPrinter() {}


//프린터로 프린트..?
void Printer::print(int pages) {
	cout << "프린트하였습니다." << endl;
	availableCount -= pages;
}

//잉크젯 프린터로 프린트
void InkJetPrinter::printInkJet(int pages) {
	print(pages);   //Printer를 상속받았으므로
	availableInk -= pages;
}

//레이저 프린터로 프린트
void LaserPrinter::printLaser(int pages) {
	print(pages);   //Printer를 상속받았으므로
	availableToner -= pages*0.5;
}



//잉크젯 프린터 정보 출력
void InkJetPrinter::showIJPinfo() {
	cout << model << ", " << manufacturer << ", 남은 종이 " << availableCount << "장, 남은 잉크 " << availableInk<<endl;
}

//레이저 프린터 정보 출력
void LaserPrinter::showLPinfo() {
	cout << model << ", " << manufacturer << ", 남은 종이 " << availableCount << "장, 남은 토너 " << availableToner<<endl;
}

int Printer::getavailableCount() {
	return availableCount;
}