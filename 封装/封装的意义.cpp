#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;


//���һ��Բ�࣬��Բ���ܳ�
const double PI = 3.14;
//class�������һ���࣬���������ŵľ����������
class Circle
{
	//����Ȩ��
	//����Ȩ��	��Ա ���ڿ��Է��ʣ�������Է���
public:
	//����Ȩ��	��Ա ���ڿ��Է��ʣ����ⲻ���Է���	���ӿ��Է��ʸ����еı�������
//protected:
	//˽��Ȩ��	��Ա ���ڿ��Է��ʣ����ⲻ���Է���	���Ӳ����Է��ʸ����е�˽������
//private:

	//����		���е����Ժ���Ϊ ͳ��Ϊ ��Ա
	//			����- ��Ա���ԣ���Ա����		��Ϊ-��Ա��������Ա����
	//�뾶
	int m_r;

	//��Ϊ
	//��ȡԲ���ܳ�
	double calculateZC()
	{
		return 2 * PI * m_r;
	}

	//���뾶��ֵ
	void setR(int r)
	{
		m_r = r;
	}
};

class Person
{
	//����Ȩ��	
public:
	string m_Name;	//����
	//����Ȩ��	
protected:
	string m_Car;	//����
	//˽��Ȩ��	
private:
	int m_Password;		//���п�����

public:
	void func()
	{
		m_Name = "����";
		m_Car = "������";		//���ڶ����Է���
		m_Password = 123456;
	}
};
int main(void)
{
	//ͨ��Բ�� ���������Բ������
	Circle c1;
	//��Բ��������Խ��и�ֵ
	//c1.m_r = 10;
	//Ҳ����ͨ����Ϊ�����Ը���
	//c1.setR(10);
	//cout << "Բ���ܳ�Ϊ��" << c1.calculateZC() << endl;


	Person p1;
	p1.m_Name = "����";	//����ֻ�ܷ���public
	//p1.m_Car = "��˹��˹";		//���ɷ���
	//p1.m_Password = 11111;	//���ɷ���
	p1.func();
	return 0;
}
