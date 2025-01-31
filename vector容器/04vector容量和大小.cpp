﻿#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//功能描述：
//对vector容器的容量和大小操作
//
//函数原型：
//empty();                             //判断容器是否为空
//capacity();                      //容器的容量
//size();                               //返回容器中元素的个数
//resize(int num);     //重新指定容器的长度为num，若容器变长，则以默认值填充新位置。如果容器变短，则末尾超出容器长度的元素被删除。
//resize(int num, elem);   //重新指定容器的长度为num，若容器变长，则以elem值填充新位置。如果容器变短，则末尾超出容器长度的元素被删除
//​			



#include <vector>

void printVector(vector<int>& v) 
{

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) 
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test01()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	printVector(v1);
	if (v1.empty())
	{
		cout << "v1为空" << endl;
	}
	else
	{
		cout << "v1不为空" << endl;
		cout << "v1的容量 = " << v1.capacity() << endl;
		cout << "v1的大小 = " << v1.size() << endl;
	}

	//resize 重新指定大小 ，若指定的更大，默认用0填充新位置，可以利用重载版本替换默认填充
	v1.resize(15, 10);
	printVector(v1);

	//resize 重新指定大小 ，若指定的更小，超出部分元素被删除
	v1.resize(5);
	printVector(v1);
}

//测试容量和大小的关系，大概是扩大原容量的50%
void test02()
{
	vector<int>v;
	int num = 0;
	int* p = NULL;
	for (int i = 0; i < 1000000; i++)
	{
		v.push_back(i);
		if (p != &v[0])
		{
			p = &v[0];
			num++;
			cout << "容量：" << v.capacity() << "\t大小：" << v.size() << endl;
		}
	}
}
int main()
{

	//test01();
	test02();
	return 0;
}