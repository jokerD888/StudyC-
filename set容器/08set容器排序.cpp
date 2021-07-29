#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

//ѧϰĿ�꣺
//set����Ĭ���������Ϊ��С����������θı��������
//��Ҫ�����㣺
//���÷º��������Ըı��������

#include <set>
//set���������������
class MyCompare
{
public:
	bool operator()(int v1, int v2) const//vs2019��Ҫ���ڴ˼�
	{
		return v1 > v2;
	}
};
void test01()
{
	set<int> s1;
	s1.insert(10);
	s1.insert(40);
	s1.insert(20);
	s1.insert(30);
	s1.insert(50);

	//Ĭ�ϴ�С����
	for (set<int>::iterator it = s1.begin(); it != s1.end(); it++) 
	{
		cout << *it << " ";
	}
	cout << endl;

	//ָ���������
	set<int, MyCompare> s2;
	s2.insert(10);
	s2.insert(40);
	s2.insert(20);
	s2.insert(30);
	s2.insert(50);

	for (set<int, MyCompare>::iterator it = s2.begin(); it != s2.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

//set����Զ�����������
class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

	//Ҳ������������<����������Զ�����������ͽ��бȽ�
	bool operator<(const Person& p1) const
	{
		return this->m_Age < p1.m_Age;//����ĳɴ��ھ��ǽ���С�ھ�������
	}

	string m_Name;
	int m_Age;

};
//�����÷º�����Ҳ��������Person<�Ƚ������
class ComparePerson
{
public:
	bool operator()(const Person& p1, const Person& p2) const
	{
		//����������������򣬵��������ȵģ�����set�Ķ����򲻻����
		return p1.m_Age > p2.m_Age;
	}
};

void test02()
{
	//�Զ����������Ͷ���ָ���������
	set<Person, ComparePerson> s;

	Person p1("����", 23);
	Person p2("����", 27);
	Person p3("�ŷ�", 25);
	Person p4("����", 21);
	Person p5("��", 27);


	s.insert(p1);
	s.insert(p2);
	s.insert(p3);
	s.insert(p4);
	s.insert(p5);


	for (set<Person, ComparePerson>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << "������ " << it->m_Name << " ���䣺 " << it->m_Age << endl;
	}
}
void test03()
{
	set<Person> s;

	Person p1("����", 23);
	Person p2("����", 27);
	Person p3("�ŷ�", 25);
	Person p4("����", 21);
	Person p5("��", 27);


	s.insert(p1);
	s.insert(p2);
	s.insert(p3);
	s.insert(p4);
	s.insert(p5);


	for (set<Person>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << "������ " << it->m_Name << " ���䣺 " << it->m_Age << endl;
	}
}
int main()
{

	//test01();
	//test02();
	test03();
	return 0;
}
