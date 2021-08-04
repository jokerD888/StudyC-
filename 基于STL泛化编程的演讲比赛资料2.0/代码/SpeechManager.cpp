
#include"SpeechManager.h"

//构造
SpeechManager::SpeechManager()
{
	this->InitSpeech();
	this->CreateSpeaker();
	this->LoadRecord();//加载往届记录
}

//初始化容器和轮数
void SpeechManager::InitSpeech()
{
	v.clear();
	m_Speaker.clear();
	m_Record.clear();
	m_Index = 1;

	vector<int> v1;//存放初始比赛选手
	vector<int> v2;//存放第一轮晋级人员
	vector<int> v3;//存放前三名

	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);

}

//创建初始选手
void  SpeechManager::CreateSpeaker()
{
	string nameSeed = "ABCDEFGHIJKL";
	for (int i = 0; i < 12; i++)
	{
		
		v[0].push_back(10001 + i);//编号插入选手容器
		string name = "选手";
		name += nameSeed[i];//名字为选手A~L

		Speaker sp;
		sp.m_Name = name;
		sp.m_Score[0] = sp.m_Score[1] = 0;

		m_Speaker.insert(make_pair(10001 + i, sp));//将编号和所对应的选手信息存入容器
	}

}

//开始赛流程
void SpeechManager::StartSpeech()
{
	//抽签
	//比赛
	//显示晋级结果

	for (int i = 0; i < 2; i++)
	{
		this->SpeechDraw();
		this->SpeechContest();
		this->ShowScore();
		this->m_Index = 2;
	}
	this->SaveRecord();
	this->ShowChampion();

	//为连续比赛做初始化准备
	this->InitSpeech();
	this->CreateSpeaker();
	this->LoadRecord();//容器等初始化完毕后，为了能在本次程序中在记录能够看到本次比赛在读取以便往届得分


	system("pause");
	system("cls");
	
}

//抽签
void SpeechManager::SpeechDraw()
{
	cout << "第<< " << this->m_Index << " >>轮比赛选手正在抽签......" << endl;
	Sleep(500);
	cout << "-----------------------------------------------------------------------------------" << endl;
	cout << "抽签后演讲顺序如下：" << endl;
	int index = 0;
	if (this->m_Index == 2)
	{
		index = 1;
	}

	random_shuffle(v[index].begin(), v[index].end());
	for (vector<int>::iterator it = v[index].begin(); it != v[index].end(); it++)
	{
		cout << *it << " ";
		Sleep(50);
	}
	cout << endl;
	cout << "-----------------------------------------------------------------------------------" << endl;


	system("pause");
	cout << endl;

}

//比赛
void SpeechManager::SpeechContest()
{
	
	//临时容器，存放小组成绩,用于选出前三
	multimap<double, int, greater<double>> GroupScore;
	int num = 0;//计数，用于分组
	int index = 0;
	cout << "-----------------------第" << this->m_Index << "轮比赛开始------------------------" << endl;
	
	if (m_Index == 2)
	{
		index = 1;
	}

	//遍历所有选手进行比赛打分
	for (vector<int>::iterator it = v[index].begin(); it != v[index].end(); it++)
	{
		num++;
		//因要求打分后要去最高分和最低分，用deque
		deque<double> d;
		for (int i = 0; i < REFEREE; i++)
		{
			double score = (rand() % 401 + 600) / 10.f;//使得得分在60.0~100
			d.push_back(score);
		}

		sort(d.begin(), d.end(), greater<double>());
		d.pop_back();//去最高最低
		d.pop_front();

		double sum = accumulate(d.begin(), d.end(), 0.0f);
		double avg = sum / d.size();

		//记录成绩
		this->m_Speaker[*it].m_Score[index] = avg;

		GroupScore.insert(make_pair(avg, *it));//key是分数

		
		//输出每组成绩，并且每组取前三存放
		if (num % 6 == 0)
		{
			if (this->m_Index == 1)
			{
				cout << "第" << num / 6 << "小组比赛名次：" << endl;
			}
			else
			{
				cout << "决赛名次：" << endl;
			}
		
			for (multimap<double, int, greater<double>>::iterator it = GroupScore.begin(); it != GroupScore.end(); it++)
			{
				cout << "编号：" << it->second << "\t姓名：" << this->m_Speaker[it->second].m_Name << "\t成绩：" << it->first << endl;
				Sleep(100);
			}
			cout << endl;

			int count = 0;
			for (multimap<double, int, greater<double>>::iterator it = GroupScore.begin(); it != GroupScore.end() && count < 3; count++, it++)
			{
				if (this->m_Index == 1)
				{
					v[1].push_back(it->second);
				}
				else
				{
					v[2].push_back(it->second);
				}
			}

			GroupScore.clear();

		}

	}
	cout << "----------------------第" << this->m_Index << "轮比赛结束---------------------------" << endl << endl;

	system("pause");


}

