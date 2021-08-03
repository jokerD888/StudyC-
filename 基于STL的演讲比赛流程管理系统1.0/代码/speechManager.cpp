#include"speechManager.h"
//����
SpeechManager::SpeechManager()
{
	this->InitSpeech();

	this->CreateSpeaker();

	this->LoadRecord();
}

//����
SpeechManager::~SpeechManager()
{
	//��ʵ�ּ���
}

//�˵�
void SpeechManager::Menu()
{
	cout << "********************************************" << endl;
	cout << "*************  ��ӭ�μ��ݽ����� ************" << endl;
	cout << "*************  1.��ʼ�ݽ�����  *************" << endl;
	cout << "*************  2.�鿴�����¼  *************" << endl;
	cout << "*************  3.��ձ�����¼  *************" << endl;
	cout << "*************  0.�˳���������  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}


//�˳�ϵͳ
void SpeechManager::ExitSystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}


//��ʼ������������
void SpeechManager::InitSpeech()
{
	//������֤Ϊ��
	this->v1.clear();
	this->v2.clear();
	this->vVictory.clear();
	this->m_Speaker.clear();

	//��ʼ����������
	this->m_Index = 1;

	this->m_Record.clear();
}

//��ʼ������12��ѡ��
void SpeechManager::CreateSpeaker()
{
	string nameSeed = "ABCDEFGHIJKL";
	for (int i = 0; i < nameSeed.size(); i++)
	{
		string name = "ѡ��";
		name += nameSeed[i];

		//��������ѡ��
		Speaker sp;
		sp.m_Name = name;
		for (int j = 0; j < 2; j++)
		{
			sp.m_Score[j] = 0;
		}

		//12��ѡ�ֱ��
		this->v1.push_back(i + 10001);

		//ѡ�ֱ�� �Լ���Ӧ��ѡ�� ��ŵ�map������
		this->m_Speaker.insert(make_pair(i + 10001, sp));
	}
}

//��ʼ���� - �������̿���
void SpeechManager::StartSpeech()
{
	//��һ�ֱ���
	
	//1����ǩ
	this->SpeechDraw();

	//2������
	this->SpeechContest();

	//3����ʾ�������
	this->ShowScore();

	//�ڶ��ֱ���
	this->m_Index++;

	//1����ǩ
	this->SpeechDraw();

	//2������
	this->SpeechContest();

	//3����ʾ���ս��
	this->ShowScore();

	//4���������
	this->SaveRecord();

	this->InitSpeech();
	this->CreateSpeaker();
	this->LoadRecord();

	cout << "���������ϣ�" << endl;
	system("pause");
	system("cls");
}


