#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;


//�쳣�Ķ�̬
class Father {
public:
	virtual void printM() {}
};
class SonNULL :public Father {
public:
	virtual void printM() {
		cout << "��ָ���쳣" << endl;
	}

};
//��̬����
//1.�м̳�
class SonOut :public Father {
public:
	virtual void printM() {	//��д�����麯��
		cout << "Խλ����쳣" << endl;
	} 
};

void func(int a,int b) {
	//throw SonNULL();
	if (a == 0) {
		throw SonNULL();
	}
	if (b == 0) {
		throw SonOut();
	}
}
void test() {
	int a = 0;
	int b = 20;
	try {
		func(a,b);
	}
	catch(Father& f){	//3.��������ָ���������
		f.printM();
	}
}
int main(void)
{
	test();
	return 0;
}