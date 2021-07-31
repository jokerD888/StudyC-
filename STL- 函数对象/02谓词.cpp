#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

//����
//����bool���͵ķº�����Ϊν��
//���operator()����һ����������ô����һԪν��
//���operator()����������������ô������Ԫν��


#include <vector>
#include <algorithm>

//C++�нṹ��������ͬ��
//��֮ͬ����
//1���ṹ����Ĭ������³�Ա�ǹ����ģ�public��������Ĭ������³�Ա��˽�е�(private)��
//2��C++�ṹ���ڲ���Ա��������Ա����Ĭ�ϵķ��ʼ�����public����c++����ڲ���Ա��������Ա������Ĭ�Ϸ��ʼ�����private��
//3��C++�ṹ��ļ̳�Ĭ����public����c++��ļ̳�Ĭ����private��
//4����Ҫ����public��ɹ��еĲ��ܱ����ʣ����ṹ������ǹ��еĿ�ֱ�ӷ��ʡ�
//��֮ͬ����
//�ṹ���п��԰���������Ҳ���Զ���public��private��protected���ݳ�Ա��
// �����˽ṹ��֮�󣬿����ýṹ�������������󡣵�C�еĽṹ�岻�����к�����
//Ҳ����˵��C++���У��ṹ���п����г�Ա�����������г�Ա���������Դӱ����̳У�Ҳ���Ա������̳У��������麯����

//һԪν��
class GreaterFive
{
public:
	bool operator()(int val)
	{
		return val > 5;
	}
};
//��
//struct GreaterFive//C++�еĽṹ���൱��һ��������� 
//{
//	bool operator()(int val)
//	{
//		return val > 5;
//	}
//};

void test01() 
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	vector<int>::iterator it = find_if(v.begin(), v.end(), GreaterFive());//find_if����������
	if (it == v.end())
	{
		cout << "û�ҵ�!" << endl;
	}
	else 
	{
		cout << "�ҵ�:" << *it << endl;
	}

}


//��Ԫν��

class MyCompare
{
public:
	bool operator()(int num1, int num2)
	{
		return num1 > num2;
	}
};

void test02()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(40);
	v.push_back(20);
	v.push_back(30);
	v.push_back(50);

	//Ĭ�ϴ�С����
	sort(v.begin(), v.end());
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	cout << "----------------------------" << endl;

	//ʹ�ú�������ı��㷨���ԣ�����Ӵ�С
	sort(v.begin(), v.end(), MyCompare());
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

int main() 
{
	test01();
	test02();
	return 0;
}
