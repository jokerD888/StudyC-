#include"speechManager.h"


//��������
//
//* ѧУ����һ���ݽ�����������12���˲μӡ� ���������� ����һ��Ϊ��̭�����ڶ���Ϊ������
//* ������ʽ�� ���������ÿ��6���� ��ѡ��ÿ��Ҫ������飬���б���
//* ÿ��ѡ�ֶ��ж�Ӧ�� ��� ���� 10001 ~10012
//* ��һ�ַ�Ϊ����С�飬ÿ��6���ˡ� ���尴��ѡ�ֱ�Ž��г�ǩ ��˳���ݽ���
//* ��С���ݽ������̭����������������ѡ�֣� ǰ�������� ��������һ�ֵı�����
//* �ڶ���Ϊ������ ǰ����ʤ�� 
//*ÿ�ֱ���������Ҫ ��ʾ����ѡ�ֵ���Ϣ 
int main()
{
	srand((unsigned int)time(NULL));
	SpeechManager sm;

	int choice = 0;//�����û�������ѡ��

	while (true)
	{
		sm.Menu();

		cout << "����������ѡ�� " << endl;
		cin >> choice; // �����û���ѡ��

		switch (choice)
		{
		case 1:  //��ʼ����
			sm.StartSpeech();
			break;
		case 2:  //�鿴��¼
			sm.ShowRecord();
			break;
		case 3:  //��ռ�¼
			sm.ClearRecord();
			break;
		case 0:  //�˳�ϵͳ
			sm.ExitSystem();
			break;
		default:
			system("cls"); //����
			break;
		}
	}

	return 0;
}