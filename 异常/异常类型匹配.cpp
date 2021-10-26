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
		cout << "func后" << endl;
	}
	catch (int) {	
		cout << "int类型异常，分母为0" << endl;
	}
	catch (double) {
		cout << "double类型异常，分母为0" << endl;
	}
	//catch (char) {//若没有此条char类型的异常接受，将报错
	//	cout << "char 类型异常，分母为0" << endl;
	//}
	catch (...) {//接受所有类型的异常
		cout << "所有类型的异常" << endl;
	}

}

int main(void)
{
	test01();
	return 0;
}