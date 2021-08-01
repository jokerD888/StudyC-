#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

//����������
//ϴ��   ָ����Χ�ڵ�Ԫ�������������
//
//����ԭ�ͣ�
//random_shuffle(iterator beg, iterator end);  
// ָ����Χ�ڵ�Ԫ�������������
// beg ��ʼ������
// end ����������
//�ܽ᣺random_shuffleϴ���㷨�Ƚ�ʵ�ã�ʹ��ʱ�ǵü����������
#include <algorithm>
#include <vector>
#include <ctime>

class myPrint
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};

void test01()
{
	srand((unsigned int)time(NULL));//��Ҫ����д
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	for_each(v.begin(), v.end(), myPrint());
	cout << endl;

	//����˳��
	random_shuffle(v.begin(), v.end());
	for_each(v.begin(), v.end(), myPrint());
	cout << endl;
}

int main()
{
	test01();

	return 0;
}

