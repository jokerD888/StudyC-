#define _CRT_SECURE_NO_WARNINGS 1
#include"WorkerManager.h"
#include"worker.h"




void test01()
{
	WorkerManager wm;
	int choice = 0;
	while (true)
	{
		wm.Menu();
		cout << "����������ѡ��" << endl;
		cin >> choice;

		switch (choice)
		{
		case 0:
			wm.Exit();
			break;
		case 1:
			wm.AddEmp();
			system("pause");//����������Ա������������ʹ�õ��˺������������������뺯���ڻ�Ӱ��BatchAddEmp()�������Ӻ�����ʹ������
			system("cls");//�ʳ����²߽������������뺯����Ӱ��Щ��ɶ���
			break;
		case 2:
			wm.BatchAddEmp();
			break;
		case 3:
			wm.DelEmp();
			break;
		case 4:
			wm.FindEmp();
			break;
		case 5:
			wm.ModEmp();
			break;
		case 6:
			wm.SortEmp();
			break;
		case 7:
			wm.CleanFile();
			break;
		case 8:
			wm.ShowEmp();
			break;
		default:
			break;
		}
	}
	 
}

void test02()
{
	Worker* worker = NULL;
	worker = new Employee(1, "����");
	worker->ShowInfo();
	delete worker;

	worker = new Manager(2, "����");
	worker->ShowInfo();
	delete worker;

	worker = new Boss(3, "����");
	worker->ShowInfo();
	delete worker;


}
int main(void)
{
	test01();
	//test02();
	return 0;
}


