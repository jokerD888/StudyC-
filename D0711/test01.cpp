#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;


//����ռλ����
//void func(int a, int,int =20) 
//{
//	cout << "this is func" << endl;
//}

//��������
//void func()
//{
//	cout << "func �ĵ��ã�" << endl;
//}
//void func(int a)
//{
//	cout << "func (int a) �ĵ��ã�" << endl;
//}
//void func(double a)
//{
//	cout << "func (double a)�ĵ��ã�" << endl;
//}
//void func(int a, double b)
//{
//	cout << "func (int a ,double b) �ĵ��ã�" << endl;
//}
//void func(double a, int b)
//{
//	cout << "func (double a ,int b)�ĵ��ã�" << endl;
//}

//������Ϊ��������
//void func(int& a)
//{
//	cout << "func (int &a) ���� " << endl;
//}
//
//void func(const int& a)
//{
//	cout << "func (const int &a) ���� " << endl;
//}

//����������������Ĭ�ϲ���
void func2(int a, int b = 10)
{
	cout << "func2(int a, int b = 10) ����" << endl;
}

void func2(int a)
{
	cout << "func2(int a) ����" << endl;
}
int main() {
	//����ռλ���� ��ռλ����Ҳ������Ĭ�ϲ���
	//����������ռλ,������ʱҪ������
	//func(10, 10); //ռλ���������
	

	//��������
	//���ã�������������ͬ����߸�����
	//����������������:
	//1. ͬһ����������
	//2.����������ͬ
	//3. �����������Ͳ�ͬ ���� ������ͬ ���� ˳��ͬ
	// ע��:�����ķ���ֵ��������Ϊ�������ص�����
	//func();
	//func(10);
	//func(3.14);
	//func(10, 3.14);
	//func(3.14, 10);


	//������Ϊ��������
	//void func(int &a)		void func(const int &a) �����ǿ����������ص�
	//int a = 10;
	//func(a); //������const	���߻���void func(int a)�������壬�����
	//func(10);//������const
	 
	
	//����������������Ĭ�ϲ���
	//func2(10);////����Ĭ�ϲ����������壬���ֶ����ԣ���Ҫ����

	return 0;
}
