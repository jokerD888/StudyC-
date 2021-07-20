#define _CRT_SECURE_NO_WARNINGS 1
#include"wokerManager.h"
#include"employee.h"
#include"worker.h"
#include"boss.h"
#include"manager.h"
void test01()
{
	Worker* worker = NULL;
	worker = new Employee(1, "����", 1);
	worker->showInfo();
	delete worker;

	worker = new Manager(2, "����", 2);
	worker->showInfo();
	delete worker;

	worker = new Boss(3, "����", 3);
	worker->showInfo();
	delete worker;
}
int main(void)
{
	/*test01();
	ʵ����������*/
	WorkerManager wm;
	int choice = 0;
	while (true)
	{
		wm.Show_Menu();

		cout << "����������ѡ��" << endl;
		cin >> choice;

		switch (choice)
		{
		case 0:		//�˳�ϵͳ
			wm.ExitSystem();
			break;
		case 1:		//���ְ��
			wm.Add_Emp();
			break;
		case 2:		//��ʾְ��
			wm.Show_Emp();
			break;
		case 3:		//ɾ��ְ��
			wm.Del_Emp();
			break;
		case 4:		//�޸�ְ��
			wm.Mod_Emp();
			break;
		case 5:		//����ְ��
			wm.Find_Emp();
			break;
		case 6:		//����ְ��
			wm.Sort_Emp();
			break;
		case 7:		//����ļ�
			wm.Clean_File();
			break;
		default:
			system("cls");
			break;
		}

	}
	return 0;
}

