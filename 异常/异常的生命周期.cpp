#define _CRT_SECURE_NO_WARNINGS 1

//异常对象的生命周期
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
//产生三个对象
void func1() {
	Maker m;	//第一个对象，在异常接受前被释放
	throw m;	//第二个对象，是第一个对象拷贝过来的

}

void test01() {
	try {
		func1();
	}
	catch(Maker m1){	//第三个对象，是第二个对象拷贝过来的
		cout << "接受一个Maker类型的异常" << endl;
		//第二个和第三个对象在catch结束时释放
	}
}
//输出
//Maker的构造
//Maker的拷贝构造
//Maker的拷贝构造
//~Maker的析构
//接受一个Maker类型的异常
//~Maker的析构
//~Maker的析构


//产生两个对象
void func2() {
	//第一个对象
	throw Maker();
	//匿名对象，虽然通常说匿名对象的结束在当前行，但通过输出语句可看到，此匿名对象的释放并不在当前行，
	//此时的匿名对象被throw返回，暗地里实际已有名字了，有名则存
}
void test02() {
	try {
		func2();
	}
	//第二个对象
	catch (Maker m1) {	
		cout << "接受一个Maker类型的异常" << endl;
		//第1个和第2个对象在catch结束时释放了
	}
}
//输出
//Maker的构造
//Maker的拷贝构造
//接受一个Maker类型的异常
//~Maker的析构
//~Maker的析构


//以上操作比较耗费内存，常用这一个，只生成一个对象
void func3() {
	throw Maker();//匿名对象
}
void test03() {
	try {
		func3();
	}
	catch (Maker& m1) {	
		//引用接收，不能用指针接受，会宕掉，因为编译器不允许对栈中的匿名对象取地址操作
		//但编译器允许对堆区中的匿名对象取地址操作,见test04()
		cout << "接受一个Maker类型的异常" << endl;
		//对象释放
	}
}
void func4() {
	throw new Maker();//匿名对象
}
void test04() {
	try {
		func4();
	}
	catch (Maker* m1) {
		cout << "接受一个Maker类型的异常" << endl;
		//对象释放
		delete m1;
	}
}


//总上所述，最适合用匿名对象和引用来抛出接受
int main(void)
{
	test04();
	return 0;
}
