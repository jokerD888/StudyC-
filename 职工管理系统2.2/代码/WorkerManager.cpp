#define _CRT_SECURE_NO_WARNINGS 1
#include"WorkerManager.h"



//���캯��
WorkerManager::WorkerManager()
{

	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	//�ļ�������
	if (!ifs.is_open())
	{
		//cout << "�ļ������ڣ�" << endl;
		this->m_num = 0;
		this->m_size = 1;
		this->m_EmpArray = new Worker*[this->m_size];
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//�ļ����ڵ�����Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//cout << "�ļ�Ϊ�գ�" << endl;
		this->m_num = 0;
		this->m_size = 1;
		this->m_EmpArray = new Worker * [this->m_size];
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	this->m_num = this->GetEmpNum();
	//��ʼ������
	//this->m_num = this->GetEmpnum();
	//this->m_size = 1;
	//this->m_EmpArray = new Worker*[this->m_size];

	//����ְ������ʼ�������ݻ�
	this->m_size = this->m_num;
	this->m_EmpArray = new Worker * [this->m_size];

	WorkerManager::InitEmp();

}

//��������
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
//�˵�
void WorkerManager::Menu()
{
	cout << "##################################################" << endl;
	cout << "########                                 #########" << endl;
	cout << "########            0.�˳�               #########" << endl;
	cout << "########  1.���ְ��     2.�������      #########" << endl;
	cout << "########  3.ɾ��ְ��     4.����ְ��      #########" << endl;
	cout << "########  5.ְԱ���     6.�������      #########" << endl;
	cout << "########  7.�������     8.��ʾȫ����Ϣ  #########" << endl;
	cout << "########                                 #########" << endl;
	cout << "##################################################" << endl;

}

void WorkerManager::Expand(int n = 1)
{
	//Ĭ����������,�ɸ���ʵ�ʽ��ж�̬����
	int multiple = 2;
	if (n > this->m_size)
	{
		multiple = (n / m_size) + 1;
	}

	Worker** newSpace = new Worker * [this->m_size *multiple ];

	if (newSpace == NULL)
	{
		cout << "����ʧ�ܣ�" << endl;
		exit(0);
	}
	for (int i = 0; i < this->m_num; i++)
	{
		newSpace[i] = this->m_EmpArray[i];
	}

	//�޸�����
	this->m_size *= multiple;

	//�ͷ�ԭ�пռ�
	delete[] this->m_EmpArray;
	//ָ���¿��ٵĿռ�
	this->m_EmpArray = newSpace;
}
//��������Ա��
void WorkerManager::AddEmp()
{

	

	//���ˣ���ԭ����2������
	if (this->m_num == this->m_size)
	{
		WorkerManager::Expand();
	}
	int id = 0;

	bool flag = true;
	while (flag)
	{
		cout << "������Ա����ţ�" << endl;
		cin >> id;
		//�жϱ���Ƿ��Ѵ���
		if (-1 == IsExist(id))
		{
			flag = false;
		}
		else
		{
			cout << "����Ѵ��ڣ�����ϸȷ�ϣ�" << endl;
		}
	}
	cout << "������Ա��������" << endl;
	string name;
	cin >> name;

	cout << "��ѡ��Ա��ְλ��" << endl;
	cout << "1.��ͨԱ��\t2.����\t\t3.�ܲ�" << endl;
	int choice = 0;
	cin >> choice;

	Worker* worker=NULL;
	//�Ա��ϰ棬�ϰ�û�ж�1��2��3������������Ч�ж�,�������Ǵ���������ʱ���ᵼ���޷�¼��Ա����Ϣ
	//�ڴ˶������ѡ������Ч���ж�,ֻ�е�ѡ������3���е�����һ�֣�����ſɼ�������
	while (choice != 1 && choice != 2 && choice != 3)
	{
		cout << "��������������ѡ��" << endl;
		cin >> choice;

	}
	//����������Ϣ������ӦԱ����Ϣ
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

	//��ǰ����++
	this->m_num++;

	this->Save();

	this->m_FileIsEmpty = false;

	cout << "��ӳɹ���" << endl;

}


void WorkerManager::BatchAddEmp()
{

	cout << "������Ҫ���ӵ�Ա����Ŀ��" << endl;
	int n;
	cin >> n;
	
	//����װ������
	if (this->m_num + n > this->m_size)
	{
		this->Expand(n);
	}

	for (int i = 0; i < n; i++)
	{
		cout << "��ʼ¼���" << i+1 << "���˵���Ϣ" << endl;
		this->AddEmp(); 
	}

	cout << "ȫ����Ϣ¼����ɣ�" << endl;
	system("pause");
	system("cls");
}

//��ʾԱ����Ϣ
void WorkerManager::ShowEmp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "-------------------------Ա����Ϣ����--------------------------" << endl << endl;;

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
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "����Ҫ����Ż��ǰ�������ɾ������1.���  2.������" << endl;
	int opt = 0;
	cin >> opt;
	while (opt != 1 && opt != 2)
	{
		cout << "�����������������룺" << endl;
		cin >> opt;

	}
	
	//�����ɾ��
	if (1 == opt)
	{

		cout << "������ɾ��Ա���ı�ţ�" << endl;
		int id = 0;
		cin >> id;
		int index = this->IsExist(id);
		if (-1 == index)
		{
			cout << "���޴���" << endl;
			system("pause");
			system("cls");
			return;
		}

		cout << "ȷ��ɾ��������Ϣ��(1.Yes  2.No)��" << endl;
		this->m_EmpArray[index]->ShowInfo();
		int choice = 0;
		cin >> choice;
		while (choice != 1 && choice != 2)
		{
			cout << "�����������������룺" << endl;
			cin >> choice;
		}

		if (2 == choice)
		{
			cout << "ȡ��ɾ����" << endl;
		}

		//����ǰ�ƣ�ʵ�ָ���ɾ��
		if (1 == choice)
		{
			for (int i = index; i < this->m_num - 1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_num--;
			this->Save();
			cout << "ɾ���ɹ���" << endl;
		}
	}

	//������ɾ��
	if (2 == opt)
	{
		string name;
		int index = 0;//ȷ��ɾ��Ա�����±�
		int sum = 0;//ͬ������
		int* arr = new int[this->m_num];//����ͬ���˵ı��
		int j = 0;
		cout << "������Ա����������" << endl;
		cin >> name;
		cout << "-------------------------��Ϣ����----------------------------" << endl << endl;
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

		if (sum > 1)//����ͬ�������,��index��λ��Ҫɾ�����˵��±�
		{
			int id;
			cout << "���鵽" << sum << "��ͬ����Ϣ����ѡ��Ҫɾ���ı�ţ�" << endl;
			cin >> id;
						//������ı�����ж�,����Ƿ���������ʾ������ͬ�����˵ı��
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
					cout << "ѡ������������ѡ��" << endl;
					cin >> id;
				}

			}
			index = this->IsExist(id);
		}

		cout << "ȷ��ɾ��������Ϣ��(1.Yes  2.No)��" << endl;
		this->m_EmpArray[index]->ShowInfo();
		int choice = 0;
		cin >> choice;
		while (choice != 1 && choice != 2)
		{
			cout << "�����������������룺" << endl;
			cin >> choice;
		}

		if (2 == choice)
		{
			cout << "ȡ��ɾ����" << endl;
		}

		if (1 == choice)
		{
			for (int i = index; i < this->m_num - 1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_num--;
			this->Save();
			cout << "ɾ���ɹ���" << endl;
		}


		delete[] arr;//�ͷ�
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
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "����Ҫ���ձ�Ż��ǰ����������ң���1.���  2.������" << endl;
	int choice = 0;
	cin >> choice;
	while (choice != 1 && choice != 2)
	{
		cout << "�����������������룺" << endl;
		cin >> choice;

	}

	if (1 == choice)
	{
		cout << "������Ա���ı�ţ�" << endl;
		int id = 0;
		cin >> id;
		int index = this->IsExist(id);
		if (-1 == index)
		{
			cout << "���޴���" << endl;
			system("pause");
			system("cls");
			return;
		}
		cout << "-------------------------��Ϣ����----------------------------" << endl << endl;
		this->m_EmpArray[index]->ShowInfo();
	}

	if (2 == choice)
	{
		cout << "������Ա����������" << endl;
		string name;
		int id = 0;//�����ͬ�������ñ�Ų���
		int sum = 0;//ͬ������
		int* arr = new int[this->m_num];//����ͬ���˵ı��
		int j = 0;
		cin >> name;
		cout << "-------------------------��Ϣ����----------------------------" << endl << endl;
		
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
			cout << "���鵽" << sum << "��ͬ����Ϣ����ѡ��Ҫ�鿴�ı�ţ�" << endl;
			cin >> id;
			//������ı�����ж�,����Ƿ���������ʾ������ͬ�����˵ı��
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
					cout << "ѡ������������ѡ��" << endl;
					cin >> id;
				}

			}
			int index = this->IsExist(id);
			cout << "������Ϣ���£�" << endl;
			this->m_EmpArray[index]->ShowInfo();

		}

		delete[] arr;//�ͷ�

	}
	system("pause");
	system("cls");
}

