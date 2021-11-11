#pragma once
#include<iostream>
using namespace std;
#include"Identity.h"
#include<vector>
#include"computerRoom.h"
#include"orderFile.h"
//学生类
class Student :public Identity {
public:
	//默认，有参构造，菜单界面
	Student();
	Student(int id, string name, string pwd);
	virtual void operMenu();

	//申请/查看自身/查看所有/取消 预约
	void applyOrder();
	void showMyOrder();
	void showAllOrder();
	void cancelOrder();

	int m_Id;

	//机房容器
	vector<ComputerRoom> vCom;
};


