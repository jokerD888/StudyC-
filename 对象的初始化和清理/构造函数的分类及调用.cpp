#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
//1.���캯���ķ��༰����
//�ɷ�Ϊ	 ���ղ�������		 �޲ι��죨Ĭ�Ϲ��죩  ��		�вι���
//		 �������ͷ���		 ��ͨ����	 ��		��������
class Person
{
public:
	//���캯��
	Person()
	{
		cout << "Person���޲ι��캯������" << endl;
	}

	Person(int a)
	{
		age = a;
		cout<< "Person���вι��캯������" << endl;
	}

	//������������
	Person(const Person& p)
	{
		//��������˵�����������Ϣ���������ҡ�����
		age = p.age;
		cout << "Person���п����ι��캯������" << endl;
	}

	~Person()
	{
		cout << "Person������ ��������" << endl;
	}

public:
	int age;

};

//����
void test01()
{
	//1.���ŷ���
	//Person p1;//Ĭ�Ϲ��캯������
	//Person p2(10);//�вκ�������
	//Person p3(p2);//�������캯������
	//cout << "p2 age = " << p2.age << endl;
	//cout << "p3 age = " << p3.age << endl;

	//ע�⣺����Ĭ�Ϲ��캯��ʱ����Ҫ�ӣ���
	//��ΪPerson p1();����������Ϊ����һ���������������Բ��ᴴ������

	//2.��ʾ����
	Person p1;
	Person p2 = Person(10);
	Person p3 = Person(p2);

	Person(10);//��������	�ص㣺��ǰִ�н�����ϵͳ���������յ���������
	//Person(p3);
	//ע�⣺��Ҫ���������캯��	��ʼ����������(�����ض��壩	����������ΪPerson(p3)=	Person p3;

	//3.��ʽת����
	Person p4 = 10;
	Person p5 = p4;

	

}
int main(void)
{
	test01();
	return 0;
}
