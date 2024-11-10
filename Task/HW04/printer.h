#pragma once
#include <string>

class Printer {
protected:
	string model;   //모델명
	string manufacturer;   //제조사
	int availableCount;   //인쇄 종이 잔량

public:
	int printedCount;   //인쇄 매수
	Printer();   //생성자
	~Printer();   //소멸자
	void print(int pages);   //멤버 함수 : 호출될 때마다 apges매의 용지 사용
	int getavailableCount();
};

class InkJetPrinter:public Printer {   //Printer을 상속 받음
	int availableInk;   //잉크 잔량
public:
	InkJetPrinter(string model, string manufacturer, int availableCount, int availableInk);   //생성자
	~InkJetPrinter();   //소멸자
	void printInkJet(int pages);   //멤버 함수
	void showIJPinfo();   //정보 출력
	

};

class LaserPrinter:public Printer {   //Printer을 상속받음
	float availableToner;   //토너 잔량
public:
	LaserPrinter(string model, string manufacturer, int availableCount, float availableToner);   //생성자
	~LaserPrinter();   //소멸자
	void printLaser(int pages);   //멤버 함수
	void showLPinfo();   //정보 출력
};