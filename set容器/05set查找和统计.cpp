#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//����������
//��set�������в��������Լ�ͳ������
//
//����ԭ�ͣ�
//find(key);                   //����key�Ƿ����,�����ڣ����ظü���Ԫ�صĵ��������������ڣ�����set.end();
//count(key);                 //ͳ��key��Ԫ�ظ���,����set,count��ֵ�޷���0��1


#include <set>

//���Һ�ͳ��
void test01()
{
	set<int> s1;
	//����
	s1.insert(10);
	s1.insert(30);
	s1.insert(20);
	s1.insert(30);
	s1.insert(30);
	s1.insert(30);
	s1.insert(30);
	s1.insert(40);

	multiset<int> s2; 
	s2.insert(30);
	s2.insert(30);
	s2.insert(30);
	s2.insert(30);
	s2.insert(30);
	s2.insert(30);
	s2.insert(10);
	s2.insert(30);
	s2.insert(20);
	s2.insert(40);

	//����
	set<int>::iterator pos1 = s1.find(30);
	set<int>::iterator pos2 = s2.find(30);


	if (pos1 != s1.end())
	{
		cout << "s1�ҵ���Ԫ�� �� " << *pos1 << endl;
	}
	else
	{
		cout << "s1δ�ҵ�Ԫ��" << endl;
	}

	if (pos2 != s2.end())
	{
		cout << "s2�ҵ���Ԫ�� �� " << *pos2 << endl;
	}
	else
	{
		cout << "s2δ�ҵ�Ԫ��" << endl;
	}

	//ͳ��
	int num1 = s1.count(30);
	cout << "num1 = " << num1 << endl;

	int num2 = s2.count(30);
	cout << "num2 = " << num2 << endl;
}

int main() 
{

	test01();
	return 0;
}