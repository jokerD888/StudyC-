#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

class Building;//����
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
	//���߱����� goodGay����Building��ĺ����ѣ����Է��ʵ�Building����˽������
	friend class goodGay;

public:
	Building();

public:
	string m_SittingRoom; //����
private:
	string m_BedRoom;//����
};

//����ʵ�ֺ���������ǰҪ�����������߱������������еĺ���
Building::Building()
{
	this->m_SittingRoom = "����";
	this->m_BedRoom = "����";
}

goodGay::goodGay()
{
	//goodGay���캯������new��һ��Building�࣬��ͨ��Building�๹�캯����ʼ���˳�Ա����
	building = new Building;
}

void goodGay::visit()
{
	cout << "�û������ڷ���" << building->m_SittingRoom << endl;
	cout << "�û������ڷ���" << building->m_BedRoom << endl;
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
