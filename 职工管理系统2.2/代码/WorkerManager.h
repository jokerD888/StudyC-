#pragma once
#include<iostream>
using namespace std;
#include"worker.h"
#include<fstream>
#define FILENAME "empFile.txt"
//创建一个管理类，有能够实现具有增删查改，显示，排序，清空等功能的成员函数
class WorkerManager
{
public:

	//构造函数
	WorkerManager();

	//析构函数
	~WorkerManager();
	//菜单
	void Menu();

	//退出
	void Exit();

	//扩容
	void Expand(int n);

	//单个增加员工
	void AddEmp();

	//批量增加员工
	void BatchAddEmp();

	//显示公司员工信息
	void ShowEmp();

	//保存数据到本地
	void Save();

	//从文档中获取员工数目
	int GetEmpNum();

	//初始化员工数组
	void InitEmp();

	//删除员工
	void DelEmp();

	//按照职工编号判断职工是否存在,若存在返回职工在数组中位置，不存在返回-1
	int IsExist(int id);

	//查找员工信息
	void FindEmp();

	//修改员工信息
	void ModEmp();

	//按员工序号排序可升可降
	void SortEmp();

	//清空文件数据
	void CleanFile();
public:
	//员工数组的指针
	Worker** m_EmpArray;

	//容量
	int m_size;

	//当前员工人数
	int m_num;

	//标志文件是否为空
	bool m_FileIsEmpty;

};
