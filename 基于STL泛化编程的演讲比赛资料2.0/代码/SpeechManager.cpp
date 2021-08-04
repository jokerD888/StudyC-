
#include"SpeechManager.h"

//����
SpeechManager::SpeechManager()
{
	this->InitSpeech();
	this->CreateSpeaker();
	this->LoadRecord();//���������¼
}

//��ʼ������������
void SpeechManager::InitSpeech()
{
	v.clear();
	m_Speaker.clear();
	m_Record.clear();
	m_Index = 1;

	vector<int> v1;//��ų�ʼ����ѡ��
	vector<int> v2;//��ŵ�һ�ֽ�����Ա
	vector<int> v3;//���ǰ����

	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);

}

//������ʼѡ��
void  SpeechManager::CreateSpeaker()
{
	string nameSeed = "ABCDEFGHIJKL";
	for (int i = 0; i < 12; i++)
	{
		
		v[0].push_back(10001 + i);//��Ų���ѡ������
		string name = "ѡ��";
		name += nameSeed[i];//����Ϊѡ��A~L

		Speaker sp;
		sp.m_Name = name;
		sp.m_Score[0] = sp.m_Score[1] = 0;

		m_Speaker.insert(make_pair(10001 + i, sp));//����ź�����Ӧ��ѡ����Ϣ��������
	}

}

//��ʼ������
void SpeechManager::StartSpeech()
{
	//��ǩ
	//����
	//��ʾ�������

	for (int i = 0; i < 2; i++)
	{
		this->SpeechDraw();
		this->SpeechContest();
		this->ShowScore();
		this->m_Index = 2;
	}
	this->SaveRecord();
	this->ShowChampion();

	//Ϊ������������ʼ��׼��
	this->InitSpeech();
	this->CreateSpeaker();
	this->LoadRecord();//�����ȳ�ʼ����Ϻ�Ϊ�����ڱ��γ������ڼ�¼�ܹ��������α����ڶ�ȡ�Ա�����÷�


	system("pause");
	system("cls");
	
}

//��ǩ
void SpeechManager::SpeechDraw()
{
	cout << "��<< " << this->m_Index << " >>�ֱ���ѡ�����ڳ�ǩ......" << endl;
	Sleep(500);
	cout << "-----------------------------------------------------------------------------------" << endl;
	cout << "��ǩ���ݽ�˳�����£�" << endl;
	int index = 0;
	if (this->m_Index == 2)
	{
		index = 1;
	}

	random_shuffle(v[index].begin(), v[index].end());
	for (vector<int>::iterator it = v[index].begin(); it != v[index].end(); it++)
	{
		cout << *it << " ";
		Sleep(50);
	}
	cout << endl;
	cout << "-----------------------------------------------------------------------------------" << endl;


	system("pause");
	cout << endl;

}

//����
void SpeechManager::SpeechContest()
{
	
	//��ʱ���������С��ɼ�,����ѡ��ǰ��
	multimap<double, int, greater<double>> GroupScore;
	int num = 0;//���������ڷ���
	int index = 0;
	cout << "-----------------------��" << this->m_Index << "�ֱ�����ʼ------------------------" << endl;
	
	if (m_Index == 2)
	{
		index = 1;
	}

	//��������ѡ�ֽ��б������
	for (vector<int>::iterator it = v[index].begin(); it != v[index].end(); it++)
	{
		num++;
		//��Ҫ���ֺ�Ҫȥ��߷ֺ���ͷ֣���deque
		deque<double> d;
		for (int i = 0; i < REFEREE; i++)
		{
			double score = (rand() % 401 + 600) / 10.f;//ʹ�õ÷���60.0~100
			d.push_back(score);
		}

		sort(d.begin(), d.end(), greater<double>());
		d.pop_back();//ȥ������
		d.pop_front();

		double sum = accumulate(d.begin(), d.end(), 0.0f);
		double avg = sum / d.size();

		//��¼�ɼ�
		this->m_Speaker[*it].m_Score[index] = avg;

		GroupScore.insert(make_pair(avg, *it));//key�Ƿ���

		
		//���ÿ��ɼ�������ÿ��ȡǰ�����
		if (num % 6 == 0)
		{
			if (this->m_Index == 1)
			{
				cout << "��" << num / 6 << "С��������Σ�" << endl;
			}
			else
			{
				cout << "�������Σ�" << endl;
			}
		
			for (multimap<double, int, greater<double>>::iterator it = GroupScore.begin(); it != GroupScore.end(); it++)
			{
				cout << "��ţ�" << it->second << "\t������" << this->m_Speaker[it->second].m_Name << "\t�ɼ���" << it->first << endl;
				Sleep(100);
			}
			cout << endl;

			int count = 0;
			for (multimap<double, int, greater<double>>::iterator it = GroupScore.begin(); it != GroupScore.end() && count < 3; count++, it++)
			{
				if (this->m_Index == 1)
				{
					v[1].push_back(it->second);
				}
				else
				{
					v[2].push_back(it->second);
				}
			}

			GroupScore.clear();

		}

	}
	cout << "----------------------��" << this->m_Index << "�ֱ�������---------------------------" << endl << endl;

	system("pause");


}

