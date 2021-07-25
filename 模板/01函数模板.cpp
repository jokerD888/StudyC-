#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//ģ����ǽ���ͨ�õ�ģ�ߣ������߸�����
//ģ���ص㣺1.��ֻ����Ϊһ����ܣ�������ֱ��ʹ�ã�2.ģ���ͨ�ò������ܵ�

//����ģ��
//���ã�����һ��ͨ�ú������亯������ֵ���ͺ��β����Ϳ��Բ������ƶ�����һ�����������������
//�﷨��template<typename T>   typename���滻Ϊclass   T���ǹ̶���������д����������
//����template ��ʾ��������ģ��  typename ��ʾ�����ķ�����һ���������ͣ�����class����
// T ��ʾͨ�õ��������ͣ����ƿ��滻��ͨ��Ϊ��д��ĸ




//�������ͺ���
void swapInt(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

//���������ͺ���
void swapDouble(double& a, double& b) {
	double temp = a;
	a = b;
	b = temp;
}

//����ģ���ṩͨ�õĽ�������
template<typename T>
void mySwap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

void test01()
{
	int a = 10;
	int b = 20;
	//swapInt(a, b);

//����ģ��ʵ�ֽ���
    //1���Զ������Ƶ�
	mySwap(a, b);

	//2����ʾָ������
	mySwap<int>(a, b);

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

}


//ע�⣺1.	�Զ������Ƶ��������Ƶ���һ�µ���������T,�ſ���ʹ��
//      2.  ģ�����Ҫȷ����T���������ͣ��ſ���ʹ��

//����ģ���ṩͨ�õĽ�������
template<class T>
void mySwap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}
// 1���Զ������Ƶ��������Ƶ���һ�µ���������T,�ſ���ʹ��
void test02()
{
	int a = 10;
	int b = 20;
	char c = 'c';

	mySwap(a, b); //���ﴫ��Ķ���int�� ��ȷ�������Ƶ���һ�µ�T
	//mySwap(a, c); // ���ﴫ��int��char�������ͣ��������޷�ʶ��T�������������ͣ������Ƶ�����һ�µ�T����
}


// 2��ģ�����Ҫȷ����T���������ͣ��ſ���ʹ��
template<class T>
void func()
{
	cout << "func ����" << endl;
}

void test02()
{
	//func(); //����ģ�岻�ܶ���ʹ�ã�����ȷ����T������
	func<int>(); //������ʾָ�����͵ķ�ʽ����Tһ�����ͣ��ſ���ʹ�ø�ģ��
}



int main(void)
{
	//test01();//����ģ���﷨
	test02();//ע������
	test02();
	return 0;

}