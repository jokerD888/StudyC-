#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

//概念
//返回bool类型的仿函数称为谓词
//如果operator()接受一个参数，那么叫做一元谓词
//如果operator()接受两个参数，那么叫做二元谓词


#include <vector>
#include <algorithm>

//C++中结构体和类的异同：
//不同之处：
//1、结构体在默认情况下成员是公共的（public），类在默认情况下成员是私有的(private)。
//2、C++结构体内部成员变量及成员函数默认的访问级别是public，而c++类的内部成员变量及成员函数的默认访问级别是private。
//3、C++结构体的继承默认是public，而c++类的继承默认是private。
//4、类要加上public变成共有的才能被访问，而结构本身就是共有的可直接访问。
//相同之处：
//结构体中可以包含函数；也可以定义public、private、protected数据成员；
// 定义了结构体之后，可以用结构体名来创建对象。但C中的结构体不允许有函数；
//也就是说在C++当中，结构体中可以有成员变量，可以有成员函数，可以从别的类继承，也可以被别的类继承，可以有虚函数。

//一元谓词
class GreaterFive
{
public:
	bool operator()(int val)
	{
		return val > 5;
	}
};
//或
//struct GreaterFive//C++中的结构体相当于一个特殊的类 
//{
//	bool operator()(int val)
//	{
//		return val > 5;
//	}
//};

void test01() 
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	vector<int>::iterator it = find_if(v.begin(), v.end(), GreaterFive());//find_if按条件查找
	if (it == v.end())
	{
		cout << "没找到!" << endl;
	}
	else 
	{
		cout << "找到:" << *it << endl;
	}

}


//二元谓词

class MyCompare
{
public:
	bool operator()(int num1, int num2)
	{
		return num1 > num2;
	}
};

void test02()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(40);
	v.push_back(20);
	v.push_back(30);
	v.push_back(50);

	//默认从小到大
	sort(v.begin(), v.end());
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	cout << "----------------------------" << endl;

	//使用函数对象改变算法策略，排序从大到小
	sort(v.begin(), v.end(), MyCompare());
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

int main() 
{
	test01();
	test02();
	return 0;
}
