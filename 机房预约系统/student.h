#pragma once
#include<iostream>
using namespace std;
#include"Identity.h"
#include<vector>
#include"computerRoom.h"
#include"orderFile.h"
//ѧ����
class Student :public Identity {
public:
	//Ĭ�ϣ��вι��죬�˵�����
	Student();
	Student(int id, string name, string pwd);
	virtual void operMenu();

	//����/�鿴����/�鿴����/ȡ�� ԤԼ
	void applyOrder();
	void showMyOrder();
	void showAllOrder();
	void cancelOrder();

	int m_Id;

	//��������
	vector<ComputerRoom> vCom;
};


