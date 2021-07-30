#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

//��������
//��˾������Ƹ��10��Ա����ABCDEFGHIJ����10��Ա�����빫˾֮����Ҫָ��Ա�����Ǹ����Ź���
//Ա����Ϣ��: ����  ������ɣ����ŷ�Ϊ���߻����������з�
//�����10��Ա�����䲿�ź͹���
//ͨ��multimap������Ϣ�Ĳ���  key(���ű��) value(Ա��)
//�ֲ�����ʾԱ����Ϣ

//ʵ�ֲ���
//1. ����10��Ա�����ŵ�vector��
//2. ����vector������ȡ��ÿ��Ա���������������
//3. ����󣬽�Ա�����ű����Ϊkey������Ա����Ϊvalue�����뵽multimap������
//4. �ֲ�����ʾԱ����Ϣ

#include <vector>
#include <map>
#include <ctime>

#define PLAN 0
#define ART 1
#define RAD 2    //research and development�з�

class Worker
{
public:
	string m_Name;
	int m_Salary;
};

void CreateWorker(vector<Worker>& v)
{
	string nameSeed = "ABCDEFGHIJ";
	for (int i = 0; i < 10; i++)
	{
		Worker worker;
		worker.m_Name = "Ա��";
		worker.m_Name += nameSeed[i];

		worker.m_Salary = rand() % 10000 + 10000;

		v.push_back(worker);
	}
}
   
void SetGroup(vector<Worker>& v, multimap<int, Worker>& m)
{
	//for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++)
	//{
	//	int deptId = rand() % 3;//0�߻� 1���� 2�з�

	//	////��Ա�����뵽������
	//	//key���ű�ţ�value����Ա��
	//	m.insert(make_pair(deptId, *it));
	//}
	for (int i = 0; i < 10; i++)
	{
		int deptId = rand() % 3;//0�߻� 1���� 2�з�

		////��Ա�����뵽������
		//key���ű�ţ�value����Ա��
		m.insert(make_pair(deptId, v[i]));
	}
}
void ShowWorkerByGroup(multimap<int, Worker>& m)
{
	cout << "------------------�߻�����-------------------------" << endl;
	multimap<int, Worker>::iterator pos = m.find(PLAN);
	int count = m.count(PLAN);
	int index = 0;
	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "������ " << pos->second.m_Name << " ���ʣ� " << pos->second.m_Salary << endl;
	}
	cout << endl;

	cout << "------------------��������-------------------------" << endl;
	pos = m.find(ART);
	count = m.count(ART);
	index = 0;
	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "������ " << pos->second.m_Name << " ���ʣ� " << pos->second.m_Salary << endl;
	}
	cout << endl;

	cout << "------------------�з�����-------------------------" << endl;
	pos = m.find(RAD);
	count = m.count(RAD);
	index = 0;
	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "������ " << pos->second.m_Name << " ���ʣ� " << pos->second.m_Salary << endl;
	}
	cout << endl;

}


int main(void)
{
	srand((unsigned int)time(NULL));

	//1������Ա��
	vector<Worker> vWorker;
	CreateWorker(vWorker);

	//2��Ա������
	multimap<int, Worker> mWorker;
	SetGroup(vWorker, mWorker);

	//3��������ʾԱ��
	ShowWorkerByGroup(mWorker);
}
