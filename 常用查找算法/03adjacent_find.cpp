#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

/*����������
���������ظ�Ԫ��

����ԭ�ͣ�
adjacent_find(iterator beg, iterator end);*/ 
// ���������ظ�Ԫ��,��������Ԫ�صĵ�һ��λ�õĵ�����
// beg ��ʼ������
// end ����������


#include <algorithm>
#include <vector>

void test01()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(5);
	v.push_back(2);
	v.push_back(4);
	v.push_back(4);
	v.push_back(3);

	//���������ظ�Ԫ��
	vector<int>::iterator it = adjacent_find(v.begin(), v.end());
	if (it == v.end())
	{
		cout << "�Ҳ���!" << endl;
	}
	else 
	{
		cout << "�ҵ������ظ�Ԫ��Ϊ:" << *it << endl;
	}
}

int main(void)
{
	test01();

	return 0;
}