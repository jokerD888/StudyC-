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
//����ݽ�������
class SpeechManager
{
public:

	//����
	SpeechManager();

	//����
	~SpeechManager();

	//�˵�
	void Menu();

	//�˳�ϵͳ
	void ExitSystem();

	//��ʼ������������
	void InitSpeech();

	//��ʼ������12��ѡ��
	void CreateSpeaker();

	//��ʼ���� - �������̿���
	void StartSpeech();

	//��ǩ
	void SpeechDraw();

	//����
	void SpeechContest();

	//��ʾ�������
	void ShowScore();

	//�����¼
	void SaveRecord();

	//��ȡ��¼
	void LoadRecord();

	//��ʾ����÷�
	void ShowRecord();

	//��ռ�¼
	void ClearRecord();

//��Ա���ԣ�

	//����ѡ�� ����  12��
	vector<int>v1;

	//��һ�ֽ�������  6��
	vector<int>v2;

	//ʤ��ǰ��������  3��
	vector<int>vVictory;

	//��ű�� �Լ���Ӧ�� ����ѡ�� ����
	map<int, Speaker> m_Speaker;

	//��¼��������
	int m_Index;

	//�ļ�Ϊ�յı�־
	bool fileIsEmpty;

	//�����¼
	map<int, vector<string>> m_Record;
};