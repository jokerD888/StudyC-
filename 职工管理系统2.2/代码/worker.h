#pragma once
#include<iostream>
using namespace std;
//创建一个抽象职工类，保留公共特性，重写个人信息
class Worker
{
public:
	//显示个人信息
	virtual void ShowInfo() = 0;

	//职工编号
	int m_Id;  

	//姓名
	string m_Name;

	//部门编号
	int m_dId;

};

//其中的dId为部门编号，1普通职工，2经理，3老板
//普通职工
class Employee :public Worker
{
public:
	//构造函数以传入的职工编号，姓名来初始化成员变量
	Employee(int id, string name);

	//重写个人信息函数
	virtual void ShowInfo();
};

//经理
class Manager :public Worker
{
public:
	//构造函数以传入的职工编号，姓名来初始化成员变量
	Manager(int id, string name);

	//重写个人信息函数
	virtual void ShowInfo();
};

//老板
class Boss :public Worker
{
public:
	//构造函数以传入的职工编号，姓名来初始化成员变量
	Boss(int id, string name);

	//重写个人信息函数
	virtual void ShowInfo();
};