#pragma once
#include<iostream>
#include"speaker.h"
using namespace std;
#include<vector>
#include<map>
#include<sstream>
#include<deque>
#include<functional>
#include<Windows.h>
#include<algorithm>
#include<numeric>
#include<fstream>
#include <iomanip>
#define REFEREE 10 //裁判人数
#define FILENAME "speech.csv"

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

	//初始化容器和轮数
	void InitSpeech();

	//创建初始选手
	void CreateSpeaker();

	//开始赛流程
	void StartSpeech();

	//抽签
	void SpeechDraw();

	//比赛
	void SpeechContest();

	//显示比赛结果
	void ShowScore();

	//展示获奖得主
	void ShowChampion();

	//读取记录分
	void LoadRecord();

	//保存分数
	void SaveRecord();

	//查看往届记录
	void ShowRecord();

	//清空记录
	void ClearRecord();

public:

	vector<vector<int>> v;//存储各轮比赛选手编号

	map<int, Speaker> m_Speaker;//存放编号 以及对应的 具体选手 容器

	int m_Index;//比赛轮数
	
	bool fileIsEmpty;//文件为空标志

	map<int, vector<string>> m_Record;

};
