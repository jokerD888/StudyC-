#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//案例描述
//有5名选手：选手ABCDE，10个评委分别对每一名选手打分，去除最高分，去除评委中最低分，取平均分。
//
//实现步骤
//1. 创建五名选手，放到vector中
//2. 遍历vector容器，取出来每一个选手，执行for循环，可以把10个评分打分存到deque容器中
//3. sort算法对deque容器中分数排序，去除最高和最低分
//4. deque容器遍历一遍，累加总分
//5. 获取平均分

#include<vector>
#include<deque>
#include<algorithm>
class Person
{
public:
	Person(string name, int score)
	{
		this->m_Name = name;
		this->m_Score = score;
	}

	string m_Name;

	int m_Score;

};
void CreatePerson(vector<Person>& v)
{
	string nameSeed = "ABCDE";
	for (int i = 0; i < 5; i++)
	{
		string name = "选手";
		name += nameSeed[i];
		int score = 0;//初始为0
		Person p(name, score);

		//放入容器
		v.push_back(p);
	}
}

//结合题意，要排序，取最小和最大，由此采用deque最为合适
void SetScore(vector<Person>& v)
{
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		deque<int> d;
		for (int i = 0; i < 10; i++)
		{
			int score = rand() % 41 + 60;//使得生成的得分在60~100之间
			d.push_back(score);
		}

		//排序
		sort(d.begin(), d.end());//记得引用算法头文件

		//去最高最低分
		d.pop_back();
		d.pop_front();

		int sum = 0;//总和
		for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
		{
			sum += *dit;
		}

		int avg = sum / d.size();
		it->m_Score = avg;

	}
}

void ShowScore(vector<Person>& v)
{
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "姓名：" << it->m_Name << "平均分：" << it->m_Score << endl;
	}
}
int main(void)
{
	//随机数种子(在此手动输入略麻烦，采用随机数测试）
	srand((unsigned int)time(NULL));

	//创建一个vector容器，存放五名选手的信息
	vector<Person>v;

	//创建人员信息
	CreatePerson(v);

	//给选手打分
	SetScore(v);

	//显示得分
	ShowScore(v);
	return 0;
}