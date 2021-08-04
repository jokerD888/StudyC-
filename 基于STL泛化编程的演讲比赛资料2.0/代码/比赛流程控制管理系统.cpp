#include"SpeechManager.h"



//比赛规则
//* 学校举行一场演讲比赛，共有12个人 参加。 比赛共两轮 ，第一轮为淘汰赛，第二轮为决赛。
//* 比赛方式： 分组比赛，每组6个人 ；选手每次要随机分组，进行比赛
//* 每名选手都有对应的 编号 ，如 10001 ~10012
//* 第一轮分为两个小组，每组6个人。 整体按照选手编号进行 抽签 后顺序演讲。
//* 当小组演讲完后，淘汰组内排名最后的三个选手， 前三名晋级 ，进入下一轮的比赛。
//* 第二轮为决赛， 前三名胜出 
//*每轮比赛过后需要 显示晋级选手的信息 
//
//### 1.2 程序功能
//* 开始演讲比赛：完成整届比赛的流程，每个比赛阶段需要给用户一个提示，用户按任意键后继续下一个阶段
//* 查看往届记录：查看之前比赛前三名结果，每次比赛都会记录到文件中，文件用.csv后缀名保存
//* 清空比赛记录：将文件中数据清空
//* 退出比赛程序：可以退出当前程序


int main(void)
{
	srand((unsigned int)time(NULL));
	cout << setiosflags(ios::fixed) << setprecision(2);//之后的实数输出保留两位小数
	SpeechManager sm;
	
	int choice = 0;
	while (true)
	{
		sm.Menu();
		cout << "请选择：";
		cin >> choice;
		while (choice != 0 && choice != 1 && choice != 2 && choice != 3)
		{
			cout << "输入有误，请重新输入：";
			cin >> choice;
		}
		switch (choice)
		{
		case 1:
			sm.StartSpeech();
			break;
		case 2:
			sm.ShowRecord();
			break;
		case 3:
			sm.ClearRecord();
			break;
		case 0:
			sm.ExitSystem();
			break;
		default:
			break;
		}
	}
	return 0;
}