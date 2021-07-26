#define _CRT_SECURE_NO_WARNINGS 1


//先来了解STL最常用的容器Vector,可以理解为数组

//容器：vector
//算法：for_each
//迭代器：vector<int>::iterator

#include<iostream>
using namespace std;
#include<vector>//包含vector容器
#include<algorithm>//包含算法


//----------vector存放内置数据类型-------------------
void MyPrint(int val)
{
	cout << val << endl;
}
void test01()
{
	//创建vector容器对象，并且通过模板参数指定容器中存放的数据类型
	vector<int> v;
	//向容器存放数据
	v.push_back(1);
	v.push_back(3);
	v.push_back(5);
	v.push_back(7);
	v.push_back(9);
	v.push_back(11);

	//每一个容器都有自己的迭代器，迭代器是用来遍历容器中的元素
	//v.begin()返回迭代器，这个迭代器指向容器中第一个数据
	//v.end()返回迭代器，这个迭代器指向容器元素的最后一个元素的下一个位置
	//vector<int>::iterator 拿到vector<int>这种容器的迭代器类型

	//遍历
	//第一种方法
	vector<int>::iterator pBegin = v.begin();//定义两个迭代器类型变量，记录头和尾的位置
	vector<int>::iterator pEnd = v.end();
	while (pBegin != pEnd)
	{
		cout << *pBegin << endl;//迭代器先理解为指针，解引用找到本体数据
		pBegin++;//往后走
	}

	//第二种遍历方式(常用）
	for (vector<int>::iterator it = v.begin(); it < v.end(); it++)
	{
		cout << *it << endl;
	}

	//第三种,使用STL提供的标准遍历算法，头文件algorithm
	for_each(v.begin(), v.end(), MyPrint);//这里的MyPrint需要自己实现

}
//-----------------Vector存放自定义数据类型--------------------
//自定义数据类型
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
//存放对象
void test02()
{
	vector<Person> v;

	//创建数据
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


//放对象指针
void test03() {

	vector<Person*> v;

	//创建数据
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

//---------------------Vector容器嵌套容器-------------
//相当于二维数组

//容器嵌套容器
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

	//将容器元素插入到vector v中
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
	//test01();//内置数据类型测试

	//test02();//自定义数据类型测试
	//test03();

	test04();//容器嵌套容器
	return 0;
}
