#pragma once
#include<iostream>
using namespace std;

//身份基类
class Identity {
public:

	//操作界面
	virtual void operMenu() = 0;
	//用户名
	string m_Name;
	//秘密
	string m_Pwd;
};