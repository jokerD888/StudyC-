#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;
//�㷨��飺
//sort`             //��������Ԫ�ؽ�������
//random_shuffle`   //ϴ��   ָ����Χ�ڵ�Ԫ�������������
//merge `           // ����Ԫ�غϲ������洢����һ������
//reverse`       // ��תָ����Χ��Ԫ��


//sort(iterator beg, iterator end, _Pred);  (Ĭ�ϴ�С��������
//  beg    ��ʼ������
//  end    ����������
// _Pred  ν��


#include <algorithm>
#include <vector>

void myPrint(int val)
{
	cout << val << " ";
}

void test01() 
{
	vector<int> v;
	v.push_back(10);
	v.push_back(30);
	v.push_back(50);
	v.push_back(20);
	v.push_back(40);

	//sortĬ�ϴ�С��������
	sort(v.begin(), v.end());
	for_each(v.begin(), v.end(), myPrint);
	cout << endl;

	//�Ӵ�С����
	sort(v.begin(), v.end(), greater<int>());
	for_each(v.begin(), v.end(), myPrint);
	cout << endl;
}

int main()
{

	test01();

	return 0;
}