void WorkerManager::ModEmp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "��������Ҫ�޸ĵ�Ա���ı�ţ�" << endl;
	cout << "���������Ա���ı�ţ����˳������������ҹ��ܲ�ѯ��ź��ٽ����޸ģ�0.�˳��޸� 1.�����޸� �� " << endl;
	int choice = 0;
	cin >> choice;
	while (choice != 0 && choice != 1)
	{
		cout << "�����������������룺" << endl;
		cin >> choice;
	}

	if (0 == choice)
	{
		cout << "�˳��޸ģ�" << endl;
	}

	if (1 == choice)
	{
		int id = 0;
		cout << "�������޸ĵ�Ա����ţ�" << endl;
		cin >> id;
		int index = this->IsExist(id);

		if (-1 == index)
		{
			cout << "���޴���" << endl;
		}
		else
		{
			cout << "������Ϣ���£�" << endl;
			this->m_EmpArray[index]->ShowInfo();
			cout << "��ѡ���޸ĵ���Ϣ������ѡ��1.���  2.����  3.ְλ  4.ȫ����Ϣ ��" << endl;
			int opt = 0;
			cin >> opt;
			while (opt != 1 && opt != 2 && opt != 3 && opt != 4)
			{
				cout << "�����������������룺" << endl;
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
				cout << "�������±�ţ�" << endl;
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
				cout << "��������������" << endl;
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
				cout << "��ѡ����ְλ����1.��ͨԱ��  2.����  3.�ܲã�" << endl;
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
				cout << "�������±�ţ�" << endl;
				cin >> newId;
				cout << "��������������" << endl;
				cin >> newName;
				cout << "��ѡ����ְλ����1.��ͨԱ��  2.����  3.�ܲã�" << endl;
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

			//��new��Ϣ��ʼ����ֵΪold��Ϣ��������4�������ظ�������Ϊһ
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


			//�ͷž����ݿռ�
			delete this->m_EmpArray[index];	

			//ָ���¿ռ�
			this->m_EmpArray[index] = worker;

			cout << "�޸ĳɹ���" << endl;

			//���浽�ĵ�
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
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "��ѡ������ʽ����1.����  2.����" << endl;
	int choice = 0;
	cin >> choice;
	while (choice != 1 && choice != 2)
	{
		cout << "����������������룺" << endl;
		cin >> choice;
	}

	//ѡ������
	for (int i = 0; i < m_num; i++)
	{
		int index = i;
		for (int j = i + 1; j < m_num; j++)
		{
			if (1 == choice)//����
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
	cout << "����ɹ����������Ϣ����" << endl;
	this->ShowEmp();
}
void WorkerManager::CleanFile()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "ȷ����գ�(1.ȷ��  2.���أ�" << endl;
	int choice = 0;
	cin >> choice;
	while (1 != choice && 2 != choice)
	{
		cout << "����������������룺" << endl;
		cin >> choice;
	}

	if (1 == choice)
	{
		//��ģʽ ios::trunc �������ɾ���ļ������´���
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

		cout << "��ճɹ���" << endl;
	}

	system("pause");
	system("cls");

}
//�˳�
void WorkerManager::Exit()
{
	cout << "�˳�ϵͳ����ӭ�´�ʹ�ã�" << endl;
	system("pause");
	exit(0);
}

