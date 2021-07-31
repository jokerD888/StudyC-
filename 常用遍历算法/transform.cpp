#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
using namespace std;

//����������
//������������һ��������
//
//����ԭ�ͣ�
//transform(iterator beg1, iterator end1, iterator beg2, _func); 
//beg1 Դ������ʼ������
//end1 Դ��������������
//beg2 Ŀ��������ʼ������
//_func �������ߺ�������
//ע�⣺���˵�Ŀ����������Ҫ��ǰ���ٿռ䣬�����޷���������

#include<vector>
#include<algorithm>

//���ñ����㷨  ���� transform

class TransForm
{
public:
	int operator()(int val)//��ֻ����Ҫԭ����ת�ƣ�ֻ��return val���ɣ�Ҳ���Զ�ԭ������һЩ������ת��
	{
		return val+10;
	}

};

class MyPrint
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};

void test01()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	for_each(v.begin(), v.end(), MyPrint());
	cout << endl;

	vector<int>vTarget; //Ŀ������

	vTarget.resize(v.size()); // Ŀ��������Ҫ��ǰ���ٿռ�

	transform(v.begin(), v.end(), vTarget.begin(), TransForm());

	for_each(vTarget.begin(), vTarget.end(), MyPrint());
}

int main()
{

	test01();
	return 0;
}

