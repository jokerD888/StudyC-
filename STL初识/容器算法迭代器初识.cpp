#define _CRT_SECURE_NO_WARNINGS 1


//�����˽�STL��õ�����Vector,�������Ϊ����

//������vector
//�㷨��for_each
//��������vector<int>::iterator

#include<iostream>
using namespace std;
#include<vector>//����vector����
#include<algorithm>//�����㷨


//----------vector���������������-------------------
void MyPrint(int val)
{
	cout << val << endl;
}
void test01()
{
	//����vector�������󣬲���ͨ��ģ�����ָ�������д�ŵ���������
	vector<int> v;
	//�������������
	v.push_back(1);
	v.push_back(3);
	v.push_back(5);
	v.push_back(7);
	v.push_back(9);
	v.push_back(11);

	//ÿһ�����������Լ��ĵ����������������������������е�Ԫ��
	//v.begin()���ص����������������ָ�������е�һ������
	//v.end()���ص����������������ָ������Ԫ�ص����һ��Ԫ�ص���һ��λ��
	//vector<int>::iterator �õ�vector<int>���������ĵ���������

	//����
	//��һ�ַ���
	vector<int>::iterator pBegin = v.begin();//�����������������ͱ�������¼ͷ��β��λ��
	vector<int>::iterator pEnd = v.end();
	while (pBegin != pEnd)
	{
		cout << *pBegin << endl;//�����������Ϊָ�룬�������ҵ���������
		pBegin++;//������
	}

	//�ڶ��ֱ�����ʽ(���ã�
	for (vector<int>::iterator it = v.begin(); it < v.end(); it++)
	{
		cout << *it << endl;
	}

	//������,ʹ��STL�ṩ�ı�׼�����㷨��ͷ�ļ�algorithm
	for_each(v.begin(), v.end(), MyPrint);//�����MyPrint��Ҫ�Լ�ʵ��

}
//-----------------Vector����Զ�����������--------------------
//�Զ�����������
class Person 
{
public:
	Person(string name, int age)
	{
		mName = name;
		mAge = age;
	}
public:
	string mName;
	int mAge;
};
//��Ŷ���
void test02()
{
	vector<Person> v;

	//��������
	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);
	Person p5("eee", 50);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);

	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++) 
	{
		cout << "Name:" << (*it).mName << " Age:" << (*it).mAge << endl;

	}
}


//�Ŷ���ָ��
void test03() {

	vector<Person*> v;

	//��������
	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);
	Person p5("eee", 50);

	v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);
	v.push_back(&p4);
	v.push_back(&p5);

	for (vector<Person*>::iterator it = v.begin(); it != v.end(); it++) 
	{
		cout << "Name:" << (*it)->mName << " Age:" << (*it)->mAge << endl;
	}
}

//---------------------Vector����Ƕ������-------------
//�൱�ڶ�ά����

//����Ƕ������
void test04()
{

	vector< vector<int> >  v;

	vector<int> v1;
	vector<int> v2;
	vector<int> v3;
	vector<int> v4;

	for (int i = 0; i < 4; i++) 
	{
		v1.push_back(i + 1);
		v2.push_back(i + 2);
		v3.push_back(i + 3);
		v4.push_back(i + 4);
	}

	//������Ԫ�ز��뵽vector v��
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	v.push_back(v4);


	for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++) 
	{

		for (vector<int>::iterator vit = (*it).begin(); vit != (*it).end(); vit++) 
		{
			cout << *vit << " ";
		}
		cout << endl;
	}

}
int main(void)
{
	//test01();//�����������Ͳ���

	//test02();//�Զ����������Ͳ���
	//test03();

	test04();//����Ƕ������
	return 0;
}
