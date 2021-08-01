#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

//功能描述：
//计算区间内 容器元素累计总和
//
//函数原型：
//accumulate(iterator beg, iterator end, value);  
// 计算容器元素累计总和
// beg 开始迭代器
// end 结束迭代器
// value 起始值
//accumulate使用时头文件注意是 numeric，这个算法很实用



#include <numeric>
#include <vector>
void test01()
{
	vector<int> v;
	for (int i = 0; i <= 100; i++) 
	{
		v.push_back(1);
	}

	int total = accumulate(v.begin(), v.end(), 100);

	cout << "total = " << total << endl;
}

int main() 
{
	test01();
	return 0;
}