//显示比赛结果
void SpeechManager::ShowScore()
{
	cout << "-------------------第" << this->m_Index << "轮晋级选手信息如下：--------------------" << endl;
	vector<int> vp;
	if (this->m_Index == 1)
	{
		vp = this->v[1];
	}
	else
	{
		vp = this->v[2];
	}

	for (vector<int>::iterator it = vp.begin(); it != vp.end(); it++)
	{
		cout << "编号：" << *it << "\t姓名： " << m_Speaker[*it].m_Name << "\t得分： " << m_Speaker[*it].m_Score[this->m_Index - 1] << endl;
		Sleep(100);
	}
	cout << endl;
	system("pause");
	system("cls");
	this->Menu();
}

//展示获奖得主
void SpeechManager::ShowChampion()
{
	cout << "*************************************************" << endl;
	cout << "*********     本次比赛获奖人员如下     **********" << endl;
	cout << "*********         冠军：" << this->m_Speaker[v[2][0]].m_Name << "          **********" << endl;
	cout << "*********  亚军：" << this->m_Speaker[v[2][1]].m_Name << "   季军：" << this->m_Speaker[v[2][2]].m_Name << "   **********" << endl;
	cout << "*************************************************" << endl;


}

//读取记录分
void SpeechManager::LoadRecord()
{
	ifstream ifs(FILENAME, ios::in);//输入流对象 读取文件

	//文件不存在
	if (!ifs.is_open())
	{
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}

	//文件为空
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}

	//文件不为空
	this->fileIsEmpty = false;

	ifs.putback(ch);//读取的单个字符放回去

	string date;
	int index = 0;
	while (ifs >> date)
	{
		vector<string> v;
		//利用字符查找和字串获取来获取数据
		int pos = -1;
		int start = 0;

		while (true)
		{
			pos = date.find(",",start);
			if (pos == -1)
			{
				break;
			}
			string tmp = date.substr(start, pos - start);
			v.push_back(tmp);
			start = pos + 1;
		}

		this->m_Record.insert(make_pair(index, v));
		index++;
	}
	ifs.close();

}

//保存分数
void SpeechManager::SaveRecord()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out | ios::app);//用输出的方式打开文件-写文件

	//将每个人数据写入到文件中
	for (vector<int>::iterator it = v[2].begin(); it != v[2].end(); it++)
	{
		ofs << *it << "," << m_Speaker[*it].m_Score[1] << ",";
	}
	ofs << endl;

	//关闭文件
	ofs.close();
	//cout << "数据已保存！" << endl;
	this->fileIsEmpty = false;
}
//查看往届记录
void SpeechManager::ShowRecord()
{
	if (this->fileIsEmpty)
	{
		cout << "文件不存在，或记录为空!" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_Record.size(); i++)
		{
			cout << "第" << i + 1 << "届 " 
				<<"冠军编号：" << this->m_Record[i][0] 
				<< " 得分：" << this->m_Record[i][1].substr(0,this->m_Record[i][1].find(".")+3)//利用字符串截取，保留两位小数
				<< "\t亚军编号：" << this->m_Record[i][2] 
				<< " 得分：" << this->m_Record[i][3].substr(0, this->m_Record[i][3].find(".") + 3)
				<< "\t季军编号：" << this->m_Record[i][4] 
				<< " 得分：" << this->m_Record[i][5].substr(0, this->m_Record[i][5].find(".") + 3)
				<< endl;

			Sleep(25);
		}


	}
	system("pause");
	system("cls");
}
//清空记录
void SpeechManager::ClearRecord()
{
	cout << "确认清空？" << endl;
	cout << "1、确认" << endl;
	cout << "2、返回" << endl;
	
	int choice = 0;
	cin >> choice;
	while (choice != 1 && choice != 2)
	{
		cout << "输入有误，请重新输入：";
		cin >> choice;
	}

	if (1 == choice)
	{
		//打开模式 ios::trunc 如果存在删除文件并重新创建
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();

		//更新记录数据
		this->InitSpeech();
		this->CreateSpeaker();
		this->LoadRecord();

		cout << "清空成功！" << endl;
	}

	system("pause");
	system("cls");
}
//析构
SpeechManager::~SpeechManager()
{
	//空实现即可
}

//菜单
void SpeechManager::Menu()
{
	cout << "###########################################" << endl;
	cout << "#######                             #######" << endl;
	cout << "#########     欢迎参加演讲比赛    #########" << endl;
	cout << "##########    1.开始演讲比赛     ##########" << endl;	
	cout << "##########    2.查看往届记录     ##########" << endl;
	cout << "##########    3.清空比赛记录     ##########" << endl;
	cout << "#########     0.退出比赛程序      #########" << endl;
	cout << "#######                             #######" << endl;
	cout << "###########################################" << endl;
	cout << endl;
}


//退出系统
void SpeechManager::ExitSystem()
{
	cout << "欢迎下次使用！" << endl;
	system("pause");
	exit(0);
}
