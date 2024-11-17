#include <iostream>
#include "GraphicEditor.h"
using namespace std;

Shape::Shape() {
	next = NULL;
}

Shape::~Shape() {}

void Shape::paint() { 
	draw();
}

Shape* Shape::add(Shape* p) { 
	this->next = p; 
	return p; 
}

Shape* Shape::getNext() { 
	return next; 
}


void Shape::setNext(Shape* p) { 
	this->next = p->next; 
}

void Line::draw() {
	cout << "Line" << endl;
}

void Circle::draw() {
		cout << "Circle" << endl;
}

void Rect::draw() {
	cout << "Rectangle" << endl;
}

int UI::selectBehavior() {
	int n;
	cout << "����:1, ����:2, ��κ���:3, ����:4 >> ";
	cin >> n;
	return n;
}

int UI::selectShape() {
	int n;
	cout << "��:1, ��:2, �簢��:3 >> ";
	cin >> n;
	return n;
}

int UI::selectIndex() {
	int n;
	cout << "�����ϰ��� �ϴ� ������ �ε��� >> ";
	cin >> n;
	return n;
}


GraphicEditor::GraphicEditor() {
	pStart = NULL; 
	pLast = NULL;
	count = 0; 
}

void GraphicEditor::inputShape(int num) {
	switch (num) {
	case 1:
		if (count == 0) {
			pStart = new Line();
			pLast = pStart;
		}
		else
			pLast = pLast->add(new Line());
		count++;
		break;

	case 2:
		if (count == 0) {
			pStart = new Circle();
			pLast = pStart;
		}
		else
			pLast = pLast->add(new Circle());
		count++;
		break;

	case 3:
		if (count == 0) {
			pStart = new Rect();
			pLast = pStart;
		}
		else
			pLast = pLast->add(new Rect());
		count++;
		break;
	}
}

void GraphicEditor::deleteShape(int num) {
	Shape* p = pStart;
	Shape* del = pStart;

	if (num < count) {
		for (int i = 0; i < num; i++) {
			p = del;
			del = del->getNext();
		}
		if (num == 0)
			pStart = p->getNext();
		else
			p->setNext(del);
		count--;
		if (count == 1) pLast = pStart;
		delete del;

	}
	else
		cout << "�ε����� �߸� �Է��ϼ̽��ϴ�." << endl;
}

void GraphicEditor::call() {
	bool exit = true;
	cout << "�׷��� �������Դϴ�." << endl;
	while (exit) {
		switch (UI::selectBehavior()) {
		case 1:
			inputShape(UI::selectShape());
			break;
		case 2:
			deleteShape(UI::selectIndex());
			break;
		case 3: {
			Shape* p = pStart;
			for (int i = 0; i < count; i++) {
				cout << i << ": "; p->paint();
				p = p->getNext();
			}
			break;
		}
		case 4:
			exit = false;
			break;
		}
	}
}