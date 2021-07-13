#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
//1.构造函数的分类及调用
//可分为	 按照参数分类		 无参构造（默认构造）  和		有参构造
//		 按照类型分类		 普通构造	 和		拷贝构造
class Person
{
public:
	//构造函数
	Person()
	{
		cout << "Person的无参构造函数调用" << endl;
	}

	Person(int a)
	{
		age = a;
		cout<< "Person的有参构造函数调用" << endl;
	}

	//拷贝函数构造
	Person(const Person& p)
	{
		//将传入的人的所有属性信息拷贝到“我”身上
		age = p.age;
		cout << "Person的有拷贝参构造函数调用" << endl;
	}

	~Person()
	{
		cout << "Person的析构 函数调用" << endl;
	}

public:
	int age;

};

//调用
void test01()
{
	//1.括号法：
	//Person p1;//默认构造函数调用
	//Person p2(10);//有参函数调用
	//Person p3(p2);//拷贝构造函数调用
	//cout << "p2 age = " << p2.age << endl;
	//cout << "p3 age = " << p3.age << endl;

	//注意：调用默认构造函数时，不要加（）
	//因为Person p1();编译器会认为这是一个函数声明，所以不会创建对象

	//2.显示法：
	Person p1;
	Person p2 = Person(10);
	Person p3 = Person(p2);

	Person(10);//匿名对象	特点：当前执行结束后，系统会立即回收掉匿名对象
	//Person(p3);
	//注意：不要利拷贝构造函数	初始化匿名对象(错误：重定义）	编译器会认为Person(p3)=	Person p3;

	//3.隐式转换法
	Person p4 = 10;
	Person p5 = p4;

	

}
int main(void)
{
	test01();
	return 0;
}
