#define _CRT_SECURE_NO_WARNINGS 1
#pragma noce
#include<iostream>
//#include<string>
using namespace std;
class Person
{
public:
	//设置姓名
	void setName(string name);
	
	//获取姓名
	string getName();

	//获取年龄
	int getAge();
	
	//设置年龄
	void setAge(int age);
	
	
	//设置情人
	void setLover(string lover);
	
private:
	//姓名	可读可写
	string m_Name;
	//年龄 可读可写
	int m_Age;
	//情人	只写
	string m_Lover;

};