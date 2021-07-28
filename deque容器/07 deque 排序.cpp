#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

//算法：(记得包含算法头文件)
//sort(iterator beg, iterator end)  //对beg和end区间内元素进行排序

#include <deque>
#include <algorithm>

void printDeque(const deque<int>& d)
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++) 
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test01()
{

	deque<int> d;
	d.push_back(10);
	d.push_back(20);
	d.push_front(30);
	d.push_front(40);
	printDeque(d);

	sort(d.begin(), d.end());
	printDeque(d);

}

int main() 
{

	test01();
	return 0;
}