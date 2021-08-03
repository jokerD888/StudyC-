#include"speechManager.h"


//比赛规则
//
//* 学校举行一场演讲比赛，共有12个人参加。 比赛共两轮 ，第一轮为淘汰赛，第二轮为决赛。
//* 比赛方式： 分组比赛，每组6个人 ；选手每次要随机分组，进行比赛
//* 每名选手都有对应的 编号 ，如 10001 ~10012
//* 第一轮分为两个小组，每组6个人。 整体按照选手编号进行抽签 后顺序演讲。
//* 当小组演讲完后，淘汰组内排名最后的三个选手， 前三名晋级 ，进入下一轮的比赛。
//* 第二轮为决赛， 前三名胜出 
//*每轮比赛过后需要 显示晋级选手的信息 
int main()
{
	srand((unsigned int)time(NULL));
	SpeechManager sm;

	int choice = 0;//接受用户的输入选择

	while (true)
	{
		sm.Menu();

		cout << "请输入您的选择： " << endl;
		cin >> choice; // 接受用户的选项

		switch (choice)
		{
		case 1:  //开始比赛
			sm.StartSpeech();
			break;
		case 2:  //查看记录
			sm.ShowRecord();
			break;
		case 3:  //清空记录
			sm.ClearRecord();
			break;
		case 0:  //退出系统
			sm.ExitSystem();
			break;
		default:
			system("cls"); //清屏
			break;
		}
	}

	return 0;
}