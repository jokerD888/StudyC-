#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;


//����֪����C++�г�Ա�����ͳ�Ա�����Ƿֿ��洢��
//ÿһ���Ǿ�̬��Ա����ֻ�ᵮ��һ�ݺ���ʵ����Ҳ����˵���ͬ���͵Ķ���Ṳ��һ�����
//��ô�����ǣ���һ���������������Ǹ���������Լ����أ�
//c++ͨ���ṩ����Ķ���ָ�룬thisָ�룬����������⡣ -->thisָ��ָ�򱻵��õĳ�Ա���������Ķ��� 
//thisָ��������ÿһ���Ǿ�̬��Ա�����ڵ�һ��ָ��
//thisָ�벻��Ҫ���壬ֱ��ʹ�ü���
//thisָ�����;��
//1.���βκͳ�Ա����ͬ��ʱ������thisָ��������
//2.����ķǾ�̬��Ա�����з��ض�������ʹ��return * this

class Person
{
public:

	Person(int age)
	{
		//1�����βκͳ�Ա����ͬ��ʱ������thisָ��������
		this->age = age;
	}

	//Person* PersonAddPerson(Person p)
	//{
	//	this->age += p.age;
	//	//���ض�����
	//	return this;//������������Person& 
	//}
	Person& PersonAddPerson(Person p)
	{
		this->age += p.age;
		//���ض�����
		return *this;//������������Person& 
	}

	int age;
};

void test01()
{
	Person p1(10);
	cout << "p1.age = " << p1.age << endl;

	Person p2(10);
	//�������ķ���ֵ��ָ������ʱ
	//p2.PersonAddPerson(p1)->PersonAddPerson(p1)->PersonAddPerson(p1);
	//�������ķ���ֵ������ʱ
	p2.PersonAddPerson(p1).PersonAddPerson(p1).PersonAddPerson(p1);
	cout << "p2.age = " << p2.age << endl;
}

int main() {

	test01();

	return 0;
}
