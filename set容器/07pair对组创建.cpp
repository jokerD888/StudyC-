#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//����������
//�ɶԳ��ֵ����ݣ����ö�����Է����������ݡ��纯������ֻ�ܷ���һ��ֵ�������Ҫ��������ֵ���Ϳ��Խ������鷵��
//
//���ִ�����ʽ
//pair<type, type > p(value1, value2); 
//pair<type, type > p = make_pair(value1, value2); 

//���鴴��
void test01()
{
	pair<string, int> p(string("Tom"), 20);
	cout << "������ " << p.first << " ���䣺 " << p.second << endl;

	pair<string, int> p2 = make_pair("Jerry", 10);
	cout << "������ " << p2.first << " ���䣺 " << p2.second << endl;
}

int main() 
{

	test01();
	return 0;
}

