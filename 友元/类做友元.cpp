#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

class Building;//声明
class goodGay
{
public:

	goodGay();
	void visit();

private:
	Building* building;
};


class Building
{
	//告诉编译器 goodGay类是Building类的好朋友，可以访问到Building类中私有内容
	friend class goodGay;

public:
	Building();

public:
	string m_SittingRoom; //客厅
private:
	string m_BedRoom;//卧室
};

//类外实现函数，函数前要加类名，告诉编译器这是类中的函数
Building::Building()
{
	this->m_SittingRoom = "客厅";
	this->m_BedRoom = "卧室";
}

goodGay::goodGay()
{
	//goodGay构造函数，又new了一个Building类，又通过Building类构造函数初始化了成员变量
	building = new Building;
}

void goodGay::visit()
{
	cout << "好基友正在访问" << building->m_SittingRoom << endl;
	cout << "好基友正在访问" << building->m_BedRoom << endl;
}

void test01()
{
	goodGay gg;
	gg.visit();

}

int main() 
{

	test01();
	return 0;
}