//��ʾ�������
void SpeechManager::ShowScore()
{
	cout << "-------------------��" << this->m_Index << "�ֽ���ѡ����Ϣ���£�--------------------" << endl;
	vector<int> vp;
	if (this->m_Index == 1)
	{
		vp = this->v[1];
	}
	else
	{
		vp = this->v[2];
	}

	for (vector<int>::iterator it = vp.begin(); it != vp.end(); it++)
	{
		cout << "��ţ�" << *it << "\t������ " << m_Speaker[*it].m_Name << "\t�÷֣� " << m_Speaker[*it].m_Score[this->m_Index - 1] << endl;
		Sleep(100);
	}
	cout << endl;
	system("pause");
	system("cls");
	this->Menu();
}

//չʾ�񽱵���
void SpeechManager::ShowChampion()
{
	cout << "*************************************************" << endl;
	cout << "*********     ���α�������Ա����     **********" << endl;
	cout << "*********         �ھ���" << this->m_Speaker[v[2][0]].m_Name << "          **********" << endl;
	cout << "*********  �Ǿ���" << this->m_Speaker[v[2][1]].m_Name << "   ������" << this->m_Speaker[v[2][2]].m_Name << "   **********" << endl;
	cout << "*************************************************" << endl;


}

//��ȡ��¼��
void SpeechManager::LoadRecord()
{
	ifstream ifs(FILENAME, ios::in);//���������� ��ȡ�ļ�

	//�ļ�������
	if (!ifs.is_open())
	{
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}

	//�ļ�Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}

	//�ļ���Ϊ��
	this->fileIsEmpty = false;

	ifs.putback(ch);//��ȡ�ĵ����ַ��Ż�ȥ

	string date;
	int index = 0;
	while (ifs >> date)
	{
		vector<string> v;
		//�����ַ����Һ��ִ���ȡ����ȡ����
		int pos = -1;
		int start = 0;

		while (true)
		{
			pos = date.find(",",start);
			if (pos == -1)
			{
				break;
			}
			string tmp = date.substr(start, pos - start);
			v.push_back(tmp);
			start = pos + 1;
		}

		this->m_Record.insert(make_pair(index, v));
		index++;
	}
	ifs.close();

}

//�������
void SpeechManager::SaveRecord()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out | ios::app);//������ķ�ʽ���ļ�-д�ļ�

	//��ÿ��������д�뵽�ļ���
	for (vector<int>::iterator it = v[2].begin(); it != v[2].end(); it++)
	{
		ofs << *it << "," << m_Speaker[*it].m_Score[1] << ",";
	}
	ofs << endl;

	//�ر��ļ�
	ofs.close();
	//cout << "�����ѱ��棡" << endl;
	this->fileIsEmpty = false;
}
//�鿴�����¼
void SpeechManager::ShowRecord()
{
	if (this->fileIsEmpty)
	{
		cout << "�ļ������ڣ����¼Ϊ��!" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_Record.size(); i++)
		{
			cout << "��" << i + 1 << "�� " 
				<<"�ھ���ţ�" << this->m_Record[i][0] 
				<< " �÷֣�" << this->m_Record[i][1].substr(0,this->m_Record[i][1].find(".")+3)//�����ַ�����ȡ��������λС��
				<< "\t�Ǿ���ţ�" << this->m_Record[i][2] 
				<< " �÷֣�" << this->m_Record[i][3].substr(0, this->m_Record[i][3].find(".") + 3)
				<< "\t������ţ�" << this->m_Record[i][4] 
				<< " �÷֣�" << this->m_Record[i][5].substr(0, this->m_Record[i][5].find(".") + 3)
				<< endl;

			Sleep(25);
		}


	}
	system("pause");
	system("cls");
}
//��ռ�¼
void SpeechManager::ClearRecord()
{
	cout << "ȷ����գ�" << endl;
	cout << "1��ȷ��" << endl;
	cout << "2������" << endl;
	
	int choice = 0;
	cin >> choice;
	while (choice != 1 && choice != 2)
	{
		cout << "�����������������룺";
		cin >> choice;
	}

	if (1 == choice)
	{
		//��ģʽ ios::trunc �������ɾ���ļ������´���
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();

		//���¼�¼����
		this->InitSpeech();
		this->CreateSpeaker();
		this->LoadRecord();

		cout << "��ճɹ���" << endl;
	}

	system("pause");
	system("cls");
}
//����
SpeechManager::~SpeechManager()
{
	//��ʵ�ּ���
}

//�˵�
void SpeechManager::Menu()
{
	cout << "###########################################" << endl;
	cout << "#######                             #######" << endl;
	cout << "#########     ��ӭ�μ��ݽ�����    #########" << endl;
	cout << "##########    1.��ʼ�ݽ�����     ##########" << endl;	
	cout << "##########    2.�鿴�����¼     ##########" << endl;
	cout << "##########    3.��ձ�����¼     ##########" << endl;
	cout << "#########     0.�˳���������      #########" << endl;
	cout << "#######                             #######" << endl;
	cout << "###########################################" << endl;
	cout << endl;
}


//�˳�ϵͳ
void SpeechManager::ExitSystem()
{
	cout << "��ӭ�´�ʹ�ã�" << endl;
	system("pause");
	exit(0);
}
