#pragma once
#include <string>

class Printer {
protected:
	string model;   //�𵨸�
	string manufacturer;   //������
	int availableCount;   //�μ� ���� �ܷ�

public:
	int printedCount;   //�μ� �ż�
	Printer();   //������
	~Printer();   //�Ҹ���
	void print(int pages);   //��� �Լ� : ȣ��� ������ apges���� ���� ���
	int getavailableCount();
};

class InkJetPrinter:public Printer {   //Printer�� ��� ����
	int availableInk;   //��ũ �ܷ�
public:
	InkJetPrinter(string model, string manufacturer, int availableCount, int availableInk);   //������
	~InkJetPrinter();   //�Ҹ���
	void printInkJet(int pages);   //��� �Լ�
	void showIJPinfo();   //���� ���
	

};

class LaserPrinter:public Printer {   //Printer�� ��ӹ���
	float availableToner;   //��� �ܷ�
public:
	LaserPrinter(string model, string manufacturer, int availableCount, float availableToner);   //������
	~LaserPrinter();   //�Ҹ���
	void printLaser(int pages);   //��� �Լ�
	void showLPinfo();   //���� ���
};