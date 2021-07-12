#define _CRT_SECURE_NO_WARNINGS 1
#include"person.h"

void Person::setName(string name)
{
	m_Name = name;
}
//获取姓名
string Person::getName()
{
	return m_Name;
}
//获取年龄
int Person::getAge()
{

	return m_Age;
}
//设置年龄
void Person::setAge(int age)
{
	if (age < 0 || age>150)
	{
		m_Age = 0;
		cout << "你这个老妖精" << endl;
		return;
	}
	m_Age = age;
}
//设置情人
void Person::setLover(string lover)
{
	m_Lover = lover;
}
