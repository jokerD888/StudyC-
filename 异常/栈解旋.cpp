#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;


class Maker {
public:
	Maker() {
		cout << "Maker�Ĺ���" << endl;
	}
	Maker(const Maker& m) {
		cout << "Maker�Ŀ�������" << endl;
	}
	~Maker() {
		cout << "~Maker������" << endl;
	}
};
void func(){
	//���׳��쳣�ĺ����У�����׳��쳣�󣬵�����û�н�������ʱ��ջ������Ķ��󶼻ᱻ�ͷţ���ͽ�ջ������Ϊ�˽�ʡ�ռ�
	Maker m;
	throw m;//���m��Maker������һ�ݣ�
	cout << "func��������" << endl;	

}
void test01() {
	try {
		func();
		cout << "func()�����" << endl;
	}

	catch (Maker) {
		cout << "����һ��Maker���͵��쳣" << endl;
	}
}
//������
//Maker�Ĺ���
//Maker�Ŀ�������
//~Maker������
//����һ��Maker���͵��쳣
//~Maker������
int main(void)
{
	test01();
	return 0;
}