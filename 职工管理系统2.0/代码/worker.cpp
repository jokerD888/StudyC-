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
	cout << "ְ����ţ� " << m_Id
		<< "\tְ��������" << m_Name
		<< "\t��λ����ְͨ��" 
		<< "\t��λְ��: ��ɾ�����������" << endl;
}

Manager::Manager(int id, string name)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_dId = 2;
}

void Manager::ShowInfo()
{
	cout << "ְ����ţ� " << m_Id
		<< "\tְ��������" << m_Name
		<< "\t��λ������"
		<< "\t��λְ��: ����ϰ彻�������񣬲��·������Ա��" << endl;
}

Boss::Boss(int id, string name)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_dId = 3;
}
void Boss::ShowInfo()
{
	cout << "ְ����ţ� " << m_Id
		<< "\tְ��������" << m_Name
		<< "\t��λ���ܲ�"
		<< "\t��λְ��: ����˾��������" << endl;
}

