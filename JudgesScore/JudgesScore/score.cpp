#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//��������
//��5��ѡ�֣�ѡ��ABCDE��10����ί�ֱ��ÿһ��ѡ�ִ�֣�ȥ����߷֣�ȥ����ί����ͷ֣�ȡƽ���֡�
//
//ʵ�ֲ���
//1. ��������ѡ�֣��ŵ�vector��
//2. ����vector������ȡ����ÿһ��ѡ�֣�ִ��forѭ�������԰�10�����ִ�ִ浽deque������
//3. sort�㷨��deque�����з�������ȥ����ߺ���ͷ�
//4. deque��������һ�飬�ۼ��ܷ�
//5. ��ȡƽ����

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
		string name = "ѡ��";
		name += nameSeed[i];
		int score = 0;//��ʼΪ0
		Person p(name, score);

		//��������
		v.push_back(p);
	}
}

//������⣬Ҫ����ȡ��С������ɴ˲���deque��Ϊ����
void SetScore(vector<Person>& v)
{
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		deque<int> d;
		for (int i = 0; i < 10; i++)
		{
			int score = rand() % 41 + 60;//ʹ�����ɵĵ÷���60~100֮��
			d.push_back(score);
		}

		//����
		sort(d.begin(), d.end());//�ǵ������㷨ͷ�ļ�

		//ȥ�����ͷ�
		d.pop_back();
		d.pop_front();

		int sum = 0;//�ܺ�
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
		cout << "������" << it->m_Name << "ƽ���֣�" << it->m_Score << endl;
	}
}
int main(void)
{
	//���������(�ڴ��ֶ��������鷳��������������ԣ�
	srand((unsigned int)time(NULL));

	//����һ��vector�������������ѡ�ֵ���Ϣ
	vector<Person>v;

	//������Ա��Ϣ
	CreatePerson(v);

	//��ѡ�ִ��
	SetScore(v);

	//��ʾ�÷�
	ShowScore(v);
	return 0;
}