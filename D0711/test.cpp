#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<stdio.h>
int& test01()
{
	static int a = 10;
	return a;
}
int func(int a, int b = 20, int c = 30) 
{
	return a + b + c;
}
int main(void)
{
	/*C++程序在执行时，将内存大方向划分为 4个区域
		-代码区：存放函数体的二进制代码，由操作系统进行管理的
		- 全局区：存放全局变量和静态变量以及常量
		- 栈区：由编译器自动分配释放, 存放函数的参数值, 局部变量等
		- 堆区：由程序员分配和释放, 若程序员不释放, 程序结束时由操作系统回收*/
	//全局区中数据：全局变量，静态变量，字符串常量，const修饰的全局变量（全局常量）


	//new关键字
	//C++中利用 == new == 操作符在堆区开辟数据
	//堆区开辟的数据，由程序员手动开辟，手动释放，释放利用操作符delete
	//语法： new 数据类型
	//利用new创建的数据，会返回该数据对应的类型的指针
	
	int* n_a = new int(10);//在堆区创建了一个int型的内存空间，并初始化为10；
	//相当于c语言中如下两句
	int* m_a = (int*)malloc(sizeof(int));
	*m_a = 10;
	cout << *n_a << endl;
	cout << *m_a << endl;

	//释放
	delete n_a;//如果内存已经释放了，再次访问就是非法操作，会引起异常
	delete m_a;
	/*free(n_a);
	free(m_a);*/
	/*cout << n_a << endl;
	cout << m_a << endl;

	cout << *n_a << endl;
	cout << *m_a << endl;*/


	//在堆区利用new开辟数组
	int* arr=new int[10];//开辟了10个整型数组的空间
	for (int i = 0; i < 10; i++)
	{
		arr[i] = i;
	}
	for (int i = 0; i < 10; i++)
	{
		cout<<arr[i] << endl;
	}
	//释放堆区数组(要加[])
	delete[] arr;

	//引用
	//作用：给变量起别名
	//语法: 数据类型& 别名 = 原名
	int a=8;
	//本质：//自动转换为 int* const b = &a; 指针常量是指针指向不可改，也说明为什么引用不可更改
	int& b = a;//引用必须要初始化，一旦初始化后不可更改(指向） 
	b = 10; //相当于：* b = 20,
	cout << b << endl;
	int c = 20;
	b = c;//这是赋值操作了，而不是更改引用了
	cout << b << endl;
	//通过引用参数产生的效果同按地址传递是一样的，使用起来更简单

	//引用做函数的返回值
	//1.不要返回局部变量的引用
	//2.如果函数的返回值是引用，函数的调用可以作为左值
	int& ref = test01();
	cout << ref << endl;
	cout << ref << endl;
	test01() = 20;
	cout << ref << endl;
	cout << ref << endl;

	//常量引用
	//使用场景：用来修饰形参，防止误操作
	int d = 11;
	//int& ref1 = 11;//报错，引用必须引用一块合法的内存空间（栈或堆区的数据）
	const int& ref1 = 22;//正确操作
	//加上const以后，编译器将代码修改为：int tmp=10;	const int& ref=tmp;
	//加上之后就不可以修改了,如ref1=33是不被允许的


	//函数默认参数
	//1. 如果某个位置参数有默认值，那么从这个位置往后，从左向右，必须都要有默认值
	//2. 如果函数声明有默认值，函数实现的时候就不能有默认参数
	cout << func(1, 3, 5) << endl;
	cout << func(10) << endl;	//当不给函数传递参数是，函数形参使用默认参数


	//函数占位参数

	return 0;
}
