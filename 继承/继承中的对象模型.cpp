#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//�Ӹ���̳й����ĳ�Ա����Щ������������У�
//���������зǾ�̬��Ա���Զ��ᱻ����̳���ȥ
class Base
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C; //˽�г�Աֻ�Ǳ������������ˣ����ǻ��ǻ�̳���ȥ
};

//�����̳�
class Son :public Base
{
public:
	int m_D;
};

void test01()
{
	cout << "sizeof Son = " << sizeof(Son) << endl;
}

int main() {

	test01();
	return 0;
}

