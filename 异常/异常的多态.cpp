#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;


//异常的多态
class Father {
public:
	virtual void printM() {}
};
class SonNULL :public Father {
public:
	virtual void printM() {
		cout << "空指针异常" << endl;
	}

};
//多态条件
//1.有继承
class SonOut :public Father {
public:
	virtual void printM() {	//重写父类虚函数
		cout << "越位溢出异常" << endl;
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
	catch(Father& f){	//3.父类引用指向子类对象
		f.printM();
	}
}
int main(void)
{
	test();
	return 0;
}