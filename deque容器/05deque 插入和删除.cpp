#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

//����ԭ�ͣ�
//���˲��������
//push_front(elem);        //������ͷ������һ������
//pop_back();                  //ɾ���������һ������
//pop_front();               //ɾ��������һ������
//
//ָ��λ�ò�����
//insert(pos, elem);          //��posλ�ò���һ��elemԪ�صĿ��������ز������ݵ�λ�á�
//insert(pos, n, elem);      //��posλ�ò���n��elem���ݣ��޷���ֵ��
//insert(pos, beg, end);    //��posλ�ò���[beg,end)��������ݣ��޷���ֵ��ע�⣺����ҿ�
//clear();                            //�����������������
//erase(beg, end);             //ɾ��[beg,end)��������ݣ�������һ�����ݵ�λ�á�ע�⣺����ҿ�
//erase(pos);                   //ɾ��posλ�õ����ݣ�������һ�����ݵ�λ�á�

#include <deque>

void printDeque(const deque<int>& d)
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++) {
		cout << *it << " ";

	}
	cout << endl;
}
//���˲���
void test01()
{
	deque<int> d;
	//β��
	d.push_back(10);
	d.push_back(20);
	//ͷ��
	d.push_front(100);
	d.push_front(200);

	printDeque(d);

	//βɾ
	d.pop_back();
	//ͷɾ
	d.pop_front();
	printDeque(d);
}

//����
void test02()
{
	deque<int> d;
	d.push_back(10);
	d.push_back(20);
	d.push_front(100);
	d.push_front(200);
	printDeque(d);

	d.insert(d.begin(), 1000);
	printDeque(d);

	d.insert(d.begin(), 2, 10000);
	printDeque(d);

	deque<int>d2;
	d2.push_back(1);
	d2.push_back(2);
	d2.push_back(3);

	d.insert(d.begin(), d2.begin(), d2.end());
	printDeque(d);

}

//ɾ��
void test03()
{
	deque<int> d;
	d.push_back(10);
	d.push_back(20);
	d.push_front(100);
	d.push_front(200);
	printDeque(d);

	d.erase(d.begin());
	printDeque(d);

	d.erase(d.begin(), d.end());
	d.clear();
	printDeque(d);
}
void test04()
{
	deque<int> d;
	d.push_back(30);
	d.push_back(40);
	d.push_front(20);
	d.push_front(10);

	d.insert(d.insert(d.begin() += 2, 15), 14); //�˺����ķ���ֵ�����²������ݵ�λ�á�
	printDeque(d);

	d.erase(d.erase(d.begin() += 2, d.begin() += 3));//ɾ��2��3���䣨����ҿ��������ݺ��ٸ��ݷ���ֵɾ����һ��
	printDeque(d);
}
int main() 
{

	//test01();
	//test02();

	//test03();
	test04();
	return 0;
}

