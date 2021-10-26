#define _CRT_SECURE_NO_WARNINGS 1

//异常处理就是处理程序中的错误，所谓错误就是指在程序运行过程中发生的一些异常事件，
//如：除0溢出，数组下标越界，所要读取的文件不存在，空指针，内存不足等

#include<iostream>
using namespace std;

//C中处理异常的方法的缺陷
//1.返回值意思不明确
//2.返回值只能返回一条信息
//3.返回值可以忽略

int func(int a,int b) {
	if (b == 0) {
		//2.抛出异常
		throw 10;//抛出一个int类型的异常
		cout << "trow后" << endl;
	}
	return a / b;
}
void test01() {
	int a = 10;
	int b = 0;
	//1.把有可能出现异常的代码块放到try中
	try {
		func(a, b);
	}
	catch(int){	//3.接受一个int 类型的异常
		cout << "分母为0" << endl;
	}
}

//thor后的代码不会执行，相当于return，出现异常的语句之后的代码也不会执行，直接跑到catch语句
void test02() {
	int a = 10;
	int b = 0;
	//1.把有可能出现异常的代码块放到try中
	try {
		func(a, b);
		cout << "func后" << endl;
	}
	catch (int) {	//3.接受一个int 类型的异常
		cout << "分母为0" << endl;
	}
}


void test03() {
	int a = 10;
	int b = 0;
	//1.把有可能出现异常的代码块放到try中
	try {
		func(a, b);
	}
	catch (int& a) {	//这里用引用接受，按理说程序该宕的，但并不会，程序做了优化
		cout << "分母为0" << endl;
		a = 20;
	}
}
int main(void)
{

	test03();
	return 0;
}
