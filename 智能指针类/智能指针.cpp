#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//����ָ���ǹ�����һ����Ķ�����ͷ�
class Maker {
public:
	Maker() {
		cout << "�޲ι���" << endl;
	}
	~Maker() {
		cout << "����" << endl;
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
	Maker* p = new Maker;//��Ȼ���Ǻ���û���ֶ�delete p,������ָ�����Զ������ǵ�����
	smartPoint sm(p);	
	//����ջ������test01�����󣬻����smartPoint����������������delete��Maker�Ķ���
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

