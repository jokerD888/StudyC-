#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//函数原型：
//reverse();    //反转链表
//sort();        //链表排序

#include<list>
void printList(const list<int>& L) 
{

	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++) 
	{
		cout << *it << " ";
	}
	cout << endl;
}

bool myCompare(int val1, int val2)
{
	return val1 > val2;
}

//反转和排序
void test01()
{
	list<int> L;
	L.push_back(90);
	L.push_back(30);
	L.push_back(20);
	L.push_back(70);
	cout << "反转前：" << endl;
	printList(L);

	//反转容器的元素
	L.reverse();
	cout << "反转后：" << endl;
	printList(L);

	//排序
	L.sort(); //默认的排序规则 从小到大
	cout << "升序：" << endl;

	printList(L);

	L.sort(myCompare); //指定规则，从大到小
	cout << "降序：" << endl;
	printList(L);
}

int main() {

	test01();

	return 0;
}

