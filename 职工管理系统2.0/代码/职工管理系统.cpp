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
		cout << "请输入您的选择：" << endl;
		cin >> choice;

		switch (choice)
		{
		case 0:
			wm.Exit();
			break;
		case 1:
			wm.AddEmp();
			system("pause");//因批量增加员工函数中连续使用到此函数，若清屏操作放入函数内会影响BatchAddEmp()批量增加函数的使用体验
			system("cls");//故出此下策将清屏操作剥离函数，影响些许可读性
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
	worker = new Employee(1, "张三");
	worker->ShowInfo();
	delete worker;

	worker = new Manager(2, "李四");
	worker->ShowInfo();
	delete worker;

	worker = new Boss(3, "王五");
	worker->ShowInfo();
	delete worker;


}
int main(void)
{
	test01();
	//test02();
	return 0;
}


