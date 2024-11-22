#include <iostream>
#include "GraphicEditor.h"
using namespace std;

Shape::Shape() {}

Shape::~Shape() {}

void Shape::paint() {
	draw();
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


GraphicEditor::GraphicEditor() {}

GraphicEditor::~GraphicEditor() {
	for (int i = 0; i < v.size(); i++)
		delete v[i];
}

void GraphicEditor::inputShape(int num) {
	switch (num) {
	case 1:   //���� ���� �����ߴٸ�
		v.push_back(new Line());
		break;

	case 2:   //���� ���� �����ߴٸ�
		v.push_back(new Circle());
		break;

	case 3:   //���� �׸� �����ߴٸ�
		v.push_back(new Rect());
		break;
	}
}

void GraphicEditor::deleteShape(int num) {

	if (num < v.size()) {
		vector<Shape*>::iterator sh;
		sh = v.begin()+num;
		delete v[num];
		sh=v.erase(sh);
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
		case 3:
			for (int i = 0; i < v.size(); i++) {
				cout << i << " : ";
				v[i]->paint();
			}
			break;
		
		case 4:
			exit = false;
			break;
		}
	}
}