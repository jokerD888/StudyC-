#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

//ѧϰĿ�꣺
//map����Ĭ���������Ϊ ����keyֵ���� ��С��������������θı��������
//
//��Ҫ������:
//���÷º��������Ըı��������

#include <map>

//������������
class MyCompare 
{
public:
	bool operator()(int v1, int v2) const
	{
		return v1 > v2;
	}
};

void test01()
{
	//Ĭ�ϴ�С��������
	//���÷º���ʵ�ִӴ�С����
	map<int, int, MyCompare> m;

	m.insert(make_pair(1, 10));
	m.insert(make_pair(2, 20));
	m.insert(make_pair(3, 30));
	m.insert(make_pair(4, 40));
	m.insert(make_pair(5, 50));

	for (map<int, int, MyCompare>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key:" << it->first << " value:" << it->second << endl;
	}
}

//�Զ�����������
class Person
{
public:
	Person(string name, int age)
	{
		this->m_Age = age;
		this->m_Name = name;
	}

	string m_Name;
	int m_Age;
};

class MyComparePerson
{
public:
	bool operator()(const Person& p1, const Person& p2) const
	{
		return p1.m_Age > p2.m_Age;//����
	}
};
void test02()
{
	map<Person, int, MyComparePerson> m1;
	Person p1("�ŷ�",28);
	Person p2("����",25);
	Person p3("����",30);
	Person p4("����",29);
	Person p5("��",26);

	//����
	m1.insert(make_pair(p1, 1));
	m1.insert(make_pair(p2, 2));
	m1.insert(make_pair(p3, 5));
	m1.insert(make_pair(p4, 4));
	m1.insert(make_pair(p5, 3));

	for (map<Person, int, MyComparePerson>::iterator it = m1.begin(); it != m1.end(); it++)
	{
		cout << "key: ������" << it->first.m_Name << " ���䣺" << it->first.m_Age<< " value: " << it->second << endl;

	}

}
int main() 
{

	//test01();
	test02();
	return 0;
}
