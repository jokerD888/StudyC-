#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
using namespace std;
#include<string>
//
//string中单个字符存取方式有两种(可查可修）
//char& operator[](int n);     //通过[]方式取字符，像数组一样使用
//char& at(int n);                    //通过at方法获取字符

//str.size()函数返回字符个数
void test01()
{
	string str = "hello world";
	for (int i = 0; i < str.size(); i++)
	{
		cout << str[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < str.size(); i++)
	{
		cout << str.at(i) << " ";
	}
	cout << endl;


	//字符修改
	str[0] = 'x';
	str.at(1) = 'x';
	cout << str << endl;

}

int main() 
{

	test01();
	return 0;
}