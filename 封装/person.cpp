#define _CRT_SECURE_NO_WARNINGS 1
#include"person.h"

void Person::setName(string name)
{
	m_Name = name;
}
//��ȡ����
string Person::getName()
{
	return m_Name;
}
//��ȡ����
int Person::getAge()
{

	return m_Age;
}
//��������
void Person::setAge(int age)
{
	if (age < 0 || age>150)
	{
		m_Age = 0;
		cout << "�����������" << endl;
		return;
	}
	m_Age = age;
}
//��������
void Person::setLover(string lover)
{
	m_Lover = lover;
}
