#pragma once
#include"worker.h"

class Employee :public Worker
{

public:

	//构造
	Employee(int id,string name,int did);
	//显示个人信息
	virtual void showInfo();
	//获取职位名称
	virtual string getDeptName();

};