//��ǩ
void SpeechManager::SpeechDraw()
{
	cout << "�� << " << this->m_Index << " >> �ֱ���ѡ�����ڳ�ǩ" << endl;
	cout << "---------------------" << endl;
	cout << "��ǩ���ݽ�˳�����£�" << endl;
	if (this->m_Index == 1)
	{
		random_shuffle(v1.begin(), v1.end()); 
		for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	else
	{
		random_shuffle(v2.begin(), v2.end());
		for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	cout << "---------------------" << endl;

	system("pause");
	cout << endl;
}


//����
void SpeechManager::SpeechContest()
{
	cout << "----------------------��" << this->m_Index << "�ֱ�����ʼ-----------------------" << endl;
	//��ʱ���������С��ɼ�
	multimap<double, int, greater<double>> GroupScore;
	int num = 0;//��¼��Ա������6��һ��

	vector<int> vSrc;//����ѡ������
	if (this->m_Index == 1)
	{
		vSrc = this->v1;
	}
	else
	{
		vSrc = this->v2;
	}

	//��������ѡ�ֽ��б���
	for (vector<int>::iterator it = vSrc.begin(); it != vSrc.end(); it++)
	{
		num++;
		//��ί���
		deque<double> d;
		//10����ί
		for (int i = 0; i < 10;i++)
		{
			double score = (rand() % 401 + 600) / 10.f;//60.0~100
			//cout << score << " ";//����
			d.push_back(score);
		}
		//cout << endl;

		//����
		sort(d.begin(), d.end(), greater<double>());
		d.pop_back();//ȥ��ͷ�
		d.pop_front();//ȥ��߷�

		double sum = accumulate(d.begin(), d.end(), 0.0f);
		double avg = sum / (double)d.size();
		//��ӡƽ���ֲ���
		//cout << "��ţ�" << *it << "\t������" << this->m_Speaker[*it].m_Name << "\t��ȡƽ���֣�" << avg << endl;

		//��ƽ���ַ��뵽map����
		this->m_Speaker[*it].m_Score[this->m_Index - 1] = avg;

		//��������ݷŵ���ʱС��������
		GroupScore.insert(make_pair(avg, *it));//key�ǵ÷֣�value��ѡ�ֱ��
		//ÿ6��ȡ��ǰ3��
		if (num % 6 == 0)
		{
			cout << "��" << num / 6 << "С��������Σ�" << endl;
			for (multimap<double, int, greater<double>>::iterator it = GroupScore.begin(); it != GroupScore.end(); it++)
			{
				cout << "��ţ�" << it->second << "\t������" << this->m_Speaker[it->second].m_Name
					<< "\t�ɼ���" << this->m_Speaker[it->second].m_Score[this->m_Index - 1] << endl;
			}
			cout << endl;
			//ȡǰ������
			int count = 0;
			for (multimap<double, int, greater<double>>::iterator it = GroupScore.begin(); it != GroupScore.end() && count<3; it++)
			{
				count++;
				if (this->m_Index == 1)
				{
					v2.push_back((*it).second);
				}
				else
				{
					vVictory.push_back((*it).second);
				}
			}
			GroupScore.clear();//С��������գ�����һ��
		}

	}
	cout << "------------------------��" << this->m_Index << "�ֱ������------------------------" << endl;

	system("pause");
}




//��ʾ�������
void SpeechManager::ShowScore()
{
	cout << "-------------------��" << this->m_Index << "�ֽ���ѡ����Ϣ���£�--------------------" << endl;
	vector<int> v;
	if (this->m_Index == 1)
	{
		v = v2;
	}
	else
	{
		v = vVictory;
	}

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "ѡ�ֱ�ţ�" << *it << " ������ " << m_Speaker[*it].m_Name << " �÷֣� " << m_Speaker[*it].m_Score[this->m_Index - 1] << endl;
	}
	cout << endl;

	system("pause");
	system("cls");
	this->Menu();
}

//�����¼
void SpeechManager::SaveRecord()
{
	ofstream ofs;
	ofs.open("speech.csv", ios::out | ios::app); // ������ķ�ʽ���ļ�  -- д�ļ�

	//��ÿ��������д�뵽�ļ���
	for (vector<int>::iterator it = vVictory.begin(); it != vVictory.end(); it++)
	{
		ofs << *it << ","
			<< m_Speaker[*it].m_Score[1] << ",";
	}
	ofs << endl;

	//�ر��ļ�
	ofs.close();

	cout << "��¼�Ѿ�����" << endl;
	//�ļ���Ϊ����
	this->fileIsEmpty = false;
}


void SpeechManager::LoadRecord()
{
	ifstream ifs("speech.csv", ios::in); //���������� ��ȡ�ļ�

	if (!ifs.is_open())
	{
		this->fileIsEmpty = true;
		//cout << "�ļ������ڣ�" << endl;
		ifs.close();
		return;
	}

	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//cout << "�ļ�Ϊ��!" << endl;
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}

	//�ļ���Ϊ��
	this->fileIsEmpty = false;

	ifs.putback(ch); //��ȡ�ĵ����ַ��Ż�ȥ

	string data;
	int index = 0;
	while (ifs >> data)
	{
		//cout << data << endl;
		vector<string>v;

		int pos = -1;
		int start = 0;

		while (true)
		{
			pos = data.find(",", start); //��0��ʼ���� ','
			if (pos == -1)
			{
				break; //�Ҳ���break����
			}
			string tmp = data.substr(start, pos - start); //�ҵ���,���зָ� ����1 ��ʼλ�ã�����2 ��ȡ����
			v.push_back(tmp);
			start = pos + 1;
		}

		this->m_Record.insert(make_pair(index, v));
		index++;
	}

	ifs.close();
}


//��ʾ����÷�
void SpeechManager::ShowRecord()
{
	if (this->fileIsEmpty)
	{
		cout << "�ļ������ڣ�������Ϊ�գ�" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_Record.size(); i++)
		{
			cout << "��" << i + 1 << "�� " <<
				"�ھ���ţ�" << this->m_Record[i][0] << " �÷֣�" << this->m_Record[i][1] << " "
				"�Ǿ���ţ�" << this->m_Record[i][2] << " �÷֣�" << this->m_Record[i][3] << " "
				"������ţ�" << this->m_Record[i][4] << " �÷֣�" << this->m_Record[i][5] << endl;
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

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		//��ģʽ ios::trunc �������ɾ���ļ������´���
		ofstream ofs("speech.csv", ios::trunc);
		ofs.close();

		//��ʼ������
		this->InitSpeech();

		//����ѡ��
		this->CreateSpeaker();

		//��ȡ�����¼
		this->LoadRecord();


		cout << "��ճɹ���" << endl;
	}

	system("pause");
	system("cls");
}

