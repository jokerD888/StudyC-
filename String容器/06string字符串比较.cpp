#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;
#include<string>

//�ȽϷ�ʽ��
//�ַ����Ƚ��ǰ��ַ���ASCII����жԱ�
//= ����  0
//> ����  1
//< ���� -1
//
//����ԭ�ͣ� 
//int compare(const string & s) const;  //���ַ���s�Ƚ�
//int compare(const char* s) const;      //���ַ���s�Ƚ�

//�ַ����Ƚ�
void test01()
{

	string s1 = "hello";
	string s2 = "aello";

	int ret = s1.compare(s2);

	if (ret == 0) {
		cout << "s1 ���� s2" << endl;
	}
	else if (ret > 0)
	{
		cout << "s1 ���� s2" << endl;
	}
	else
	{
		cout << "s1 С�� s2" << endl;
	}

}

int main() 
{

	test01();
	return 0;
}
