#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;


int func(int a, int b) {
	if (b == 0) {
		throw 'c';
	}
	return a / b;
}
void test01() {
	int a = 10;
	int b = 0;
	try {
		func(a, b);
		cout << "func��" << endl;
	}
	catch (int) {	
		cout << "int�����쳣����ĸΪ0" << endl;
	}
	catch (double) {
		cout << "double�����쳣����ĸΪ0" << endl;
	}
	//catch (char) {//��û�д���char���͵��쳣���ܣ�������
	//	cout << "char �����쳣����ĸΪ0" << endl;
	//}
	catch (...) {//�����������͵��쳣
		cout << "�������͵��쳣" << endl;
	}

}

int main(void)
{
	test01();
	return 0;
}