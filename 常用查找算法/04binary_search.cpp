#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

//����������
//����ָ��Ԫ���Ƿ���ڣ�����������,Ĭ������
//����ԭ��
//bool binary_search(iterator beg, iterator end, value); 


// ����ָ����Ԫ�أ��鵽 ����true  ����false
// ע��: �����������в�����
// beg ��ʼ������
// end ����������
// value ���ҵ�Ԫ��


#include <algorithm>
#include <vector>
#include<functional>
//Ĭ������������
void MyPrint(int val)
{
	cout << val << " ";
}
void test01()
{
	//����һ����������
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	for_each(v.begin(), v.end(), MyPrint);
	cout << endl;

	//���ֲ���
	bool ret = binary_search(v.begin(), v.end(), 3);
	if (ret)
	{
		cout << "�ҵ���" << endl;
	}
	else
	{
		cout << "δ�ҵ�" << endl;
	}
}

//------------------����������--------------------
//��������������������ֶ��巽������ͨ�����������������ú�������
//��ͨ����
bool MySort01(const int a,const int b)
{
	return a > b;
}
class MySort02
{
public:
	bool operator()(const int a, const int b)
	{
		return a > b;
	}
};
void test02()
{
	vector<int> v;

	for (int i = 0; i < 10; i++)
	{
		v.push_back(9-i);
	}
	for_each(v.begin(), v.end(), MyPrint);
	cout << endl;

	int ret = binary_search(v.begin(), v.end(),6 , MySort01);//��ͨ����
	//int ret = binary_search(v.begin(), v.end(), 6, MySort02());//��������
	//int ret = binary_search(v.begin(), v.end(), 6, greater<int>());//���ú�������

	if (ret)
	{
		cout << "�ҵ���" << endl;
	}
	else
	{
		cout << "δ�ҵ�" << endl;
	}

}

int main() 
{
	test01();
	test02();
	return 0;
}

