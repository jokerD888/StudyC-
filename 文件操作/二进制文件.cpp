#define _CRT_SECURE_NO_WARNINGS 1

//以二进制的方式对文件进行读写操作
//打开方式要指定为 ios::binary 
//写文件
//二进制方式写文件主要利用流对象调用成员函数write
//函数原型 ：ostream& write(const char* buffer, int len); 
//参数解释：字符指针buffer指向内存中一段存储空间。len是读写的字节数
//读文件
//二进制方式写文件主要利用流对象调用成员函数write
//函数原型 ：ostream& write(const char* buffer, int len); 
//参数解释：字符指针buffer指向内存中一段存储空间。len是读写的字节数
#include<iostream>	
using namespace std;
#include<fstream>		


class Person
{
public:
	char m_Name[64];
	int m_Age;
};

//写文件
void test01()
{
	//1、包含头文件

	//2、创建输出流对象
	ofstream ofs("person.txt", ios::out | ios::binary);		//记得二进制文件要值定添加ios::binary 

	//3、打开文件
	//ofs.open("person.txt", ios::out | ios::binary);

	Person p1 = { "张三  "  , 18 };

	//4、写文件(类型要转化为const char*）
	ofs.write((const char*)&p1, sizeof(p1));

	//5、关闭文件
	ofs.close();
}


//读文件
void test02()
{
	ifstream ifs("person.txt", ios::in | ios::binary);
	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
	}

	Person p2;
	ifs.read((char*)&p2, sizeof(p2));

	cout << "姓名： " << p2.m_Name << " 年龄： " << p2.m_Age << endl;
}

int main() {

	test01();
	test02();
	return 0;
}
