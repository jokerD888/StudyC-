#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//����ԭ�ͣ�
//reverse();    //��ת����
//sort();        //��������

#include<list>
void printList(const list<int>& L) 
{

	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++) 
	{
		cout << *it << " ";
	}
	cout << endl;
}

bool myCompare(int val1, int val2)
{
	return val1 > val2;
}

//��ת������
void test01()
{
	list<int> L;
	L.push_back(90);
	L.push_back(30);
	L.push_back(20);
	L.push_back(70);
	cout << "��תǰ��" << endl;
	printList(L);

	//��ת������Ԫ��
	L.reverse();
	cout << "��ת��" << endl;
	printList(L);

	//����
	L.sort(); //Ĭ�ϵ�������� ��С����
	cout << "����" << endl;

	printList(L);

	L.sort(myCompare); //ָ�����򣬴Ӵ�С
	cout << "����" << endl;
	printList(L);
}

int main() {

	test01();

	return 0;
}

