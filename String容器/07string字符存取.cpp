#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
using namespace std;
#include<string>
//
//string�е����ַ���ȡ��ʽ������(�ɲ���ޣ�
//char& operator[](int n);     //ͨ��[]��ʽȡ�ַ���������һ��ʹ��
//char& at(int n);                    //ͨ��at������ȡ�ַ�

//str.size()���������ַ�����
void test01()
{
	string str = "hello world";
	for (int i = 0; i < str.size(); i++)
	{
		cout << str[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < str.size(); i++)
	{
		cout << str.at(i) << " ";
	}
	cout << endl;


	//�ַ��޸�
	str[0] = 'x';
	str.at(1) = 'x';
	cout << str << endl;

}

int main() 
{

	test01();
	return 0;
}