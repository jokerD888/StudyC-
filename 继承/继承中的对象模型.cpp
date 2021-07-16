#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//从父类继承过来的成员，哪些属于子类对象中？
//父类中所有非静态成员属性都会被子类继承下去
class Base
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C; //私有成员只是被编译器隐藏了，但是还是会继承下去
};

//公共继承
class Son :public Base
{
public:
	int m_D;
};

void test01()
{
	cout << "sizeof Son = " << sizeof(Son) << endl;
}

int main() {

	test01();
	return 0;
}

