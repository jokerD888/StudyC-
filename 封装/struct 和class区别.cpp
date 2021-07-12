#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//在C++中 struct和class唯一的区别就在于默认的访问权限不同
//区别：
// struct 默认权限为公共
//class   默认权限为私有
class C1
{
	int m_A;	//默认权限为私有
};
struct	C2
{
	int m_A;	 //默认权限为公共
};
	
int main(void)
{
	C1 c1;
	//c1.m_A = 100;	//报错，不可访问

	C2 c2;
	c2.m_A = 100;
	return 0;
}
