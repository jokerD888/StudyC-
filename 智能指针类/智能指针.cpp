#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//智能指针是管理另一个类的对象的释放
class Maker {
public:
	Maker() {
		cout << "无参构造" << endl;
	}
	~Maker() {
		cout << "析构" << endl;
	}
	void printMaker() {
		cout << "hello" << endl;
	}
	
};
class smartPoint {
public:
	smartPoint(Maker* m) {
		p = m;
	}
	~smartPoint() {
		if (p) {
			delete p;
			p = nullptr;
		}
	}
	Maker* operator->() {
		return this->p; 
	}
	Maker& operator*() {
		return *p;
	}
private:
	Maker* p;
};
void test01() {
	Maker* p = new Maker;//虽然我们后续没有手动delete p,但智能指针类自动帮我们调用了
	smartPoint sm(p);	
	//利用栈区，当test01结束后，会调用smartPoint的析构函数，进而delete了Maker的对象
}

void test02() {
	Maker* p = new Maker;
	smartPoint sm(p);
	sm->printMaker();
	(*sm).printMaker();
}
int main(void)
{
	test02();
	return 0;
}

