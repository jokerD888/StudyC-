#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;
//
//����������
//��������Ԫ�ؽ��з�ת
//
//����ԭ�ͣ�
//reverse(iterator beg, iterator end);  
// ��תָ����Χ��Ԫ��
// beg ��ʼ������
// end ����������


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
	vector<int> v;
	v.push_back(10);
	v.push_back(30);
	v.push_back(50);
	v.push_back(20);
	v.push_back(40);

	cout << "��תǰ�� " << endl;
	for_each(v.begin(), v.end(), myPrint());
	cout << endl;

	cout << "��ת�� " << endl;

	reverse(v.begin(), v.end());
	for_each(v.begin(), v.end(), myPrint());
	cout << endl;
}

int main() 
{

	test01();

	return 0;
}
