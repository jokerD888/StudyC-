#define _CRT_SECURE_NO_WARNINGS 1
#include"WorkerManager.h"



//构造函数
WorkerManager::WorkerManager()
{

	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	//文件不存在
	if (!ifs.is_open())
	{
		//cout << "文件不存在！" << endl;
		this->m_num = 0;
		this->m_size = 1;
		this->m_EmpArray = new Worker*[this->m_size];
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//文件存在但数据为空
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//cout << "文件为空！" << endl;
		this->m_num = 0;
		this->m_size = 1;
		this->m_EmpArray = new Worker * [this->m_size];
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	this->m_num = this->GetEmpNum();
	//初始化容量
	//this->m_num = this->GetEmpnum();
	//this->m_size = 1;
	//this->m_EmpArray = new Worker*[this->m_size];

	//根据职工数初始化数组容积
	this->m_size = this->m_num;
	this->m_EmpArray = new Worker * [this->m_size];

	WorkerManager::InitEmp();

}

//析构函数
WorkerManager::~WorkerManager()
{
	if (this->m_EmpArray != NULL)
	{
		for (int i = 0; i < this->m_num; i++)
		{
			if (this->m_EmpArray[i] != NULL)
			{
				delete this->m_EmpArray[i];
			}
		}

		this->m_num = 0;
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
	}
}
//菜单
void WorkerManager::Menu()
{
	cout << "##################################################" << endl;
	cout << "########                                 #########" << endl;
	cout << "########            0.退出               #########" << endl;
	cout << "########  1.添加职工     2.批量添加      #########" << endl;
	cout << "########  3.删除职工     4.查找职工      #########" << endl;
	cout << "########  5.职员变更     6.编号排序      #########" << endl;
	cout << "########  7.清除数据     8.显示全部信息  #########" << endl;
	cout << "########                                 #########" << endl;
	cout << "##################################################" << endl;

}

void WorkerManager::Expand(int n = 1)
{
	//默认扩容两倍,可根据实际进行动态扩容
	int multiple = 2;
	if (n > this->m_size)
	{
		multiple = (n / m_size) + 1;
	}

	Worker** newSpace = new Worker * [this->m_size *multiple ];

	if (newSpace == NULL)
	{
		cout << "扩容失败！" << endl;
		exit(0);
	}
	for (int i = 0; i < this->m_num; i++)
	{
		newSpace[i] = this->m_EmpArray[i];
	}

	//修该容量
	this->m_size *= multiple;

	//释放原有空间
	delete[] this->m_EmpArray;
	//指向新开辟的空间
	this->m_EmpArray = newSpace;
}
//单个增加员工
void WorkerManager::AddEmp()
{

	

	//满了，按原来的2倍扩容
	if (this->m_num == this->m_size)
	{
		WorkerManager::Expand();
	}
	int id = 0;

	bool flag = true;
	while (flag)
	{
		cout << "请输入员工编号：" << endl;
		cin >> id;
		//判断编号是否已存在
		if (-1 == IsExist(id))
		{
			flag = false;
		}
		else
		{
			cout << "编号已存在，请仔细确认！" << endl;
		}
	}
	cout << "请输入员工姓名：" << endl;
	string name;
	cin >> name;

	cout << "请选择员工职位：" << endl;
	cout << "1.普通员工\t2.经理\t\t3.总裁" << endl;
	int choice = 0;
	cin >> choice;

	Worker* worker=NULL;
	//对比上版，上版没有对1，2，3三中数字做有效判断,造成输入非此三种数据时，会导致无法录入员工信息
	//在此对输入的选择做有效性判断,只有当选择是这3种中的其中一种，程序才可继续运行
	while (choice != 1 && choice != 2 && choice != 3)
	{
		cout << "输入有误，请重新选择：" << endl;
		cin >> choice;

	}
	//根据输入信息创建对应员工信息
	switch (choice)
	{
	case 1:
		worker = new Employee(id, name);
		break;
	case 2:
		worker = new Manager(id, name);
		break;
	case 3:
		worker = new Boss(id, name);
		break;
	default:
		break;
	}
	m_EmpArray[this->m_num] = worker; 

	//当前人数++
	this->m_num++;

	this->Save();

	this->m_FileIsEmpty = false;

	cout << "添加成功！" << endl;

}


void WorkerManager::BatchAddEmp()
{

	cout << "请输入要增加的员工数目：" << endl;
	int n;
	cin >> n;
	
	//不够装，扩容
	if (this->m_num + n > this->m_size)
	{
		this->Expand(n);
	}

	for (int i = 0; i < n; i++)
	{
		cout << "开始录入第" << i+1 << "个人的信息" << endl;
		this->AddEmp(); 
	}

	cout << "全部信息录入完成！" << endl;
	system("pause");
	system("cls");
}

//显示员工信息
void WorkerManager::ShowEmp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "-------------------------员工信息如下--------------------------" << endl << endl;;

	for (int i = 0; i < this->m_num; i++)
	{
		this->m_EmpArray[i]->ShowInfo();
	}

	cout<<endl << "--------------------------------------------------------------" << endl;

	system("pause");
	system("cls");
}

