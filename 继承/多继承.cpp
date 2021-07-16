#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//C++允许 一个类继承多个类*
//语法： class 子类 ：继承方式 父类1 ， 继承方式 父类2...
//但多继承可能会引发父类中有同名成员出现，需要加作用域区分，C++实际开发中不建议用多继承
//多继承中如果父类中出现了同名情况，子类使用时候要加作用域

class Base1 {
public:
	Base1()
	{
		m_A = 100;
	}
public:
	int m_A;
};

class Base2 {
public:
	Base2()
	{
		m_A = 200;  //开始是m_B 不会出问题，但是改为mA就会出现不明确
	}
public:
	int m_A;
};

//语法：class 子类：继承方式 父类1 ，继承方式 父类2 
class Son : public Base2, public Base1
{
public:
	Son()
	{
		m_C = 300;
		m_D = 400;
	}
public:
	int m_C;
	int m_D;
};


//多继承容易产生成员同名的情况
//通过使用类名作用域可以区分调用哪一个基类的成员
void test01()
{
	Son s;
	cout << "sizeof Son = " << sizeof(s) << endl;
	cout << s.Base1::m_A << endl;
	cout << s.Base2::m_A << endl;
}

//--------------------------------------------------------
//菱形继承
//概念:
//​两个派生类继承同一个基类
//​又有某个类同时继承者两个派生类
//这种继承被称为菱形继承，或者钻石继承

class Animal
{
public:
	int m_Age;
};

//继承前加virtual关键字后，变为虚继承
//此时公共的父类Animal称为虚基类
class Sheep : virtual public Animal {};
class Tuo : virtual public Animal {};
class SheepTuo : public Sheep, public Tuo {};

void test02()
{
	SheepTuo st;
	st.Sheep::m_Age = 100;
	st.Tuo::m_Age = 200;	//最终的m_Age的值是调用前是最后一次赋的值

	cout << "st.Sheep::m_Age = " << st.Sheep::m_Age << endl;
	cout << "st.Tuo::m_Age = " << st.Tuo::m_Age << endl;
	cout << "st.m_Age = " << st.m_Age << endl;
}


int main() {

	test01();
	test02();
	return 0;
}
