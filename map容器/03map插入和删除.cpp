#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

//����������
//map�������в������ݺ�ɾ������
//
//����ԭ�ͣ�
//insert(elem);     //�������в���Ԫ�ء�
//clear();                    //�������Ԫ��
//erase(pos);               //ɾ��pos��������ָ��Ԫ�أ�������һ��Ԫ�صĵ�������
//erase(beg, end);     //ɾ������[beg,end)������Ԫ�� ��������һ��Ԫ�صĵ�������
//erase(key);             //ɾ��������ֵΪkey��Ԫ�ء�

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
	//����
	map<int, int> m;
	//��һ�ֲ��뷽ʽ
	m.insert(pair<int, int>(1, 10));

	//�ڶ��ֲ��뷽ʽ
	m.insert(make_pair(2, 20));

	//�����ֲ��뷽ʽ�����Ƽ��� 
	m.insert(map<int, int>::value_type(3, 30));

	//�����ֲ��뷽ʽ
	m[4] = 40;

	//cout << m[5] << endl;;//������ʲ��������ᴴ��һ��������ʵֵΪ0
	printMap(m);

	//ɾ��
	m.erase(m.begin());
	printMap(m);

	m.erase(3);//ɾ��ָ����ֵ�Ķ���
	printMap(m);

	//���
	m.erase(m.begin(), m.end());
	m.clear();
	printMap(m);
}

int main() 
{

	test01();
	return 0;
}