void WorkerManager::Save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	
	for (int i = 0; i < this->m_num; i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_dId << endl; 
	}

	ofs.close();
}

int WorkerManager::GetEmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;

	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
		num++;

	ifs.close();

	return num;

}

void WorkerManager::InitEmp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;

	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		Worker* worker = NULL;

		if (dId == 1)
		{
			worker = new Employee(id, name);
		}
		else if (dId == 2)
		{
			worker = new Manager(id, name);
		}
		else if (dId == 3)
		{
			worker = new Boss(id, name);
		}

		this->m_EmpArray[index] = worker;
		index++;
	}


}

void WorkerManager::DelEmp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "您是要按编号还是按照姓名删除？（1.编号  2.姓名）" << endl;
	int opt = 0;
	cin >> opt;
	while (opt != 1 && opt != 2)
	{
		cout << "输入有误，请重新输入：" << endl;
		cin >> opt;

	}
	
	//按编号删除
	if (1 == opt)
	{

		cout << "请输入删除员工的编号：" << endl;
		int id = 0;
		cin >> id;
		int index = this->IsExist(id);
		if (-1 == index)
		{
			cout << "查无此人" << endl;
			system("pause");
			system("cls");
			return;
		}

		cout << "确定删除此人信息吗？(1.Yes  2.No)？" << endl;
		this->m_EmpArray[index]->ShowInfo();
		int choice = 0;
		cin >> choice;
		while (choice != 1 && choice != 2)
		{
			cout << "输入有误，请重新输入：" << endl;
			cin >> choice;
		}

		if (2 == choice)
		{
			cout << "取消删除！" << endl;
		}

		//数据前移，实现覆盖删除
		if (1 == choice)
		{
			for (int i = index; i < this->m_num - 1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_num--;
			this->Save();
			cout << "删除成功！" << endl;
		}
	}

	//按姓名删除
	if (2 == opt)
	{
		string name;
		int index = 0;//确认删除员工的下标
		int sum = 0;//同名人数
		int* arr = new int[this->m_num];//储存同名人的编号
		int j = 0;
		cout << "请输入员工的姓名：" << endl;
		cin >> name;
		cout << "-------------------------信息如下----------------------------" << endl << endl;
		for (int i = 0; i < this->m_num; i++)
		{
			if (this->m_EmpArray[i]->m_Name == name)
			{
				this->m_EmpArray[i]->ShowInfo();
				arr[j++] = this->m_EmpArray[i]->m_Id;
				sum++;
				index = i;
			}
		}
		cout<<endl;

		if (sum > 1)//多人同名的情况,对index定位到要删除的人的下标
		{
			int id;
			cout << "共查到" << sum << "条同名信息，请选择要删除的编号：" << endl;
			cin >> id;
						//对输入的编号做判断,检查是否是上面显示出来的同名的人的编号
			while (true)
			{
				int i = 0;
				for ( i = 0; i < j; i++)
				{
					if (arr[i] == id)
						break;
				}
				if (i < j)
					break;
				else
				{
					cout << "选择有误，请重新选择：" << endl;
					cin >> id;
				}

			}
			index = this->IsExist(id);
		}

		cout << "确定删除此人信息吗？(1.Yes  2.No)？" << endl;
		this->m_EmpArray[index]->ShowInfo();
		int choice = 0;
		cin >> choice;
		while (choice != 1 && choice != 2)
		{
			cout << "输入有误，请重新输入：" << endl;
			cin >> choice;
		}

		if (2 == choice)
		{
			cout << "取消删除！" << endl;
		}

		if (1 == choice)
		{
			for (int i = index; i < this->m_num - 1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_num--;
			this->Save();
			cout << "删除成功！" << endl;
		}


		delete[] arr;//释放
	}


	system("pause");
	system("cls");
}
int WorkerManager::IsExist(int id)
{

	for (int i = 0; i < this->m_num; i++)
	{
		if (this->m_EmpArray[i]->m_Id == id)
		{
			return i;
		}
	}

	return -1;
}

void WorkerManager::FindEmp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "您是要按照编号还是按照姓名查找？（1.编号  2.姓名）" << endl;
	int choice = 0;
	cin >> choice;
	while (choice != 1 && choice != 2)
	{
		cout << "输入有误，请重新输入：" << endl;
		cin >> choice;

	}

	if (1 == choice)
	{
		cout << "请输入员工的编号：" << endl;
		int id = 0;
		cin >> id;
		int index = this->IsExist(id);
		if (-1 == index)
		{
			cout << "查无此人" << endl;
			system("pause");
			system("cls");
			return;
		}
		cout << "-------------------------信息如下----------------------------" << endl << endl;
		this->m_EmpArray[index]->ShowInfo();
	}

	if (2 == choice)
	{
		cout << "请输入员工的姓名：" << endl;
		string name;
		int id = 0;//如果有同名，再用编号查找
		int sum = 0;//同名人数
		int* arr = new int[this->m_num];//储存同名人的编号
		int j = 0;
		cin >> name;
		cout << "-------------------------信息如下----------------------------" << endl << endl;
		
		for (int i = 0; i < this->m_num; i++)
		{
			if (this->m_EmpArray[i]->m_Name == name)
			{
				this->m_EmpArray[i]->ShowInfo();
				arr[j++] = this->m_EmpArray[i]->m_Id;
				sum++;
			}
		}

		if (sum > 1)
		{
			cout << "共查到" << sum << "条同名信息，请选择要查看的编号：" << endl;
			cin >> id;
			//对输入的编号做判断,检查是否是上面显示出来的同名的人的编号
			while (true)
			{
				int i = 0;
				for ( i = 0; i < j; i++)
				{
					if (arr[i] == id)
						break;
				}
				if (i < j)
					break;
				else
				{
					cout << "选择有误，请重新选择：" << endl;
					cin >> id;
				}

			}
			int index = this->IsExist(id);
			cout << "此人信息如下：" << endl;
			this->m_EmpArray[index]->ShowInfo();

		}

		delete[] arr;//释放

	}
	system("pause");
	system("cls");
}

