#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;
#include"MyArray.hpp"

//案例描述:  实现一个通用的数组类，要求如下：
// 1.可以对内置数据类型以及自定义数据类型的数据进行存储
// 2.将数组中的数据存储到堆区
// 3.构造函数中可以传入数组的容量
// 4.提供对应的拷贝构造函数以及operator = 防止浅拷贝问题
// 5.提供尾插法和尾删法对数组中的数据进行增加和删除
// 6.可以通过下标的方式访问数组中的元素
// 7.可以获取数组中当前元素个数和数组的容量


class Person
{
public:
	Person() {}//这里提供了有参构造，系统就不会提供默认构造了，需自行补充
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
//基本类型int测试
void test02()
{
	MyArray<int> arr1(5);
	for (int i = 0; i < 5; i++)
	{
		arr1.PushBack(i);
	}
	PrintArray(arr1);
	cout << "arr1容量为:" << arr1.GetCapacity() << endl;

	MyArray<int> arr2(arr1);
	arr2.PopBack();
	PrintArray(arr2);

	MyArray<int> arr3(10);
	arr3 = arr2;
	arr3.PushBack(6);
	PrintArray(arr3);

}

//自定义数据类型测试
void PrintPersonArray(MyArray<Person>& arr)
{
	for (int i = 0; i < arr.GetSize(); i++)
	{
		cout << "姓名：" << arr[i].m_Name << "\t年龄：" << arr[i].m_Age << endl;
	}
}
void test03()
{
	MyArray<Person> arr(10);

	Person p1("张三", 29);
	Person p2("李四", 19);
	Person p3("王五", 20);
	Person p4("赵六", 22);
	Person p5("小七", 17);

	//插入数组
	arr.PushBack(p1);
	arr.PushBack(p2);
	arr.PushBack(p3);
	arr.PushBack(p4);
	arr.PushBack(p5);

	PrintPersonArray(arr);//打印

	cout << "Peron数组的容量：" << arr.GetCapacity() << endl;





}
int main(void)
{
	//test01();
	//test02();
	test03();
	return 0;
}

