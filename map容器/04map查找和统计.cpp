#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

//����������
//��map�������в��������Լ�ͳ������
//
//����ԭ�ͣ�
//find(key);              //����key�Ƿ����,�����ڣ����ظü���Ԫ�صĵ��������������ڣ�����set.end();
//count(key);                 //ͳ��key��Ԫ�ظ���������map�޷���0��1


#include <map>

//���Һ�ͳ��
void test01()
{
	map<int, int>m;
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(3, 30));
	m.insert(pair<int, int>(3, 30));
	m.insert(pair<int, int>(3, 30));
	m.insert(pair<int, int>(3, 30));


	multimap<int, int> m1;
	m1.insert(pair<int, int>(1, 10));
	m1.insert(pair<int, int>(2, 20));
	m1.insert(pair<int, int>(3, 30));
	m1.insert(pair<int, int>(3, 30));
	m1.insert(pair<int, int>(3, 30));
	m1.insert(pair<int, int>(3, 30));

	//����
	map<int, int>::iterator pos = m.find(3);

	if (pos != m.end())
	{
		cout << "�ҵ���Ԫ�� key = " << pos->first << " value = " << (*pos).second << endl;
	}
	else
	{
		cout << "δ�ҵ�Ԫ��" << endl;
	}

	//ͳ��
	int num = m.count(3);
	cout << "num = " << num << endl;

	int num1 = m1.count(3);
	cout << "num1 = " << num1 << endl;
}

int main() 
{

	test01();

	return 0;
}