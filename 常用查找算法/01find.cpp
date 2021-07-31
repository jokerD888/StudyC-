#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

//����������
//����ָ��Ԫ�أ��ҵ�����ָ��Ԫ�صĵ��������Ҳ������ؽ���������end()
//
//����ԭ�ͣ�
//find(iterator beg, iterator end, value);  
// ��ֵ����Ԫ�أ��ҵ�����ָ��λ�õ��������Ҳ������ؽ���������λ��
// beg ��ʼ������
// end ����������
// value ���ҵ�Ԫ��

#include <algorithm>
#include <vector>
#include <string>

//������������
void test01()
{

	vector<int> v;
	for (int i = 0; i < 10; i++) 
	{
		v.push_back(i + 1);
	}
	//�����������Ƿ��� 5 ���Ԫ��
	vector<int>::iterator it = find(v.begin(), v.end(), 5);
	if (it == v.end())
	{
		cout << "û���ҵ�!" << endl;
	}
	else
	{
		cout << "�ҵ�:" << *it << endl;
	}
}

//�Զ����������ͣ���Ҫ����==
class Person 
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	//����==
	bool operator==(const Person& p)
	{
		if (this->m_Name == p.m_Name && this->m_Age == p.m_Age)
		{
			return true;
		}
		return false;
	}

public:
	string m_Name;
	int m_Age;
};

void test02() 
{

	vector<Person> v;

	//��������
	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);

	vector<Person>::iterator it = find(v.begin(), v.end(), Person("bbb",20));
	if (it == v.end())
	{
		cout << "û���ҵ�!" << endl;
	}
	else
	{
		cout << "�ҵ�����:" << it->m_Name << " ����: " << it->m_Age << endl;
	}
}

int main(void)
{
	test01();
	test02();

	return 0;
}
