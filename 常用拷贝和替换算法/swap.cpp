#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

//����������
//��������������Ԫ��
//����ԭ�ͣ�
//swap(container c1, container c2);  
// ��������������Ԫ��
// c1����1
// c2����2
//swap��������ʱ��ע�⽻��������Ҫͬ������ 
#include <algorithm>
#include <vector>

class myPrint
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};

void test01()
{
	vector<int> v1;
	vector<int> v2;
	for (int i = 0; i < 10; i++) 
	{
		v1.push_back(i);
		v2.push_back(i + 100);
	}

	cout << "����ǰ�� " << endl;
	for_each(v1.begin(), v1.end(), myPrint());
	cout << endl;
	for_each(v2.begin(), v2.end(), myPrint());
	cout << endl;

	cout << "������ " << endl;
	swap(v1, v2);
	for_each(v1.begin(), v1.end(), myPrint());
	cout << endl;
	for_each(v2.begin(), v2.end(), myPrint());
	cout << endl;
}

int main() 
{
	test01();

	return 0;
}
