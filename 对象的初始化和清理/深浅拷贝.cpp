#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;


//ǳ�������򵥵ĸ�ֵ��������
//������ڶ�����������ռ䣬���п�������

//��ʼ���б�  
class Person 
{
public:
	
	Person() 
	{
		cout << "�޲ι��캯��!" << endl;
	}
	//��ͳ��ʽ��ʼ��
	/*Person(int age, int height) 
	{
		cout << "�вι��캯��!" << endl;
		m_age = age;
		m_height = new int(height);
	}*/

	//��ʼ���б�ʽ��ʼ��
	Person(int age, int height) :m_age(age), m_height(new int(height)) {};

	Person(const Person& p) //����Լ���д�������캯����ϵͳ�Լ���ǳ�������캯���ᵼ��ͬһ�ڴ�ռ����ͷţ�����
	{
		cout << "�������캯��!" << endl;
		//�������������ڶ����������ڴ棬�ᵼ��ǳ�����������ظ��ͷŶ�������
		m_age = p.m_age;
		m_height = new int(*p.m_height);	//������Ĭ��ʵ�ֵĴ��룺m_height=p.m_height;

	}

	~Person() 
	{
		//�������룬���ѿ��ٵ��������ͷŲ���	
		if (m_height != NULL)
		{
			delete m_height;
			m_height = NULL;
		}
		cout << "��������!" << endl;

	}
public:
	int m_age;
	int* m_height;
};

void test01()
{
	Person p1(18, 180);
	Person p2(p1);

	cout << "p1�����䣺 " << p1.m_age << " ��ߣ� " << *p1.m_height << endl;
	cout << "p2�����䣺 " << p2.m_age << " ��ߣ� " << *p2.m_height << endl;
}
//�ܽ᣺����������ڶ������ٵģ�һ��Ҫ�Լ��ṩ�������캯������ֹǳ��������������
int main() {

	test01();

	return 0;
}