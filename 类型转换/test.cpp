#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

// ------------------------静态转换--------------------
//1.基础类型转换
void test01() {
	char a = 'a';
	//static_cast<要转的类型>(将谁转换）
	double d = static_cast<double>(a); 
	double d1 = (double)a;

}


//2.有层次关系类的指针或引用转换
class Fat {

};
class Son :public Fat {

};
class Other {

};

void test02() {
	Fat* f = nullptr;
	Son* s = nullptr;
	//向下转换，不安全
	Son* s1=static_cast<Son*>(f);

	//向上转换，安全
	Fat* f1 = static_cast<Fat*>(s);

	//Other* o = static_cast<Other*>(s);//没有继承关系，无法转换
}

//引用转换
void test03() {
	Fat f;
	Son s;
	Fat& ref_f = f;
	Son& ref_s = s;
	//向上，安全
	Fat& f1=static_cast<Fat&>(ref_s);
	//向下，不安全
	Son& s1=static_cast<Son&>(ref_f);

}

//----------------------动态转换dynamic_cast---------------------
//主要用于类层次间的上行转换和下行转换
//在上行转换时，和static_cast效果是一样的
//不同的是，在下行转换时dynamic_cast具有类型检查的功能，比static_cast安全

void test04() {
	char a = 'a';
	//dynamic_cast<double>(a);//基础类型不能使用动态转换
	Fat* f = nullptr;
	Son* s = nullptr;
	//向上，安全
	Fat* f1 = dynamic_cast<Fat*>(s);
	//向下,不安全，会检查
	//Son* s1 = dynamic_cast<Son*>(f);//该操作报错，Fat不是多态类型
}

class Fat2 {
public:
	virtual void func() {};
};
class Son2 :public Fat2 {
public:
	virtual void func() {};
};
//发生多态，向下转换，动态转换就可以
void test05() {
	Fat2* f = new Son2;
	Son2* s2 = dynamic_cast<Son2*>(f);
}


//常量转换--------------------const_cast-------------------
//用于修改类型的const属性,只能是指针或引用
//注意：不能直接对非指针和非引用的变量使用const_cast操作符直接移除它的const

void test06() {
	const int* p = nullptr;
	int* newp = const_cast<int*>(p);

	int* pp = nullptr;
	const int* npp = const_cast<const int*>(pp);
}

//重新解释转换------------------reinterpret_cast-------------------
//很不安全，不常用
void test07() {
	int a = 10;
	int* p = reinterpret_cast<int*>(a);

	Fat* f = nullptr;
	Other* o = reinterpret_cast<Other*>(f);
	int* i = reinterpret_cast<int*>(f);

}
int main(void)
{
	test05();
	test01();
	return 0;
}
