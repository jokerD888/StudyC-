#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//C++�п�ָ��Ҳ�ǿ��Ե��ó�Ա�����ģ�����ҲҪע����û���õ�thisָ��
//����õ�thisָ�룬��Ҫ�����жϱ�֤����Ľ�׳��

//��ָ����ʳ�Ա����
class Person 
{
public:

	void ShowClassName() 
	{
		cout << "����Person��!" << endl;
	}

	void ShowPerson() 
	{
		if (this == NULL) 
		{
			return;
		}
		cout << mAge << endl;//�൱��cout <<this-> mAge << endl;
	}

public:
	int mAge;
};

void test01()
{
	Person* p = NULL;
	p->ShowClassName(); //��ָ�룬���Ե��ó�Ա����
	p->ShowPerson();  //���������Ա�������õ���thisָ�룬�Ͳ�������
}

int main() {

	test01();
	return 0;
}
