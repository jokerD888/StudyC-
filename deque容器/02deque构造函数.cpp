#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

//����ԭ�ͣ�
//deque<T >  deqT;                      //Ĭ�Ϲ�����ʽ
//deque(beg, end);                  //���캯����[beg, end)�����е�Ԫ�ؿ���������
//deque(n, elem);                    //���캯����n��elem����������
//deque(const deque& deq);   //�������캯��

#include <deque>

void printDeque(const deque<int>& d)//����const���κ�����ĵ�������������Ҳ�����const_
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++) 
	{
		cout << *it << " ";

	}
	cout << endl;
}
//deque����
void test01()
{

	deque<int> d1; //�޲ι��캯��
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}
	printDeque(d1);
	deque<int> d2(d1.begin(), d1.end());
	printDeque(d2);

	deque<int>d3(10, 100);
	printDeque(d3);

	deque<int>d4 = d3;
	printDeque(d4);
}
int main(void)
{
	test01();
	return 0;

}
