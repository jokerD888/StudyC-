#define _CRT_SECURE_NO_WARNINGS 1
#pragma noce
#include<iostream>
//#include<string>
using namespace std;
class Person
{
public:
	//��������
	void setName(string name);
	
	//��ȡ����
	string getName();

	//��ȡ����
	int getAge();
	
	//��������
	void setAge(int age);
	
	
	//��������
	void setLover(string lover);
	
private:
	//����	�ɶ���д
	string m_Name;
	//���� �ɶ���д
	int m_Age;
	//����	ֻд
	string m_Lover;

};