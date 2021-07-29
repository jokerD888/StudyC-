#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

//��������������set�����Լ���ֵ
//���죺
//set<T > st;                        //Ĭ�Ϲ��캯����
//set(const set& st);     //�������캯��
//
//��ֵ��
//set& operator=(const set& st);  //���صȺŲ�����

//set������������ʱ��insert
//set�����������ݵ����ݻ��Զ�����

#include <set>

void printSet(set<int>& s)
{
	for (set<int>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

//����͸�ֵ
void test01()
{
	set<int> s1;

	s1.insert(10);
	s1.insert(30);
	s1.insert(20);
	s1.insert(40);
	printSet(s1);

	//��������
	set<int>s2(s1);
	printSet(s2);

	//��ֵ
	set<int>s3;
	s3 = s2;
	printSet(s3);
}

int main()
{
	test01();
	return 0;
}