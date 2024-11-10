#include <iostream>
using namespace std;

#include "printer.h"

Printer::Printer() {
	availableCount = 0;
	printedCount = 0;
	model = "";
	manufacturer = "";
}

InkJetPrinter::InkJetPrinter(string model,string manufacturer,int availableCount, int availableInk) {
	this->model = model;
	this->manufacturer = manufacturer;
	this->availableCount = availableCount;
	this->availableInk = availableInk;
}

LaserPrinter::LaserPrinter(string model, string manufacturer, int availableCount, float availableToner) {
	this->model = model;
	this->manufacturer = manufacturer;
	this->availableCount = availableCount;
	this->availableToner = availableToner;
}

Printer::~Printer() {}

InkJetPrinter::~InkJetPrinter() {}

LaserPrinter::~LaserPrinter() {}

void Printer::print(int pages) {
	cout << "프린트하였습니다." << endl;
	availableCount -= pages;
}

void InkJetPrinter::printInkJet(int pages) {
	print(pages);   //Printer를 상속받았으므로
	availableInk -= pages;
}

void LaserPrinter::printLaser(int pages) {
	print(pages);   //Printer를 상속받았으므로
	availableToner -= pages*0.5;
}

void InkJetPrinter::showIJPinfo() {
	cout << model << ", " << manufacturer << ", 남은 종이 " << availableCount << "장, 남은 잉크 " << availableInk<<endl;
}

void LaserPrinter::showLPinfo() {
	cout << model << ", " << manufacturer << ", 남은 종이 " << availableCount << "장, 남은 토너 " << availableToner<<endl;
}

int Printer::getavailableCount() {
	return availableCount;
}
