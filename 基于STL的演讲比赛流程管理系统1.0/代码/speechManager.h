#pragma once
#include<iostream>
using namespace std;
#include<vector>
#include<map>
#include<deque>
#include<numeric>
#include"speaker.h"
#include<algorithm>
#include<functional>
#include<fstream>
//设计演讲管理类
class SpeechManager
{
public:

	//构造
	SpeechManager();

	//析构
	~SpeechManager();

	//菜单
	void Menu();

	//退出系统
	void ExitSystem();

	//初始化容器和属性
	void InitSpeech();

	//初始化创建12名选手
	void CreateSpeaker();

	//开始比赛 - 比赛流程控制
	void StartSpeech();

	//抽签
	void SpeechDraw();

	//比赛
	void SpeechContest();

	//显示比赛结果
	void ShowScore();

	//保存记录
	void SaveRecord();

	//读取记录
	void LoadRecord();

	//显示往届得分
	void ShowRecord();

	//清空记录
	void ClearRecord();

//成员属性：

	//比赛选手 容器  12人
	vector<int>v1;

	//第一轮晋级容器  6人
	vector<int>v2;

	//胜利前三名容器  3人
	vector<int>vVictory;

	//存放编号 以及对应的 具体选手 容器
	map<int, Speaker> m_Speaker;

	//记录比赛轮数
	int m_Index;

	//文件为空的标志
	bool fileIsEmpty;

	//往届记录
	map<int, vector<string>> m_Record;
};