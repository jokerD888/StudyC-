#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
//#include<string>
using namespace std;
#include"person.h"
//成员属性设置为私有
//1.自己可以控制读写权限
//2.对于写，可以检测数据的有效性
//class Person
//{
//public:
//	//设置姓名
//	void setName(string name)
//	{
//		m_Name = name;
//	}
//	//获取姓名
//	string getName()
//	{
//		return m_Name;
//	}
//	//获取年龄
//	int getAge()
//	{
//		
//		return m_Age;
//	}
//	//设置年龄
//	void setAge(int age)
//	{
//		if (age < 0 || age>150)
//		{
//			m_Age = 0;
//			cout << "你这个老妖精" << endl;
//			return;
//		}
//		m_Age = age;
//	}
//	//设置情人
//	void setLover(string lover)
//	{
//		m_Lover = lover;
//	}
//private:
//	//姓名	可读可写
//	string m_Name;
//	//年龄 可读可写
//	int m_Age;
//	//情人	只写
//	string m_Lover;
//
//};

int main(void)
{
	Person p;
	p.setName("李四");
	cout <<"姓名为:"<< p.getName() << endl;

	//p.m_Age = 18;	//报错，不可访问
	p.setAge(1008);
	cout << "年龄为:"<<p.getAge() << endl;

	p.setLover("zlm");
	
	return 0;
}