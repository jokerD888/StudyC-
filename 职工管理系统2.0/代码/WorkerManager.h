#pragma once
#include<iostream>
using namespace std;
#include"worker.h"
#include<fstream>
#define FILENAME "empFile.txt"
//����һ�������࣬���ܹ�ʵ�־�����ɾ��ģ���ʾ��������յȹ��ܵĳ�Ա����
class WorkerManager
{
public:

	//���캯��
	WorkerManager();

	//��������
	~WorkerManager();
	//�˵�
	void Menu();

	//�˳�
	void Exit();

	//����
	void Expand(int n);

	//��������Ա��
	void AddEmp();

	//��������Ա��
	void BatchAddEmp();

	//��ʾ��˾Ա����Ϣ
	void ShowEmp();

	//�������ݵ�����
	void Save();

	//���ĵ��л�ȡԱ����Ŀ
	int GetEmpNum();

	//��ʼ��Ա������
	void InitEmp();

	//ɾ��Ա��
	void DelEmp();

	//����ְ������ж�ְ���Ƿ����,�����ڷ���ְ����������λ�ã������ڷ���-1
	int IsExist(int id);

	//����Ա����Ϣ
	void FindEmp();

	//�޸�Ա����Ϣ
	void ModEmp();

	//��Ա�������������ɽ�
	void SortEmp();

	//����ļ�����
	void CleanFile();
public:
	//Ա�������ָ��
	Worker** m_EmpArray;

	//����
	int m_size;

	//��ǰԱ������
	int m_num;

	//��־�ļ��Ƿ�Ϊ��
	bool m_FileIsEmpty;

};
