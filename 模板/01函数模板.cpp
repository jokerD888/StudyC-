#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//模板就是建立通用的模具，大大提高复用性
//模板特点：1.它只是作为一个框架，不可以直接使用；2.模板的通用不是万能的

//函数模板
//作用：建立一个通用函数，其函数返回值类型和形参类型可以不具体制定，用一个虚拟的类型来代表。
//语法：template<typename T>   typename可替换为class   T不是固定命名，可写做其他名称
//其中template 表示声明创建模板  typename 表示其后面的符号是一种数据类型，可用class代替
// T 表示通用的数据类型，名称可替换，通常为大写字母




//交换整型函数
void swapInt(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

//交换浮点型函数
void swapDouble(double& a, double& b) {
	double temp = a;
	a = b;
	b = temp;
}

//利用模板提供通用的交换函数
template<typename T>
void mySwap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

void test01()
{
	int a = 10;
	int b = 20;
	//swapInt(a, b);

//利用模板实现交换
    //1、自动类型推导
	mySwap(a, b);

	//2、显示指定类型
	mySwap<int>(a, b);

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

}


//注意：1.	自动类型推导，必须推导出一致的数据类型T,才可以使用
//      2.  模板必须要确定出T的数据类型，才可以使用

//利用模板提供通用的交换函数
template<class T>
void mySwap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}
// 1、自动类型推导，必须推导出一致的数据类型T,才可以使用
void test02()
{
	int a = 10;
	int b = 20;
	char c = 'c';

	mySwap(a, b); //这里传入的都是int型 正确，可以推导出一致的T
	//mySwap(a, c); // 这里传了int和char两种类型，编译器无法识别T到底是那种类型，错误，推导不出一致的T类型
}


// 2、模板必须要确定出T的数据类型，才可以使用
template<class T>
void func()
{
	cout << "func 调用" << endl;
}

void test02()
{
	//func(); //错误，模板不能独立使用，必须确定出T的类型
	func<int>(); //利用显示指定类型的方式，给T一个类型，才可以使用该模板
}



int main(void)
{
	//test01();//函数模板语法
	test02();//注意事项
	test02();
	return 0;

}