#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;


//��C++�У����ڵĳ�Ա�����ͳ�Ա�����ֿ��洢
//ֻ�зǾ�̬��Ա������������Ķ�����


class Person 
{
public:
	Person() 
	{
		mA = 0;
	}
	//�Ǿ�̬��Ա����ռ����ռ�
	int mA;
	//��̬��Ա������ռ����ռ�,�������������
	static int mB;
	//����Ҳ��ռ����ռ䣬���к�������һ������ʵ��
	void func() 
	{ 
		cout << "mA:" << this->mA << endl;
	}
	//��̬��Ա����Ҳ��ռ����ռ�
	static void sfunc() 
	{
	}
};
int Person::mB = 10;
class Person1
{

};
int main() {

	Person1 p;
	Person p2;
	//�ն���ռ���ڴ�ռ�Ϊ1�ֽ�
	//c++���������ÿ���ն���Ҳ����һ���ֽڿռ䣬��Ϊ�����ֿն���ռ�ڴ��λ��
	cout << "sizeof of p " << sizeof(p) << endl;	
	cout << sizeof(Person1) << endl;

	cout << "sizeof of p " << sizeof(p2) << endl;
	cout << sizeof(Person) << endl;



	return 0;
}
