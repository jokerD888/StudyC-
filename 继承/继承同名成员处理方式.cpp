#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;


//���⣺�������븸�����ͬ���ĳ�Ա�����ͨ��������󣬷��ʵ����������ͬ���������أ�
//��������ͬ����Ա   ֱ�ӷ��ʼ���
// ���ʸ���ͬ����Ա   ��Ҫ��������
//���ʾ�̬��ԱҲһ�����������ʾ�̬��Ա�����ַ���(ͨ����������������

//�Ǿ�̬��Ա--------------------------------------------------------
//class Base {
//public:
//	Base()
//	{
//		m_A = 100;
//	}
//
//	void func()
//	{
//		cout << "Base - func()����" << endl;
//	}
//
//	void func(int a)
//	{
//		cout << "Base - func(int a)����" << endl;
//	}
//
//public:
//	int m_A;
//};
//
//
//class Son : public Base 
//{
//public:
//	Son()
//	{
//		m_A = 200;
//	}
//
//	//�������븸��ӵ��ͬ���ĳ�Ա��������������ظ������������ص�ͬ����Ա����
//	//�������ʸ����б����ص�ͬ����Ա��������Ҫ�Ӹ����������
//	void func()
//	{
//		cout << "Son - func()����" << endl;
//	}
//public:
//	int m_A;
//};
//void test01()
//{
//	Son s;
//
//	cout << "Son�µ�m_A = " << s.m_A << endl;
//	cout << "Base�µ�m_A = " << s.Base::m_A << endl;
//
//	s.func();
//	s.Base::func();
//	s.Base::func(10);
//
//}
// 
// 
//��̬��Ա----------------------------------------
class Base {
public:
	static void func()
	{
		cout << "Base - static void func()" << endl;
	}
	static void func(int a)
	{
		cout << "Base - static void func(int a)" << endl;
	}

	static int m_A;
};

int Base::m_A = 100;

class Son : public Base {
public:
	static void func()
	{
		cout << "Son - static void func()" << endl;
	}
	static int m_A;
};

int Son::m_A = 200;

//ͬ����Ա����
void test01()
{
	//ͨ���������
	cout << "ͨ��������ʣ� " << endl;
	Son s;
	cout << "Son  �� m_A = " << s.m_A << endl;
	cout << "Base �� m_A = " << s.Base::m_A << endl;

	//ͨ����������
	cout << "ͨ���������ʣ� " << endl;
	cout << "Son  �� m_A = " << Son::m_A << endl;
	cout << "Base �� m_A = " << Son::Base::m_A << endl;
}

//ͬ����Ա����
void test02()
{
	//ͨ���������
	cout << "ͨ��������ʣ� " << endl;
	Son s;
	s.func();
	s.Base::func();

	cout << "ͨ���������ʣ� " << endl;
	Son::func();
	Son::Base::func();
	//����ͬ������������ص�����������ͬ����Ա��������Ҫ�������������
	Son::Base::func(100);
}


int main() {

	test01();
	test02();
	return 0;
}
