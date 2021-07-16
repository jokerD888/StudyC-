#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;


//问题：当子类与父类出现同名的成员，如何通过子类对象，访问到子类或父类中同名的数据呢？
//访问子类同名成员   直接访问即可
// 访问父类同名成员   需要加作用域
//访问静态成员也一样，不过访问静态成员有两种方法(通过对象名和类名）

//非静态成员--------------------------------------------------------
//class Base {
//public:
//	Base()
//	{
//		m_A = 100;
//	}
//
//	void func()
//	{
//		cout << "Base - func()调用" << endl;
//	}
//
//	void func(int a)
//	{
//		cout << "Base - func(int a)调用" << endl;
//	}
//
//public:
//	int m_A;
//};
//
//
//class Son : public Base 
//{
//public:
//	Son()
//	{
//		m_A = 200;
//	}
//
//	//当子类与父类拥有同名的成员函数，子类会隐藏父类中所有重载的同名成员函数
//	//如果想访问父类中被隐藏的同名成员函数，需要加父类的作用域
//	void func()
//	{
//		cout << "Son - func()调用" << endl;
//	}
//public:
//	int m_A;
//};
//void test01()
//{
//	Son s;
//
//	cout << "Son下的m_A = " << s.m_A << endl;
//	cout << "Base下的m_A = " << s.Base::m_A << endl;
//
//	s.func();
//	s.Base::func();
//	s.Base::func(10);
//
//}
// 
// 
//静态成员----------------------------------------
class Base {
public:
	static void func()
	{
		cout << "Base - static void func()" << endl;
	}
	static void func(int a)
	{
		cout << "Base - static void func(int a)" << endl;
	}

	static int m_A;
};

int Base::m_A = 100;

class Son : public Base {
public:
	static void func()
	{
		cout << "Son - static void func()" << endl;
	}
	static int m_A;
};

int Son::m_A = 200;

//同名成员属性
void test01()
{
	//通过对象访问
	cout << "通过对象访问： " << endl;
	Son s;
	cout << "Son  下 m_A = " << s.m_A << endl;
	cout << "Base 下 m_A = " << s.Base::m_A << endl;

	//通过类名访问
	cout << "通过类名访问： " << endl;
	cout << "Son  下 m_A = " << Son::m_A << endl;
	cout << "Base 下 m_A = " << Son::Base::m_A << endl;
}

//同名成员函数
void test02()
{
	//通过对象访问
	cout << "通过对象访问： " << endl;
	Son s;
	s.func();
	s.Base::func();

	cout << "通过类名访问： " << endl;
	Son::func();
	Son::Base::func();
	//出现同名，子类会隐藏掉父类中所有同名成员函数，需要加作作用域访问
	Son::Base::func(100);
}


int main() {

	test01();
	test02();
	return 0;
}
