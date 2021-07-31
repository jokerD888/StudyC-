#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

//����������
//ʵ�ֱ�������
//
//����ԭ�ͣ�
//for_each(iterator beg, iterator end, _func);  ʵ�ʵײ�Ҳ�ǵ�����forѭ������
// �����㷨 ��������Ԫ��
// beg ��ʼ������
// end ����������
// _func �������ߺ�������

#include <algorithm>
#include <vector>

//��ͨ����
void print01(int val)
{
	cout << val << " ";
}
//��������
class print02
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};

//for_each�㷨�����÷�
void test01() 
{

	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	//�����㷨
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
