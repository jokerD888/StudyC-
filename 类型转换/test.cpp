#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

// ------------------------��̬ת��--------------------
//1.��������ת��
void test01() {
	char a = 'a';
	//static_cast<Ҫת������>(��˭ת����
	double d = static_cast<double>(a); 
	double d1 = (double)a;

}


//2.�в�ι�ϵ���ָ�������ת��
class Fat {

};
class Son :public Fat {

};
class Other {

};

void test02() {
	Fat* f = nullptr;
	Son* s = nullptr;
	//����ת��������ȫ
	Son* s1=static_cast<Son*>(f);

	//����ת������ȫ
	Fat* f1 = static_cast<Fat*>(s);

	//Other* o = static_cast<Other*>(s);//û�м̳й�ϵ���޷�ת��
}

//����ת��
void test03() {
	Fat f;
	Son s;
	Fat& ref_f = f;
	Son& ref_s = s;
	//���ϣ���ȫ
	Fat& f1=static_cast<Fat&>(ref_s);
	//���£�����ȫ
	Son& s1=static_cast<Son&>(ref_f);

}

//----------------------��̬ת��dynamic_cast---------------------
//��Ҫ�������μ������ת��������ת��
//������ת��ʱ����static_castЧ����һ����
//��ͬ���ǣ�������ת��ʱdynamic_cast�������ͼ��Ĺ��ܣ���static_cast��ȫ

void test04() {
	char a = 'a';
	//dynamic_cast<double>(a);//�������Ͳ���ʹ�ö�̬ת��
	Fat* f = nullptr;
	Son* s = nullptr;
	//���ϣ���ȫ
	Fat* f1 = dynamic_cast<Fat*>(s);
	//����,����ȫ������
	//Son* s1 = dynamic_cast<Son*>(f);//�ò�������Fat���Ƕ�̬����
}

class Fat2 {
public:
	virtual void func() {};
};
class Son2 :public Fat2 {
public:
	virtual void func() {};
};
//������̬������ת������̬ת���Ϳ���
void test05() {
	Fat2* f = new Son2;
	Son2* s2 = dynamic_cast<Son2*>(f);
}


//����ת��--------------------const_cast-------------------
//�����޸����͵�const����,ֻ����ָ�������
//ע�⣺����ֱ�ӶԷ�ָ��ͷ����õı���ʹ��const_cast������ֱ���Ƴ�����const

void test06() {
	const int* p = nullptr;
	int* newp = const_cast<int*>(p);

	int* pp = nullptr;
	const int* npp = const_cast<const int*>(pp);
}

//���½���ת��------------------reinterpret_cast-------------------
//�ܲ���ȫ��������
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