void WorkerManager::ModEmp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "请输入你要修改的员工的编号：" << endl;
	cout << "（若不清楚员工的编号，可退出利用姓名查找功能查询编号后再进行修改：0.退出修改 1.继续修改 ） " << endl;
	int choice = 0;
	cin >> choice;
	while (choice != 0 && choice != 1)
	{
		cout << "输入有误，请重新输入：" << endl;
		cin >> choice;
	}

	if (0 == choice)
	{
		cout << "退出修改！" << endl;
	}

	if (1 == choice)
	{
		int id = 0;
		cout << "请输入修改的员工编号：" << endl;
		cin >> id;
		int index = this->IsExist(id);

		if (-1 == index)
		{
			cout << "查无此人" << endl;
		}
		else
		{
			cout << "此人信息如下：" << endl;
			this->m_EmpArray[index]->ShowInfo();
			cout << "请选择修改的信息：（单选：1.编号  2.姓名  3.职位  4.全部信息 ）" << endl;
			int opt = 0;
			cin >> opt;
			while (opt != 1 && opt != 2 && opt != 3 && opt != 4)
			{
				cout << "输入有误，请重新输入：" << endl;
				cin >> opt;
			}
			
			Worker* worker = NULL;
			int oldDId = this->m_EmpArray[index]->m_dId;
			int oldId = this->m_EmpArray[index]->m_Id;
			string oldName = this->m_EmpArray[index]->m_Name;
			int newId = oldId;
			string newName = oldName;
			int newDId = oldDId;

			if (1 == opt)
			{
				cout << "请输入新编号：" << endl;
				cin >> newId;
				//switch(oldDId)
				//{
				//case 1:
				//	worker = new Employee(newId, oldName);
				//	break;
				//case 2:
				//	worker = new Manager(newId, oldName);
				//	break;
				//case 3:
				//	worker = new Boss(newId, oldName);
				//	break;
				//default:
				//	break;
				//}
			}
			else if (2 == opt)
			{
				cout << "请输入新姓名：" << endl;
				cin >> newName;
				/*switch (oldDId)
				{
				case 1:
					worker = new Employee(oldId, newName);
					break;
				case 2:
					worker = new Manager(oldId, newName);
					break;
				case 3:
					worker = new Boss(oldId, newName);
					break;
				default:
					break;
				}*/
			}
			else if (3 == opt)
			{
				cout << "请选择新职位：（1.普通员工  2.经理  3.总裁）" << endl;
				cin >> newDId;
				/*switch (newDId)
				{
				case 1:
					worker = new Employee(oldId, oldName);
					break;
				case 2:
					worker = new Manager(oldId, oldName);
					break;
				case 3:
					worker = new Boss(oldId, oldName);
					break;
				default:
					break;
				}*/
			}
			else if (4 == opt)
			{
				cout << "请输入新编号：" << endl;
				cin >> newId;
				cout << "请输入新姓名：" << endl;
				cin >> newName;
				cout << "请选择新职位：（1.普通员工  2.经理  3.总裁）" << endl;
				cin >> newDId;

				//switch (newDId)
				//{
				//case 1:
				//	worker = new Employee(newId, newName);
				//	break;
				//case 2:
				//	worker = new Manager(newId,newName);
				//	break;
				//case 3:
				//	worker = new Boss(newId, newName);
				//	break;
				//default:
				//	break;
				//}

			}

			//将new信息初始化赋值为old信息，将以上4个相似重复代码简而为一
			switch (newDId)
			{
			case 1:
				worker = new Employee(newId, newName);
				break;
			case 2:
				worker = new Manager(newId,newName);
				break;
			case 3:
				worker = new Boss(newId, newName);
				break;
			default:
				break;
			}


			//释放旧数据空间
			delete this->m_EmpArray[index];	

			//指向新空间
			this->m_EmpArray[index] = worker;

			cout << "修改成功！" << endl;

			//保存到文档
			this->Save();

		}

	}

	system("pause");
	system("cls");

}

