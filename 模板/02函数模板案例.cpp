#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

//交换函数模板
template<typename T>
void MySwap(T& a, T& b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

//排序函数模板
template<typename T>
void MySort(T arr[], int len)
{
	//选择排序
	for (int i = 0; i < len-1; i++)
	{
		int min = i;
		for (int j = i + 1; j < len; j++)
		{
			if (arr[j] < arr[min])
				min = j;
		}
		if (min != i)
		{
			//T tmp = arr[min];
			//arr[min] = arr[i];
			//arr[i] = tmp;
			//或
			MySwap(arr[min], arr[i]);
		}
	}
}

//打印函数模板
template<typename T>
void PrintArray(T& arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void test01()
{
	char arr[] = "bacdfeg";
	int len = sizeof(arr) / sizeof(char);
	MySort(arr, len-1);//len-1是因为最后'\0'在最后也占了1个字符空间
	PrintArray(arr, len);
}

void test02()
{
	int arr[] = { 4,2,8,6,1,9,7,3,5 };
	int num = sizeof(arr) / sizeof(int);
	MySort(arr, num);
	PrintArray(arr, num);

}
int main(void)
{
	test01();
	test02();
	return 0;
}
