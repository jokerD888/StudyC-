#define _CRT_SECURE_NO_WARNINGS 1

//�쳣������Ǵ�������еĴ�����ν�������ָ�ڳ������й����з�����һЩ�쳣�¼���
//�磺��0����������±�Խ�磬��Ҫ��ȡ���ļ������ڣ���ָ�룬�ڴ治���

#include<iostream>
using namespace std;

//C�д����쳣�ķ�����ȱ��
//1.����ֵ��˼����ȷ
//2.����ֵֻ�ܷ���һ����Ϣ
//3.����ֵ���Ժ���

int func(int a,int b) {
	if (b == 0) {
		//2.�׳��쳣
		throw 10;//�׳�һ��int���͵��쳣
		cout << "trow��" << endl;
	}
	return a / b;
}
void test01() {
	int a = 10;
	int b = 0;
	//1.���п��ܳ����쳣�Ĵ����ŵ�try��
	try {
		func(a, b);
	}
	catch(int){	//3.����һ��int ���͵��쳣
		cout << "��ĸΪ0" << endl;
	}
}

//thor��Ĵ��벻��ִ�У��൱��return�������쳣�����֮��Ĵ���Ҳ����ִ�У�ֱ���ܵ�catch���
void test02() {
	int a = 10;
	int b = 0;
	//1.���п��ܳ����쳣�Ĵ����ŵ�try��
	try {
		func(a, b);
		cout << "func��" << endl;
	}
	catch (int) {	//3.����һ��int ���͵��쳣
		cout << "��ĸΪ0" << endl;
	}
}


void test03() {
	int a = 10;
	int b = 0;
	//1.���п��ܳ����쳣�Ĵ����ŵ�try��
	try {
		func(a, b);
	}
	catch (int& a) {	//���������ý��ܣ�����˵�����崵ģ��������ᣬ���������Ż�
		cout << "��ĸΪ0" << endl;
		a = 20;
	}
}
int main(void)
{

	test03();
	return 0;
}
