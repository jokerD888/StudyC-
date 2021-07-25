#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;
//Person类模板声明
template<class T1,class T2>
class Person;

//声明，若不想声明就将实现提前
template<class T1,class T2>
void PrintPerson2(Person<T1, T2>& p);

//类模板
template<class T1,class T2>
class Person
{
	//全局函数配合友元-类内实现
	friend void PrintPerson(Person<T1, T2>& p)
	{
		cout << "name: " << p.m_Name << "\tage：" << p.m_Age << endl;
	}

	//类外实现
	friend void PrintPerson2<>(Person<T1, T2>& p);//注意这里的函数明前的空参数列表<>，是为告诉编译器这是一个函数模板的声明
public:
	Person(T1 name, T2 age)
	{
		this->m_Age = age;
		this->m_Name = name;
	}

private:
	T1 m_Name;
	T2 m_Age; 
};
//类外实现全局函数
template<class T1,class T2>
void PrintPerson2(Person<T1, T2>& p)
{
	cout << "name: " << p.m_Name << "\tage：" << p.m_Age << endl;
}
//类内
void test01()
{
	Person<string, int> p("Tom", 18);
	PrintPerson(p);
}
//类外
void test02()
{
	Person<string, int> p("Jerry", 19);
	PrintPerson2(p);
}
int main(void)
{

	test01();
	test02();
	return 0;
}
