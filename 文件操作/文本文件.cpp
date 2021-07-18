#define _CRT_SECURE_NO_WARNINGS 1

//��������ʱ���������ݶ�������ʱ���ݣ�����һ�����н������ᱻ�ͷ�
//ͨ���ļ����Խ����ݳ־û�
//C++�ж��ļ�������Ҫ����ͷ�ļ� <fstream>
//�ļ����ͷ�Ϊ���֣�
//1. �ı��ļ� -�ļ����ı���ASCII����ʽ�洢�ڼ�����У����Զ�����
//2. �������ļ�-�ļ����ı��Ķ�������ʽ�洢�ڼ�����У��û�һ�㲻��ֱ�Ӷ�������

//�����ļ���������:
//1. ofstream��д����
//2. ifstream�� ������
//3. fstream �� ��д����

/*д�ļ��������£�
1. ����ͷ�ļ�
#include <fstream>
2. ����������
ofstream ofs;
3. ���ļ�
ofs.open("�ļ�·��", �򿪷�ʽ);
4. д����
ofs << "д�������";
5. �ر��ļ�
ofs.close();*/

//�ļ��򿪷�ʽ��
//| ios::in | Ϊ���ļ������ļ�         |
//| ios::out | Ϊд�ļ������ļ�         |
//| ios::ate | ��ʼλ�ã��ļ�β           |
//| ios::app | ׷�ӷ�ʽд�ļ�             |
//| ios::trunc | ����ļ�������ɾ�����ٴ��� |
//| ios::binary | �����Ʒ�ʽ |
//ע�⣺ �ļ��򿪷�ʽ�������ʹ�ã����� | ������
//���磺 �ö����Ʒ�ʽд�ļ� ios::binary | ios::out

#include<iostream>	
using namespace std;
#include<fstream>		//1.����ͷ�ļ�
 

//д�ļ�
void test01()
{
	//ofstream ofs;		//2.����������
	//ofs.open("test.txt", ios::out);   //3.�򿪷�ʽ        //�����д·������Ĭ�ϵ�ǰ��������·��
	//��2����3���ϲ���дΪ
	ofstream ofs("test.txt", ios::out);		//�൱��д�����Ĺ��캯��
	
	ofs << "����: ����" << endl;    //4. д����
	ofs << "�Ա�: ��" << endl;
	ofs << "����: 20" << endl;

	ofs.close();	//5. �ر��ļ�
}


//���ļ�
void test02()
{
	ifstream ifs;		//2.����������
	ifs.open("test.txt", ios::in);		//3.�򿪷�ʽ

	if (!ifs.is_open())		//�ж��Ƿ�ɹ����ļ�
	{
		cout << "�ļ���ʧ��" << endl;
		return;
	}

	//��һ�ַ�ʽ							//4. ������
	//char buf[1024] = { 0 };
	//while (ifs >> buf)		//ֱ�Ӷ�ȡ�������ո���н�����ifs>>bufֻ�ж����ļ�ĩβ�Ż᷵��false
	//{
	//	cout << buf;
	//}

	//�ڶ���
	//char buf[1024] = { 0 };
	//while (ifs.getline(buf,sizeof(buf)))		//�ַ����飬���ж�ȡ���ɶ�ȡ�ո�
	//{
	//	cout << buf << endl;
	//}

	//������
	//string buf;
	//while (getline(ifs, buf))			//�ַ�����ȡ�����ж�ȡ���ɶ�ȡ�ո�
	//{
	//	cout << buf << endl;
	//}

	char c;
	while ((c = ifs.get()) != EOF)		//�����ַ���ȡ���ɶ�ȡ�ո�ͻ��У���Ч�ʵ���
	{
		cout << c;
	}

	ifs.close();			//5. �ر��ļ�
}
int main() {

	test01();
	test02();
	return 0;
}