void WorkerManager::SortEmp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "请选择排序方式：（1.升序  2.降序）" << endl;
	int choice = 0;
	cin >> choice;
	while (choice != 1 && choice != 2)
	{
		cout << "输出有误，请重新输入：" << endl;
		cin >> choice;
	}

	//选择排序法
	for (int i = 0; i < m_num; i++)
	{
		int index = i;
		for (int j = i + 1; j < m_num; j++)
		{
			if (1 == choice)//升序
			{
				if (this->m_EmpArray[j]->m_Id < this->m_EmpArray[index]->m_Id)
				{
					index = j;
				}
			}
			else
			{
				if (this->m_EmpArray[j]->m_Id > this->m_EmpArray[index]->m_Id)
				{
					index = j;
				}
			}

		}

		if (i != index)
		{
			Worker* tmp = m_EmpArray[i];
			m_EmpArray[i] = m_EmpArray[index];
			m_EmpArray[index] = tmp;
		}
	}

	this->Save();
	cout << "排序成功，排序后信息如下" << endl;
	this->ShowEmp();
}
void WorkerManager::CleanFile()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "确定清空？(1.确认  2.返回）" << endl;
	int choice = 0;
	cin >> choice;
	while (1 != choice && 2 != choice)
	{
		cout << "输出有误，请重新输入：" << endl;
		cin >> choice;
	}

	if (1 == choice)
	{
		//打开模式 ios::trunc 如果存在删除文件并重新创建
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();

		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_num; i++)
			{
				if (this->m_EmpArray[i] != NULL)
				{
					delete this->m_EmpArray[i];
				}
			}

			this->m_num = 0;
			delete[] m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_FileIsEmpty = true;

		}

		cout << "清空成功！" << endl;
	}

	system("pause");
	system("cls");

}
//退出
void WorkerManager::Exit()
{
	cout << "退出系统，欢迎下次使用！" << endl;
	system("pause");
	exit(0);
}

