#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;


//Ȼ�죬ģ��Ҳ�����ľ�����
//ģ���ͨ���Բ��������ܵ�
//���磺
template<class T>
void f(T a, T b)
{
	a = b;
}
//�������������ṩ�ĸ�ֵ��������������a��b��һ�����飬���޷�ʵ����
//�ֱ���T���������ʹ��������Person�������Զ����������ͣ�Ҳ�޷���������
//���C++Ϊ�˽���������⣬�ṩģ������أ�����Ϊ��Щ�ض��������ṩ���廯��ģ��

//��ô��ʾ���廯�ͷ�ģ�庯����ʲô�����أ�
//��Ȼʹ������Ч��һ����������Щ����ģ��Ĳ����п���û����ģ�������ֻ���ں����������ˡ����ֵ���ʱû�취�������ݣ���ֻ����ʾʵ��������

class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	string m_Name;
	int m_Age;
};

//��ͨ����ģ��
template<class T>
bool myCompare(T& a, T& b)
{
	if (a == b)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//��ԭģ���ǰ�����template<>��ʵ����������������,�൱��template<>+��ͨ��������=��ʽ���廯
//���þ��廯Person�İ汾ʵ�ִ��룬���廯���ȵ��ã����ͬ��������������;��廯��ģ�壬Ҳ�����ȵ���ģ�壩
//�ڵ������ȼ��ϣ���ģ�庯�������ھ��廯�ͳ���ģ�壬���廯�����ڳ���ģ��
template<> bool myCompare(Person& p1, Person& p2)
{
	cout << "����" << endl;
	if (p1.m_Name == p2.m_Name && p1.m_Age == p2.m_Age)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool myCompare(Person& p1, Person& p2)
{
	cout << "��ģ�庯��" << endl;
	if (p1.m_Name == p2.m_Name && p1.m_Age == p2.m_Age)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void test01()
{
	int a = 10;
	int b = 20;
	//�����������Ϳ���ֱ��ʹ��ͨ�õĺ���ģ��
	bool ret = myCompare(a, b);
	if (ret)
	{
		cout << "a == b " << endl;
	}
	else
	{
		cout << "a != b " << endl;
	}
}

void test02()
{
	Person p1("Tom", 10);
	Person p2("Tom", 10);
	//�Զ����������ͣ����������ͨ�ĺ���ģ��
	//���Դ������廯��Person�������͵�ģ�壬�������⴦���������
	bool ret = myCompare(p1, p2);
	if (ret)
	{
		cout << "p1 == p2 " << endl;
	}
	else
	{
		cout << "p1 != p2 " << endl;
	}
}

int main()
{

	test01();
	test02();
	return 0;
}

