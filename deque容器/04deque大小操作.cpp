#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;
//
//����ԭ�ͣ�
//
//deque.empty();                      //�ж������Ƿ�Ϊ��
//deque.size();                         //����������Ԫ�صĸ���
//deque.resize(num);      //����ָ�������ĳ���Ϊnum,�������䳤������Ĭ��ֵ�����λ�á����������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ����
//deque.resize(num, elem);    //����ָ�������ĳ���Ϊnum,�������䳤������elemֵ�����λ�á����������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ����
//

#include <deque>

void printDeque(const deque<int>& d)
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++) 
	{
		cout << *it << " ";
	}
	cout << endl;
}

//��С����
void test01()
{
	deque<int> d1;
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}
	printDeque(d1);

	//�ж������Ƿ�Ϊ��
	if (d1.empty()) {
		cout << "d1Ϊ��!" << endl;
	}
	else {
		cout << "d1��Ϊ��!" << endl;
		//ͳ�ƴ�С
		cout << "d1�Ĵ�СΪ��" << d1.size() << endl;
	}

	//����ָ����С
	d1.resize(15, 1);
	printDeque(d1);

	d1.resize(5);
	printDeque(d1);
}

int main() 
{

	test01();
	return 0;
}