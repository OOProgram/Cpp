#pragma once
#include <iostream>
using namespace std;

class Shape {
	Shape* next;
protected:
	virtual void draw() = 0;
public:
	Shape();
	virtual ~Shape();
	void paint();
	Shape* add(Shape* p);
	Shape* getNext();
	void setNext(Shape* p);
};

class Circle : public Shape {
protected:
	virtual void draw();
};

class Rect : public Shape {
protected:
	virtual void draw();
};

class Line : public Shape {
protected:
	virtual void draw();
};

class UI {
public:
	static int selectBehavior();
	static int selectShape();
	static int selectIndex();
};

class GraphicEditor {
	Shape* pStart;
	Shape* pLast;
	int count;
public:
	GraphicEditor();
	void inputShape(int num);
	void deleteShape(int num);
	void call();
};