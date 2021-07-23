#define _CRT_SECURE_NO_WARNINGS 1
#include"worker.h"
Employee::Employee(int id, string name)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_dId = 1;
}

void Employee::ShowInfo()
{
	cout << "职工编号： " << m_Id
		<< "\t职工姓名：" << m_Name
		<< "\t岗位：普通职工" 
		<< "\t岗位职责: 完成经理交给的任务" << endl;
}

Manager::Manager(int id, string name)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_dId = 2;
}

void Manager::ShowInfo()
{
	cout << "职工编号： " << m_Id
		<< "\t职工姓名：" << m_Name
		<< "\t岗位：经理"
		<< "\t岗位职责: 完成老板交给的任务，并下发任务给员工" << endl;
}

Boss::Boss(int id, string name)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_dId = 3;
}
void Boss::ShowInfo()
{
	cout << "职工编号： " << m_Id
		<< "\t职工姓名：" << m_Name
		<< "\t岗位：总裁"
		<< "\t岗位职责: 管理公司所有事务" << endl;
}

