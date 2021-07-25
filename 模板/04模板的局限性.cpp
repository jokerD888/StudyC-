#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;


//然鹅，模板也有它的局限性
//模板的通用性并不是万能的
//例如：
template<class T>
void f(T a, T b)
{
	a = b;
}
//在上述代码中提供的赋值操作，如果传入的a和b是一个数组，就无法实现了
//又比如T的数据类型传入的是像Person这样的自定义数据类型，也无法正常运行
//因此C++为了解决这种问题，提供模板的重载，可以为这些特定的类型提供具体化的模板

//那么显示具体化和非模板函数有什么区别呢？
//虽然使用起来效果一样，但是有些函数模板的参数中可能没有用模板参数，只能在函数体内用了。这种调用时没办法调用推演，就只能显示实例化调用

class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	string m_Name;
	int m_Age;
};

//普通函数模板
template<class T>
bool myCompare(T& a, T& b)
{
	if (a == b)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//在原模板的前面加上template<>并实例化函数参数即可,相当于template<>+普通函数重载=显式具体化
//利用具体化Person的版本实现代码，具体化优先调用（如果同是有重载运算符和具体化的模板，也是优先调用模板）
//在调用优先级上，非模板函数优先于具体化和常规模板，具体化优先于常规模板
template<> bool myCompare(Person& p1, Person& p2)
{
	cout << "具体" << endl;
	if (p1.m_Name == p2.m_Name && p1.m_Age == p2.m_Age)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool myCompare(Person& p1, Person& p2)
{
	cout << "非模板函数" << endl;
	if (p1.m_Name == p2.m_Name && p1.m_Age == p2.m_Age)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void test01()
{
	int a = 10;
	int b = 20;
	//内置数据类型可以直接使用通用的函数模板
	bool ret = myCompare(a, b);
	if (ret)
	{
		cout << "a == b " << endl;
	}
	else
	{
		cout << "a != b " << endl;
	}
}

void test02()
{
	Person p1("Tom", 10);
	Person p2("Tom", 10);
	//自定义数据类型，不会调用普通的函数模板
	//可以创建具体化的Person数据类型的模板，用于特殊处理这个类型
	bool ret = myCompare(p1, p2);
	if (ret)
	{
		cout << "p1 == p2 " << endl;
	}
	else
	{
		cout << "p1 != p2 " << endl;
	}
}

int main()
{

	test01();
	test02();
	return 0;
}

