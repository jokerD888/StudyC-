#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//��C++�� struct��classΨһ�����������Ĭ�ϵķ���Ȩ�޲�ͬ
//����
// struct Ĭ��Ȩ��Ϊ����
//class   Ĭ��Ȩ��Ϊ˽��
class C1
{
	int m_A;	//Ĭ��Ȩ��Ϊ˽��
};
struct	C2
{
	int m_A;	 //Ĭ��Ȩ��Ϊ����
};
	
int main(void)
{
	C1 c1;
	//c1.m_A = 100;	//�������ɷ���

	C2 c2;
	c2.m_A = 100;
	return 0;
}
