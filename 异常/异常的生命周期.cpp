#define _CRT_SECURE_NO_WARNINGS 1

//�쳣�������������
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
//������������
void func1() {
	Maker m;	//��һ���������쳣����ǰ���ͷ�
	throw m;	//�ڶ��������ǵ�һ�����󿽱�������

}

void test01() {
	try {
		func1();
	}
	catch(Maker m1){	//�����������ǵڶ������󿽱�������
		cout << "����һ��Maker���͵��쳣" << endl;
		//�ڶ����͵�����������catch����ʱ�ͷ�
	}
}
//���
//Maker�Ĺ���
//Maker�Ŀ�������
//Maker�Ŀ�������
//~Maker������
//����һ��Maker���͵��쳣
//~Maker������
//~Maker������


//������������
void func2() {
	//��һ������
	throw Maker();
	//����������Ȼͨ��˵��������Ľ����ڵ�ǰ�У���ͨ��������ɿ�����������������ͷŲ����ڵ�ǰ�У�
	//��ʱ����������throw���أ�������ʵ�����������ˣ��������
}
void test02() {
	try {
		func2();
	}
	//�ڶ�������
	catch (Maker m1) {	
		cout << "����һ��Maker���͵��쳣" << endl;
		//��1���͵�2��������catch����ʱ�ͷ���
	}
}
//���
//Maker�Ĺ���
//Maker�Ŀ�������
//����һ��Maker���͵��쳣
//~Maker������
//~Maker������


//���ϲ����ȽϺķ��ڴ棬������һ����ֻ����һ������
void func3() {
	throw Maker();//��������
}
void test03() {
	try {
		func3();
	}
	catch (Maker& m1) {	
		//���ý��գ�������ָ����ܣ���崵�����Ϊ�������������ջ�е���������ȡ��ַ����
		//������������Զ����е���������ȡ��ַ����,��test04()
		cout << "����һ��Maker���͵��쳣" << endl;
		//�����ͷ�
	}
}
void func4() {
	throw new Maker();//��������
}
void test04() {
	try {
		func4();
	}
	catch (Maker* m1) {
		cout << "����һ��Maker���͵��쳣" << endl;
		//�����ͷ�
		delete m1;
	}
}


//�������������ʺ�������������������׳�����
int main(void)
{
	test04();
	return 0;
}
