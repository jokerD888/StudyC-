#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
//#include<string>
using namespace std;
#include"person.h"
//��Ա��������Ϊ˽��
//1.�Լ����Կ��ƶ�дȨ��
//2.����д�����Լ�����ݵ���Ч��
//class Person
//{
//public:
//	//��������
//	void setName(string name)
//	{
//		m_Name = name;
//	}
//	//��ȡ����
//	string getName()
//	{
//		return m_Name;
//	}
//	//��ȡ����
//	int getAge()
//	{
//		
//		return m_Age;
//	}
//	//��������
//	void setAge(int age)
//	{
//		if (age < 0 || age>150)
//		{
//			m_Age = 0;
//			cout << "�����������" << endl;
//			return;
//		}
//		m_Age = age;
//	}
//	//��������
//	void setLover(string lover)
//	{
//		m_Lover = lover;
//	}
//private:
//	//����	�ɶ���д
//	string m_Name;
//	//���� �ɶ���д
//	int m_Age;
//	//����	ֻд
//	string m_Lover;
//
//};

int main(void)
{
	Person p;
	p.setName("����");
	cout <<"����Ϊ:"<< p.getName() << endl;

	//p.m_Age = 18;	//�������ɷ���
	p.setAge(1008);
	cout << "����Ϊ:"<<p.getAge() << endl;

	p.setLover("zlm");
	
	return 0;
}