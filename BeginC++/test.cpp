#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

int main() {

	cout << "Hello world" << endl;
	cout << "\141" << endl;	//8����ת���ַ���d��Χ0~7
	cout << "\x61" << endl;//16����ת���ַ���h��Χ0~9��a~f��A~F

	//�ַ���
	char str1[] = "abcd";	//c���
	string str2 = "abcd";	//c++���	Ҫ��ͷ�ļ�#include<string>

	cout << str1 << endl;
	cout << str2 << endl;


	//��������bool
	//���ã������������ʹ������ٵ�ֵ 
	//bool����ֻ������ֵ��
	//true  -- - �棨������1��
	//false -- - �٣�������0��

	bool flag = true;
	cout << flag << endl;	//1

	flag = false;
	cout << flag << endl;	//0


	////���ݵ�����
	////���ã����ڴӼ��̻�ȡ����
	////�ؼ���:cin
	////�﷨��cin >> ���� 
	////1.����
	//int a = 0;
	//cout << "���������ͱ�����" << endl;
	//cin >> a;
	//cout << a << endl;
	////2.������
	//double d = 0;
	//cout << "�����븡���ͱ�����" << endl;
	//cin >> d;
	//cout << d << endl;
	////3.�ַ���
	//char c = 0;
	//cout << "�������ַ��ͱ���:" << endl;
	//cin >> c;
	//cout << c << endl;
	////4.�ַ�����
	//string str;
	//cout << "�������ַ����ͱ�����" << endl;
	//cin >> str;
	//cout << str << endl;
	////5.��������(�������ͱ��������ͣ�ֻ����������ת������������0.1���ڱ���ʱ�ᱻ�ضϱ��0��
	//bool flag1 = false;
	//cout << "�����벼���ͱ�����" << endl;
	//cin >> flag;
	//cout << flag << endl;
	

	
	//���飬��c����ʹ�÷���һ��
	int arr1[10] = { 1,2,3,4,5,6,7,8,9,10 };

	cout << "����������ռ�ڴ�ռ�Ϊ�� " << sizeof(arr1) << endl;
	cout << "ÿ��Ԫ����ռ�ڴ�ռ�Ϊ�� " << sizeof(arr1[0]) << endl;
	cout << "�����Ԫ�ظ���Ϊ�� " << sizeof(arr1) / sizeof(arr1[0]) << endl;

	//����ͨ����������ȡ�������׵�ַ
	cout << "�����׵�ַΪ�� " << (int)arr1 << endl;	//��ת��Ϊint�Ļ�Ĭ�����16����
	cout << "�����е�һ��Ԫ�ص�ַΪ�� " << (int)&arr1[0] << endl;
	cout << "�����еڶ���Ԫ�ص�ַΪ�� " << (int)&arr1[1] << endl;

	int arr2[2][3] =
	{
		{1,2,3},
		{4,5,6}
	};
	//��ַ
	cout << "��ά�����׵�ַ��" << arr2 << endl;
	cout << "��ά�����һ�е�ַ��" << arr2[0] << endl;
	cout << "��ά����ڶ��е�ַ��" << arr2[1] << endl;

	cout << "��ά�����һ��Ԫ�ص�ַ��" << &arr2[0][0] << endl;
	cout << "��ά����ڶ���Ԫ�ص�ַ��" << &arr2[0][1] << endl;


	//��ά�ַ������c���Զ���һ�ֱ�ʾ	
	//�ڴ�window�����£�����GBK���룬һ�����ĺ���վռ��2���ֽ�,�ڴ��еĳ���������5,��ͬ�����¿��ܸ��в�ͬ
	char name1[3][5]= { "����","����","����" };
	string name2[3] = { "����","����","����" };
	for (int i = 0; i < 3; i++)
	{
		cout << name1[i] << endl;
		cout << name2[i] << endl;

	}


	return 0;
}


