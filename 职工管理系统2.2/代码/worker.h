#pragma once
#include<iostream>
using namespace std;
//����һ������ְ���࣬�����������ԣ���д������Ϣ
class Worker
{
public:
	//��ʾ������Ϣ
	virtual void ShowInfo() = 0;

	//ְ�����
	int m_Id;  

	//����
	string m_Name;

	//���ű��
	int m_dId;

};

//���е�dIdΪ���ű�ţ�1��ְͨ����2����3�ϰ�
//��ְͨ��
class Employee :public Worker
{
public:
	//���캯���Դ����ְ����ţ���������ʼ����Ա����
	Employee(int id, string name);

	//��д������Ϣ����
	virtual void ShowInfo();
};

//����
class Manager :public Worker
{
public:
	//���캯���Դ����ְ����ţ���������ʼ����Ա����
	Manager(int id, string name);

	//��д������Ϣ����
	virtual void ShowInfo();
};

//�ϰ�
class Boss :public Worker
{
public:
	//���캯���Դ����ְ����ţ���������ʼ����Ա����
	Boss(int id, string name);

	//��д������Ϣ����
	virtual void ShowInfo();
};