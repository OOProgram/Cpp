#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Shape {
protected:
	virtual void draw() = 0;
public:
	Shape();
	virtual ~Shape();
	void paint();
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
	vector<Shape*> v;
public:
	GraphicEditor();
	~GraphicEditor();
	void inputShape(int num);
	void deleteShape(int num);
	void call();
};