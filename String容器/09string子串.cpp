#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;
#include<string>

//����������
//���ַ����л�ȡ��Ҫ���Ӵ�

//����ԭ�ͣ�
//string substr(int pos = 0, int n = npos) const;    //������pos��ʼ��n���ַ���ɵ��ַ���


void test01()
{

	string str = "abcdefg";
	string subStr = str.substr(1, 3);
	cout << "subStr = " << subStr << endl;

	//�����Ȼ�򵥣�ȴ�Ƚ�ͨ�ã����磺��ȡ������û����Զ���ȡ@֮ǰ���ִ�
	string email = "hello@sina.com";
	int pos = email.find("@");
	string username = email.substr(0, pos);
	cout << "username: " << username << endl;

}

int main()
{

	test01();
	return 0;
}
