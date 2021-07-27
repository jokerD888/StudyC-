#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;
#include<string>

//功能描述：
//从字符串中获取想要的子串

//函数原型：
//string substr(int pos = 0, int n = npos) const;    //返回由pos开始的n个字符组成的字符串


void test01()
{

	string str = "abcdefg";
	string subStr = str.substr(1, 3);
	cout << "subStr = " << subStr << endl;

	//这个虽然简单，却比较通用，比如：获取邮箱的用户名自动截取@之前的字串
	string email = "hello@sina.com";
	int pos = email.find("@");
	string username = email.substr(0, pos);
	cout << "username: " << username << endl;

}

int main()
{

	test01();
	return 0;
}
