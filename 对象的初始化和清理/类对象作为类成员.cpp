#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;


//�������Ϊ���Ա���磺
//class A {}
//class B
//{
//    A a��
//}

class Phone
{
public:
	Phone(string name)
	{
		m_PhoneName = name;
		cout << "Phone����" << endl;
	}

	~Phone()
	{
		cout << "Phone����" << endl;
	}

	string m_PhoneName;

};


class Person
{
public:

	//��ʼ���б���Ը��߱�����������һ�����캯��
	Person(string name, string pName) :m_Name(name), m_Phone(pName)
	{
		cout << "Person����" << endl;
	}

	~Person()
	{
		cout << "Person����" << endl;
	}

	void playGame()
	{
		cout << m_Name << " ʹ��" << m_Phone.m_PhoneName << " ���ֻ�! " << endl;
	}

	string m_Name;
	Phone m_Phone;

};
void test01()
{
	//�����г�Ա�����������ʱ�����ǳƸó�ԱΪ �����Ա
	//�����˳���� ���ȵ��ö����Ա�Ĺ��죬�ٵ��ñ��๹��
	//����˳���빹���෴���ȵ��ñ��๹�죬�ٵ��ö����Ա�Ĺ���
	Person p("����", "ƻ��X");
	p.playGame();

}


int main() {

	test01();
	return 0;
}
