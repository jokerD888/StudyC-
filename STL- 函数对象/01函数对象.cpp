#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;
//�����������
//���
//���غ������ò��������࣬����󳣳�Ϊ��������
//��������ʹ�����ص�()ʱ����Ϊ���ƺ������ã�Ҳ�зº���
//
//���ʣ�
//��������(�º���)��һ���� ������һ������

//��������ʹ��
//�ص㣺
//����������ʹ��ʱ����������ͨ������������, �����в����������з���ֵ
//�������󳬳���ͨ�����ĸ����������������Լ���״̬
//�������������Ϊ��������


//1������������ʹ��ʱ����������ͨ������������, �����в����������з���ֵ
class MyAdd
{
public:

	int operator()(int v1, int v2)
	{
		return v1 + v2;
	}

};

void test01()
{
	MyAdd myAdd;
	cout << myAdd(10, 10) << endl;
}

//2����������������Լ���״̬
class MyPrint
{
public:
	MyPrint()
	{
		count = 0;
	}
	void operator()(string test)
	{
		cout << test << endl;
		count++; //ͳ��ʹ�ô���,������ͨ������Ҫ������ô���������Ҫ�ٶ���ȫ�ֱ�������
	}

	int count; //�ڲ��Լ���״̬
};
void test02()
{
	MyPrint myPrint;
	myPrint("hello world");
	myPrint("hello world");
	myPrint("hello world");
	cout << "myPrint���ô���Ϊ�� " << myPrint.count << endl;
}

//3���������������Ϊ��������
void doPrint(MyPrint& mp, string test)
{
	mp(test);
}

void test03()
{
	MyPrint myPrint;
	doPrint(myPrint, "Hello C++");
}

int main()
{

	test01();
	test02();
	test03();

	return 0;
}
