#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//����������
//����vector�ڶ�̬��չ����ʱ����չ����,����������ϴ󣬿���һ��ʼ����reserveԤ���ռ�
//
//����ԭ�ͣ�
//reserve(int len); //����Ԥ��len��Ԫ�س��ȣ�Ԥ��λ�ò���ʼ����Ԫ�ز��ɷ��ʡ�




#include <vector>

void test01()
{
	vector<int> v;

	//Ԥ���ռ�
	v.reserve(100000);

	int num = 0;
	int* p = NULL;
	for (int i = 0; i < 100000; i++) 
	{
		v.push_back(i);
		if (p != &v[0]) 
		{
			p = &v[0];
			num++;
		}
	}

	cout << "num:" << num << endl;
}

int main() 
{

	test01();
	return 0;
}