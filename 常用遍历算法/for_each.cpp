#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

//功能描述：
//实现遍历容器
//
//函数原型：
//for_each(iterator beg, iterator end, _func);  实际底层也是迭代器for循环遍历
// 遍历算法 遍历容器元素
// beg 开始迭代器
// end 结束迭代器
// _func 函数或者函数对象

#include <algorithm>
#include <vector>

//普通函数
void print01(int val)
{
	cout << val << " ";
}
//函数对象
class print02
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};

//for_each算法基本用法
void test01() 
{

	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	//遍历算法
	for_each(v.begin(), v.end(), print01);
	cout << endl;

	for_each(v.begin(), v.end(), print02());
	cout << endl;
}

int main()
{
	test01();
	return 0;
}
