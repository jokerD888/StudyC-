#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

//����������
//���������� ����Ԫ���ۼ��ܺ�
//
//����ԭ�ͣ�
//accumulate(iterator beg, iterator end, value);  
// ��������Ԫ���ۼ��ܺ�
// beg ��ʼ������
// end ����������
// value ��ʼֵ
//accumulateʹ��ʱͷ�ļ�ע���� numeric������㷨��ʵ��



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
