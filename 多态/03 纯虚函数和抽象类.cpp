#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//�ڶ�̬�У�ͨ���������麯����ʵ���Ǻ�������ģ���Ҫ���ǵ���������д������,��˿��Խ��麯����Ϊ���麯��
//���麯���﷨��virtual ����ֵ���� ������ �������б� = 0; 

//���������˴��麯���������Ҳ��Ϊ ������
//���������ص㣺
//�޷�ʵ��������
//���������д�������еĴ��麯��������Ҳ���ڳ�����

class Base
{
public:
	//���麯��
	//����ֻҪ��һ�����麯���ͳ�Ϊ������
	//�������޷�ʵ��������
	//���������д�����еĴ��麯��������Ҳ���ڳ�����
	virtual void func() = 0;
};

class Son :public Base
{
public:
	virtual void func()
	{
		cout << "func����" << endl;
	};
};

void test01()
{
	Base* base = NULL;
	//base = new Base; // ���󣬳������޷�ʵ��������
	base = new Son;
	base->func();
	delete base;//�ǵ�����
}

int main() {

	test01();
	return 0;
}



