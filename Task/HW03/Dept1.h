#pragma once
#include <iostream>

class Dept {
	int size;   //scores �迭�� ũ��
	int* scores;   //���� �Ҵ� ���� ���� �迭�� �ּ�
public:
	Dept(int size);   //������
	~Dept();   //�Ҹ���
	int getSize();
	void read();   //size��ŭ Ű���忡�� ������ �о� scores �迭�� ����
	bool isOver60(int index);
};

int countPass(Dept& dept);