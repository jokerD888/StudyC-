#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//递增运算符重载
//前置递增返回引用，后置递增返回值

class MyInteger
{

	friend ostream& operator<<(ostream& out, MyInteger myint);

public:
	MyInteger() 
	{
		m_Num = 0;
	}
	//前置++
	MyInteger& operator++() 
	{
		//先++
		m_Num++;
		//再返回
		return *this;
	}

	//后置++
	MyInteger operator++(int) 
	{
		//先返回
		MyInteger temp = *this; //记录当前本身的值，然后让本身的值加1，但是返回的是以前的值，达到先返回后++；
		m_Num++;
		return temp;
	}

private:
	int m_Num;
};


ostream& operator<<(ostream& out, MyInteger myint) 
{
	out << myint.m_Num;
	return out;
}


//前置++ 先++ 再返回
void test01() 
{
	MyInteger myInt;
	cout << ++(++myInt) << endl;	//因前置++返回的是引用，可以连续前置++
	cout << myInt << endl;
}

//后置++ 先返回 再++
void test02() {

	MyInteger myInt;
	cout << (myInt++)++ << endl;	//而后置++返回的是值，只是原数据的一份临时拷贝，连续后置++并不会累加到自身
	cout << myInt << endl;
}

int main() {

	//test01();
	test02();
	return 0;
}
