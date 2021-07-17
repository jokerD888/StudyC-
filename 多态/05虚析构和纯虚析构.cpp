#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//多态使用时，如果子类中有属性开辟到堆区，那么父类指针在释放时无法调用到子类的析构代码
// 即父类指针在析构时候不会调用子类中的析构函数，导致子类中如果有堆区属性，会导致内存泄露
//解决方式：将父类中的析构函数改为虚析构或者 纯虚析构，Fu类中有虚析构函数，delete Fu先执行子类的析构函数再执行父类的析构函数。

//虚析构和纯虚析构共性：
//可以解决父类指针释放子类对象
//都需要有具体的函数实现
//虚析构和纯虚析构区别：
// 如果是纯虚析构，该类属于抽象类，无法实例化对象

//虚析构语法：
//virtual ~类名() {}
//纯虚析构语法：
// virtual ~类名() = 0; 
//实现：类名::~类名() {}

class Animal {
public:

	Animal()
	{
		cout << "Animal 构造函数调用！" << endl;
	}

	virtual void Speak() = 0;

	//析构函数加上virtual关键字，变成虚析构函数
	/*virtual ~Animal()
	{
		cout << "Animal虚析构函数调用！" << endl;
	}*/

	//纯虚析构
	virtual ~Animal() = 0;
};

Animal::~Animal()
{
	cout << "Animal 纯虚析构函数调用！" << endl;
}

//和包含普通纯虚函数的类一样，包含了纯虚析构函数的类也是一个抽象类。不能够被实例化。

class Cat : public Animal {
public:
	Cat(string name)
	{
		cout << "Cat构造函数调用！" << endl; 
		m_Name = new string(name);
	}
	virtual void Speak()
	{
		cout << *m_Name << "小猫在说话!" << endl;
	}
	void fun()
	{
		;
	}
	~Cat()
	{
		cout << "Cat析构函数调用!" << endl;
		if (this->m_Name != NULL) {
			delete m_Name;
			m_Name = NULL;
		}
	}

public:
	string* m_Name;
};

void test01()
{


	Animal* animal = new Cat("Tom");
	animal->Speak();
	//在此如果不加虚析构或者 纯虚析构，不会有Son的析构函数调用，则string* m_Name在堆区开辟的内容将不会被释放
	//个人传统做法：
	//delete ((Cat*)animal)->m_Name;
	//或
	//((Cat*)animal)->~Cat();


	//通过父类指针去释放，会导致子类对象可能清理不干净，造成内存泄漏
	//怎么解决？给基类增加一个虚析构函数
	//虚析构函数就是用来解决通过父类指针释放子类对象
	delete animal;
}

int main() {

	test01();
	return 0;
}
//虚析构函数为什么会自动再调用父类的析构函数？
//答1：根据指针或者引用所指对象的实际类型然后调用相应的析构函数，同时对于所有派生类的析构函数，编译器都会插入调用直接基类的析构函数的代码。
//答2:多态的作用。
//对于普通对象 B b; 由于继承的原因，B类中包含父类A，在析构时编译器在调用B类析构函数后会自动调用A的析构函数。
//但在使用指针的情况下，如果不是虚函数：对于A* pb = new B; 在使用delete pb时，pb只是一个向A指针，delete时调用A的析构函数。
//如果析构函数为虚函数，采用后期绑定，在delete pb时，编译器会根据pb所指的实际类型来调用析构函数：pb实际指向B类型，调用B类的析构函数
//（B继承A，调用B的析构函数后自动调用A的析构函数）