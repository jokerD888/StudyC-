#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//��̬��Ա
// 
//��̬��Ա����
//���ж�����ͬһ������
//�ڱ���׶η����ڴ�
//���������������ʼ��
class Person
{

public:
	static int m_A; //��̬��Ա����


private:
	static int m_B; //��̬��Ա����Ҳ���з���Ȩ�޵�
};
//�����ʼ����
int Person::m_A = 10;
int Person::m_B = 10;

void test01()
{
	//��̬��Ա�������ַ��ʷ�ʽ

	//1��ͨ������
	Person p1;
	p1.m_A = 100;
	cout << "p1.m_A = " << p1.m_A << endl;

	Person p2;
	p2.m_A = 200;
	cout << "p1.m_A = " << p1.m_A << endl; //����ͬһ������
	cout << "p2.m_A = " << p2.m_A << endl;

	//2��ͨ������
	cout << "m_A = " << Person::m_A << endl;


	//cout << "m_B = " << Person::m_B << endl; //˽��Ȩ�޷��ʲ���
}


// ��̬��Ա����
//���ж�����ͬһ������
//��̬��Ա����ֻ�ܷ��ʾ�̬��Ա����
class Person1
{

public:

	//��̬��Ա�����ص㣺
	//1 ������һ������
	//2 ��̬��Ա����ֻ�ܷ��ʾ�̬��Ա����

	static void func()
	{
		cout << "func����" << endl;
		m_A = 100;  //��̬��Ա�����ܷ��ʾ�̬��Ա����
		//m_B = 100; //���󣬲����Է��ʷǾ�̬��Ա����
	}
	static int m_A; //��̬��Ա����
	int m_B; // 

private:

	//��̬��Ա����Ҳ���з���Ȩ�޵�
	static void func2()
	{
		cout << "func2����" << endl;
	}
};
int Person1::m_A = 10;


void test02()
{
	//��̬��Ա�������ַ��ʷ�ʽ

	//1��ͨ������
	Person1 p1;
	p1.func();

	//2��ͨ������
	Person1::func();


	//Person::func2(); //˽��Ȩ�޷��ʲ���
}
int main() {

	test02();

	return 0;
}
