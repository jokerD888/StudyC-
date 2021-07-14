#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;


//在C++中，类内的成员变量和成员函数分开存储
//只有非静态成员变量才属于类的对象上


class Person 
{
public:
	Person() 
	{
		mA = 0;
	}
	//非静态成员变量占对象空间
	int mA;
	//静态成员变量不占对象空间,不属于类对象上
	static int mB;
	//函数也不占对象空间，所有函数共享一个函数实例
	void func() 
	{ 
		cout << "mA:" << this->mA << endl;
	}
	//静态成员函数也不占对象空间
	static void sfunc() 
	{
	}
};
int Person::mB = 10;
class Person1
{

};
int main() {

	Person1 p;
	Person p2;
	//空对象占用内存空间为1字节
	//c++编译器会给每个空对象也分配一个字节空间，是为了区分空对象占内存的位置
	cout << "sizeof of p " << sizeof(p) << endl;	
	cout << sizeof(Person1) << endl;

	cout << "sizeof of p " << sizeof(p2) << endl;
	cout << sizeof(Person) << endl;



	return 0;
}
