#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;


class Maker {
public:
	Maker() {
		cout << "Maker的构造" << endl;
	}
	Maker(const Maker& m) {
		cout << "Maker的拷贝构造" << endl;
	}
	~Maker() {
		cout << "~Maker的析构" << endl;
	}
};
void func(){
	//在抛出异常的函数中，如果抛出异常后，但函数没有结束，这时，栈上申请的对象都会被释放，这就叫栈解旋，为了节省空间
	Maker m;
	throw m;//这个m是Maker拷贝的一份；
	cout << "func函数结束" << endl;	

}
void test01() {
	try {
		func();
		cout << "func()代码后" << endl;
	}

	catch (Maker) {
		cout << "接受一个Maker类型的异常" << endl;
	}
}
//输出结果
//Maker的构造
//Maker的拷贝构造
//~Maker的析构
//接受一个Maker类型的异常
//~Maker的析构
int main(void)
{
	test01();
	return 0;
}