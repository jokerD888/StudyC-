#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//功能描述：
//对set容器进行查找数据以及统计数据
//
//函数原型：
//find(key);                   //查找key是否存在,若存在，返回该键的元素的迭代器；若不存在，返回set.end();
//count(key);                 //统计key的元素个数,对于set,count的值无非是0或1


#include <set>

//查找和统计
void test01()
{
	set<int> s1;
	//插入
	s1.insert(10);
	s1.insert(30);
	s1.insert(20);
	s1.insert(30);
	s1.insert(30);
	s1.insert(30);
	s1.insert(30);
	s1.insert(40);

	multiset<int> s2; 
	s2.insert(30);
	s2.insert(30);
	s2.insert(30);
	s2.insert(30);
	s2.insert(30);
	s2.insert(30);
	s2.insert(10);
	s2.insert(30);
	s2.insert(20);
	s2.insert(40);

	//查找
	set<int>::iterator pos1 = s1.find(30);
	set<int>::iterator pos2 = s2.find(30);


	if (pos1 != s1.end())
	{
		cout << "s1找到了元素 ： " << *pos1 << endl;
	}
	else
	{
		cout << "s1未找到元素" << endl;
	}

	if (pos2 != s2.end())
	{
		cout << "s2找到了元素 ： " << *pos2 << endl;
	}
	else
	{
		cout << "s2未找到元素" << endl;
	}

	//统计
	int num1 = s1.count(30);
	cout << "num1 = " << num1 << endl;

	int num2 = s2.count(30);
	cout << "num2 = " << num2 << endl;
}

int main() 
{

	test01();
	return 0;
}