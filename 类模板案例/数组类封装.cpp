#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;
#include"MyArray.hpp"

//��������:  ʵ��һ��ͨ�õ������࣬Ҫ�����£�
// 1.���Զ��������������Լ��Զ����������͵����ݽ��д洢
// 2.�������е����ݴ洢������
// 3.���캯���п��Դ������������
// 4.�ṩ��Ӧ�Ŀ������캯���Լ�operator = ��ֹǳ��������
// 5.�ṩβ�巨��βɾ���������е����ݽ������Ӻ�ɾ��
// 6.����ͨ���±�ķ�ʽ���������е�Ԫ��
// 7.���Ի�ȡ�����е�ǰԪ�ظ��������������


class Person
{
public:
	Person() {}//�����ṩ���вι��죬ϵͳ�Ͳ����ṩĬ�Ϲ����ˣ������в���
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}


	string m_Name;
	int m_Age;
};

void test01()
{
	MyArray<int> arr1(5);
	MyArray<int> arr2(arr1);
	MyArray<int> arr3(20);
	arr3 = arr1;

}
void PrintArray( MyArray<int>& arr)
{
	for (int i = 0; i < arr.GetSize(); i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
//��������int����
void test02()
{
	MyArray<int> arr1(5);
	for (int i = 0; i < 5; i++)
	{
		arr1.PushBack(i);
	}
	PrintArray(arr1);
	cout << "arr1����Ϊ:" << arr1.GetCapacity() << endl;

	MyArray<int> arr2(arr1);
	arr2.PopBack();
	PrintArray(arr2);

	MyArray<int> arr3(10);
	arr3 = arr2;
	arr3.PushBack(6);
	PrintArray(arr3);

}

//�Զ����������Ͳ���
void PrintPersonArray(MyArray<Person>& arr)
{
	for (int i = 0; i < arr.GetSize(); i++)
	{
		cout << "������" << arr[i].m_Name << "\t���䣺" << arr[i].m_Age << endl;
	}
}
void test03()
{
	MyArray<Person> arr(10);

	Person p1("����", 29);
	Person p2("����", 19);
	Person p3("����", 20);
	Person p4("����", 22);
	Person p5("С��", 17);

	//��������
	arr.PushBack(p1);
	arr.PushBack(p2);
	arr.PushBack(p3);
	arr.PushBack(p4);
	arr.PushBack(p5);

	PrintPersonArray(arr);//��ӡ

	cout << "Peron�����������" << arr.GetCapacity() << endl;





}
int main(void)
{
	//test01();
	//test02();
	test03();
	return 0;
}

