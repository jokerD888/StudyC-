#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

//��ģ�����ã�
//����һ��ͨ���࣬���еĳ�Ա �������Ϳ��Բ������ƶ�����һ�����������������
//�﷨��
//template<typename T>
//��

//��ģ��
template<class NameType, class AgeType>
class Person
{
public:
	Person(NameType name, AgeType age)
	{
		this->mName = name;
		this->mAge = age;
	}
	void showPerson()
	{
		cout << "name: " << this->mName << " age: " << this->mAge << endl;
	}
public:
	NameType mName;
	AgeType mAge;
};

void test01()
{
	// ָ��NameType Ϊstring���ͣ�AgeType Ϊ int����
	Person<string, int>P1("�����", 999);
	P1.showPerson();
}



int main(void)
{
	return 0;
}
