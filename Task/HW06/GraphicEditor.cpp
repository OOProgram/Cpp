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
	cout << "삽입:1, 삭제:2, 모두보기:3, 종료:4 >> ";
	cin >> n;
	return n;
}

int UI::selectShape() {
	int n;
	cout << "선:1, 원:2, 사각형:3 >> ";
	cin >> n;
	return n;
}

int UI::selectIndex() {
	int n;
	cout << "삭제하고자 하는 도형의 인덱스 >> ";
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
	case 1:   
		v.push_back(new Line());
		break;

	case 2:  
		v.push_back(new Circle());
		break;

	case 3:  
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
		cout << "인덱스를 잘못 입력하셨습니다." << endl;
}

void GraphicEditor::call() {
	bool exit = true;
	cout << "그래픽 에디터입니다." << endl;
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
