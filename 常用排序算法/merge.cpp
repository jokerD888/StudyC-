#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

//����������
//��������Ԫ�غϲ������洢����һ�����У��ϲ��껹������ġ�
//
//����ԭ�ͣ�
//merge(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);  

// ����Ԫ�غϲ������洢����һ������
// ע��: �������������������
// beg1   ����1��ʼ������
// end1   ����1����������
// beg2   ����2��ʼ������
// end2   ����2����������
// dest    Ŀ��������ʼ������


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

//ԭ��������
void test01()
{
	vector<int> v1;
	vector<int> v2;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 1);
	}

	vector<int> vtarget;
	//Ŀ��������Ҫ��ǰ���ٿռ�
	vtarget.resize(v1.size() + v2.size());
	//�ϲ�  ��Ҫ������������
	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), vtarget.begin());
	for_each(vtarget.begin(), vtarget.end(), myPrint());
	cout << endl;
}

//ԭ��������
void test02()
{
	vector<int> v1;
	vector<int> v2;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(9-i);
		v2.push_back(10-i);
	}

	vector<int> vtarget;
	//Ŀ��������Ҫ��ǰ���ٿռ�
	vtarget.resize(v1.size() + v2.size());
	//�ϲ�  ��Ҫ������������
	//merge(v1.begin(), v1.end(), v2.begin(), v2.end(), vtarget.begin());
	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), vtarget.begin(), greater<int>());
	for_each(vtarget.begin(), vtarget.end(), myPrint());
	cout << endl;
}

int main() 
{
	test01();

	test02();
	return 0;
}