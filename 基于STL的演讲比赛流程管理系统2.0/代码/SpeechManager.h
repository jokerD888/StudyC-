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
#define REFEREE 10 //��������
#define FILENAME "speech.csv"

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

	//������ʼѡ��
	void CreateSpeaker();

	//��ʼ������
	void StartSpeech();

	//��ǩ
	void SpeechDraw();

	//����
	void SpeechContest();

	//��ʾ�������
	void ShowScore();

	//չʾ�񽱵���
	void ShowChampion();

	//��ȡ��¼��
	void LoadRecord();

	//�������
	void SaveRecord();

	//�鿴�����¼
	void ShowRecord();

	//��ռ�¼
	void ClearRecord();

public:

	vector<vector<int>> v;//�洢���ֱ���ѡ�ֱ��

	map<int, Speaker> m_Speaker;//��ű�� �Լ���Ӧ�� ����ѡ�� ����

	int m_Index;//��������
	
	bool fileIsEmpty;//�ļ�Ϊ�ձ�־

	map<int, vector<string>> m_Record;

};
