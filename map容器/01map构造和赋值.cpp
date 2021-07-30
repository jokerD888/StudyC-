#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

//map��������
//map������Ԫ�ض���pair
//pair�е�һ��Ԫ��Ϊkey����ֵ�������������ã��ڶ���Ԫ��Ϊvalue��ʵֵ��
//����Ԫ�ض������Ԫ�صļ�ֵ�Զ�����
//
//���ʣ�
//map / multimap���� ����ʽ���� ���ײ�ṹ���ö�����ʵ�֡�
//
//�ŵ㣺 
//���Ը���keyֵ�����ҵ�valueֵ
//
//map��multimap ����  ��
//map���������������ظ�keyֵԪ��
//multimap�������������ظ�keyֵԪ��
//
//map����͸�ֵ
//����������
//��map�������й���͸�ֵ����
//
//����ԭ�ͣ�
//���죺
//map<T1, T2 > mp;                     //mapĬ�Ϲ��캯��: 
//map(const map& mp);              //�������캯��
//��ֵ��
//map& operator=(const map& mp);     //���صȺŲ�����


#include <map>

void printMap(map<int, int>& m)
{
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key = " << it->first << " value = " << it->second << endl;
	}
	cout << endl;
}

void test01()
{
	map<int, int>m; //Ĭ�Ϲ���
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(4, 40));
	m.insert(pair<int, int>(3, 30));
	printMap(m);

	map<int, int>m2(m); //��������
	printMap(m2);

	map<int, int>m3;
	m3 = m2; //��ֵ
	printMap(m3);
}

int main() 
{

	test01();
	return 0;
}

