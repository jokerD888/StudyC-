#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;


//浅拷贝：简单的赋值拷贝操作
//深拷贝：在堆区重新申请空间，进行拷贝操作

//初始化列表  
class Person 
{
public:
	
	Person() 
	{
		cout << "无参构造函数!" << endl;
	}
	//传统方式初始化
	/*Person(int age, int height) 
	{
		cout << "有参构造函数!" << endl;
		m_age = age;
		m_height = new int(height);
	}*/

	//初始化列表方式初始化
	Person(int age, int height) :m_age(age), m_height(new int(height)) {};

	Person(const Person& p) //如果自己不写拷贝构造函数，系统自己的浅拷贝构造函数会导致同一内存空间多次释放，报错
	{
		cout << "拷贝构造函数!" << endl;
		//如果不利用深拷贝在堆区创建新内存，会导致浅拷贝带来的重复释放堆区问题
		m_age = p.m_age;
		m_height = new int(*p.m_height);	//编译器默认实现的代码：m_height=p.m_height;

	}

	~Person() 
	{
		//析构代码，将堆开辟的数据做释放操作	
		if (m_height != NULL)
		{
			delete m_height;
			m_height = NULL;
		}
		cout << "析构函数!" << endl;

	}
public:
	int m_age;
	int* m_height;
};

void test01()
{
	Person p1(18, 180);
	Person p2(p1);

	cout << "p1的年龄： " << p1.m_age << " 身高： " << *p1.m_height << endl;
	cout << "p2的年龄： " << p2.m_age << " 身高： " << *p2.m_height << endl;
}
//总结：如果属性有在堆区开辟的，一定要自己提供拷贝构造函数，防止浅拷贝带来的问题
int main() {

	test01();

	return 0;
}