#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

//类模板作用：
//建立一个通用类，类中的成员 数据类型可以不具体制定，用一个虚拟的类型来代表。
//语法：
//template<typename T>
//类

//类模板
template<class NameType, class AgeType>
class Person
{
public:
	Person(NameType name, AgeType age)
	{
		this->mName = name;
		this->mAge = age;
	}
	void showPerson()
	{
		cout << "name: " << this->mName << " age: " << this->mAge << endl;
	}
public:
	NameType mName;
	AgeType mAge;
};

void test01()
{
	// 指定NameType 为string类型，AgeType 为 int类型
	Person<string, int>P1("孙悟空", 999);
	P1.showPerson();
}



int main(void)
{
	return 0;
}
