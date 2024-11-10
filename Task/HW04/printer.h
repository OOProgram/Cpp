#pragma once
#include <string>

class Printer {
protected:
	string model;
	string manufacturer;
	int availableCount;

public:
	int printedCount;
	Printer();
	~Printer(); 
	void print(int pages);
	int getavailableCount();
};

class InkJetPrinter:public Printer {
	int availableInk;
public:
	InkJetPrinter(string model, string manufacturer, int availableCount, int availableInk); 
	~InkJetPrinter();
	void printInkJet(int pages); 
	void showIJPinfo();   
	

};

class LaserPrinter:public Printer {  
	float availableToner; 
public:
	LaserPrinter(string model, string manufacturer, int availableCount, float availableToner); 
	~LaserPrinter();  
	void printLaser(int pages);
	void showLPinfo(); 
};
