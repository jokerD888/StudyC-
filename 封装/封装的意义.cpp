#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;


//设计一个圆类，求圆的周长
const double PI = 3.14;
//class代表设计一个类，类后面紧跟着的就是类的名称
class Circle
{
	//访问权限
	//公共权限	成员 类内可以访问，类外可以访问
public:
	//保护权限	成员 类内可以访问，类外不可以访问	儿子可以访问父亲中的保护内容
//protected:
	//私有权限	成员 类内可以访问，类外不可以访问	儿子不可以访问父亲中的私有内容
//private:

	//属性		类中的属性和行为 统称为 成员
	//			属性- 成员属性，成员变量		行为-成员函数，成员方法
	//半径
	int m_r;

	//行为
	//获取圆的周长
	double calculateZC()
	{
		return 2 * PI * m_r;
	}

	//给半径赋值
	void setR(int r)
	{
		m_r = r;
	}
};

class Person
{
	//公共权限	
public:
	string m_Name;	//姓名
	//保护权限	
protected:
	string m_Car;	//汽车
	//私有权限	
private:
	int m_Password;		//银行卡密码

public:
	void func()
	{
		m_Name = "张三";
		m_Car = "拖拉机";		//类内都可以访问
		m_Password = 123456;
	}
};
int main(void)
{
	//通过圆类 创建具体的圆（对象）
	Circle c1;
	//给圆对象的属性进行赋值
	//c1.m_r = 10;
	//也可以通过行为给属性复制
	//c1.setR(10);
	//cout << "圆的周长为：" << c1.calculateZC() << endl;


	Person p1;
	p1.m_Name = "李四";	//类外只能访问public
	//p1.m_Car = "劳斯莱斯";		//不可访问
	//p1.m_Password = 11111;	//不可访问
	p1.func();
	return 0;
}
