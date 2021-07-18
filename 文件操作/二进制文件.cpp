#define _CRT_SECURE_NO_WARNINGS 1

//�Զ����Ƶķ�ʽ���ļ����ж�д����
//�򿪷�ʽҪָ��Ϊ ios::binary 
//д�ļ�
//�����Ʒ�ʽд�ļ���Ҫ������������ó�Ա����write
//����ԭ�� ��ostream& write(const char* buffer, int len); 
//�������ͣ��ַ�ָ��bufferָ���ڴ���һ�δ洢�ռ䡣len�Ƕ�д���ֽ���
//���ļ�
//�����Ʒ�ʽд�ļ���Ҫ������������ó�Ա����write
//����ԭ�� ��ostream& write(const char* buffer, int len); 
//�������ͣ��ַ�ָ��bufferָ���ڴ���һ�δ洢�ռ䡣len�Ƕ�д���ֽ���
#include<iostream>	
using namespace std;
#include<fstream>		


class Person
{
public:
	char m_Name[64];
	int m_Age;
};

//д�ļ�
void test01()
{
	//1������ͷ�ļ�

	//2���������������
	ofstream ofs("person.txt", ios::out | ios::binary);		//�ǵö������ļ�Ҫֵ�����ios::binary 

	//3�����ļ�
	//ofs.open("person.txt", ios::out | ios::binary);

	Person p1 = { "����  "  , 18 };

	//4��д�ļ�(����Ҫת��Ϊconst char*��
	ofs.write((const char*)&p1, sizeof(p1));

	//5���ر��ļ�
	ofs.close();
}


//���ļ�
void test02()
{
	ifstream ifs("person.txt", ios::in | ios::binary);
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
	}

	Person p2;
	ifs.read((char*)&p2, sizeof(p2));

	cout << "������ " << p2.m_Name << " ���䣺 " << p2.m_Age << endl;
}

int main() {

	test01();
	test02();
	return 0;
}
