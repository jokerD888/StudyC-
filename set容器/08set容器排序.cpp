#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

//学习目标：
//set容器默认排序规则为从小到大，掌握如何改变排序规则
//主要技术点：
//利用仿函数，可以改变排序规则

#include <set>
//set存放内置数据类型
class MyCompare
{
public:
	bool operator()(int v1, int v2) const//vs2019需要加在此加
	{
		return v1 > v2;
	}
};
void test01()
{
	set<int> s1;
	s1.insert(10);
	s1.insert(40);
	s1.insert(20);
	s1.insert(30);
	s1.insert(50);

	//默认从小到大
	for (set<int>::iterator it = s1.begin(); it != s1.end(); it++) 
	{
		cout << *it << " ";
	}
	cout << endl;

	//指定排序规则
	set<int, MyCompare> s2;
	s2.insert(10);
	s2.insert(40);
	s2.insert(20);
	s2.insert(30);
	s2.insert(50);

	for (set<int, MyCompare>::iterator it = s2.begin(); it != s2.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

//set存放自定义数据类型
class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

	//也可以利用重载<运算符来对自定义的数据类型进行比较
	bool operator<(const Person& p1) const
	{
		return this->m_Age < p1.m_Age;//这里改成大于就是降序，小于就是升序
	}

	string m_Name;
	int m_Age;

};
//可以用仿函数，也可以重载Person<比较运算符
class ComparePerson
{
public:
	bool operator()(const Person& p1, const Person& p2) const
	{
		//按照年龄进行排序降序，但如果有相等的，按照set的定义则不会插入
		return p1.m_Age > p2.m_Age;
	}
};

void test02()
{
	//自定义数据类型都会指定排序规则
	set<Person, ComparePerson> s;

	Person p1("刘备", 23);
	Person p2("关羽", 27);
	Person p3("张飞", 25);
	Person p4("赵云", 21);
	Person p5("马超", 27);


	s.insert(p1);
	s.insert(p2);
	s.insert(p3);
	s.insert(p4);
	s.insert(p5);


	for (set<Person, ComparePerson>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << "姓名： " << it->m_Name << " 年龄： " << it->m_Age << endl;
	}
}
void test03()
{
	set<Person> s;

	Person p1("刘备", 23);
	Person p2("关羽", 27);
	Person p3("张飞", 25);
	Person p4("赵云", 21);
	Person p5("马超", 27);


	s.insert(p1);
	s.insert(p2);
	s.insert(p3);
	s.insert(p4);
	s.insert(p5);


	for (set<Person>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << "姓名： " << it->m_Name << " 年龄： " << it->m_Age << endl;
	}
}
int main()
{

	//test01();
	//test02();
	test03();
	return 0;
}
