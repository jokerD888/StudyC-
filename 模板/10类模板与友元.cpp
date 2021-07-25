#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;
//Person��ģ������
template<class T1,class T2>
class Person;

//�����������������ͽ�ʵ����ǰ
template<class T1,class T2>
void PrintPerson2(Person<T1, T2>& p);

//��ģ��
template<class T1,class T2>
class Person
{
	//ȫ�ֺ��������Ԫ-����ʵ��
	friend void PrintPerson(Person<T1, T2>& p)
	{
		cout << "name: " << p.m_Name << "\tage��" << p.m_Age << endl;
	}

	//����ʵ��
	friend void PrintPerson2<>(Person<T1, T2>& p);//ע������ĺ�����ǰ�Ŀղ����б�<>����Ϊ���߱���������һ������ģ�������
public:
	Person(T1 name, T2 age)
	{
		this->m_Age = age;
		this->m_Name = name;
	}

private:
	T1 m_Name;
	T2 m_Age; 
};
//����ʵ��ȫ�ֺ���
template<class T1,class T2>
void PrintPerson2(Person<T1, T2>& p)
{
	cout << "name: " << p.m_Name << "\tage��" << p.m_Age << endl;
}
//����
void test01()
{
	Person<string, int> p("Tom", 18);
	PrintPerson(p);
}
//����
void test02()
{
	Person<string, int> p("Jerry", 19);
	PrintPerson2(p);
}
int main(void)
{

	test01();
	test02();
	return 0;
}
