#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;


//函数占位参数
//void func(int a, int,int =20) 
//{
//	cout << "this is func" << endl;
//}

//函数重载
//void func()
//{
//	cout << "func 的调用！" << endl;
//}
//void func(int a)
//{
//	cout << "func (int a) 的调用！" << endl;
//}
//void func(double a)
//{
//	cout << "func (double a)的调用！" << endl;
//}
//void func(int a, double b)
//{
//	cout << "func (int a ,double b) 的调用！" << endl;
//}
//void func(double a, int b)
//{
//	cout << "func (double a ,int b)的调用！" << endl;
//}

//引用作为重载条件
//void func(int& a)
//{
//	cout << "func (int &a) 调用 " << endl;
//}
//
//void func(const int& a)
//{
//	cout << "func (const int &a) 调用 " << endl;
//}

//函数重载碰到函数默认参数
void func2(int a, int b = 10)
{
	cout << "func2(int a, int b = 10) 调用" << endl;
}

void func2(int a)
{
	cout << "func2(int a) 调用" << endl;
}
int main() {
	//函数占位参数 ，占位参数也可以有默认参数
	//用数据类型占位,但调用时要传参数
	//func(10, 10); //占位参数必须填补
	

	//函数重载
	//作用：函数名可以相同，提高复用性
	//函数重载满足条件:
	//1. 同一个作用域下
	//2.函数名称相同
	//3. 函数参数类型不同 或者 个数不同 或者 顺序不同
	// 注意:函数的返回值不可以作为函数重载的条件
	//func();
	//func(10);
	//func(3.14);
	//func(10, 3.14);
	//func(3.14, 10);


	//引用作为重载条件
	//void func(int &a)		void func(const int &a) 两者是可以引起重载的
	//int a = 10;
	//func(a); //调用无const	两者会与void func(int a)产生歧义，需避免
	//func(10);//调用有const
	 
	
	//函数重载碰到函数默认参数
	//func2(10);////碰到默认参数产生歧义，出现二义性，需要避免

	return 0;
}
