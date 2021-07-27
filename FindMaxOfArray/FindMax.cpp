#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<iostream>
using namespace std;

//6.编写模板函数, 它以由一个T类型元素组成的数组和一个表示数组元素数目的整数作为参数，并返回数组中最大的元素。
//在程序中对它进行测试，该程序使用一个包含6个int元素的数组和一个包含4个double元素的数组来调用该函数。
//程序还包含一个具体化，它以char指针数组和数组中的指针数量作为参数，并返回最长的字符串的地址。
//如果有多个这样的字符串，则返回其中第1个字符串的地址。使用由5个字符串指针组成的数组来测试该具体化。


//template<typename T,int sz>
//T FindMax(T(&arr)[sz], int len)
//{
//	T max = arr[0];
//	for (int i = 1; i < len; i++)
//	{
//		if (arr[i] > max)
//			max = arr[i];
//	}
//
//	return max;
//}
//或
template<typename T>
T FindMax(T* arr, int len)
{
	T max = arr[0];
	for (int i = 1; i < len; i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}

	return max;
}

template<> char* FindMax(char* arr[], int num)
{
	int i = 0;
	int maxLen = strlen(arr[0]);
	int max = 0;
	for (i = 1; i < num; i++)
	{
		if (strlen(arr[i]) > maxLen)
		{
			max = i;
			maxLen = strlen(arr[i]);
		}
	}

	return arr[max];
}

int main(void)
{
	int arr1[] = { 0,1,4,7,5,9,6 };
	double arr2[] = { 3.14,1.1,8.9,0.2,6.6 };
	char str1[] = "agarfa";
	char str2[] = "auregui";
	char str3[] = "rgsg";
	char str4[] = "abcdefghijk";
	char str5[] = "a";
	char str6[] = "abcdefghijk";
	char* arr3[] = { str1,str2,str3,str4,str5,str6 };

	int len1 = sizeof(arr1) / sizeof(int);
	int len2 = sizeof(arr2) / sizeof(double);
	int len3 = sizeof(arr3) / sizeof(char*);

	int maxInt = FindMax(arr1, len1);
	double maxDouble = FindMax(arr2, len2);
	char* maxString = FindMax(arr3, len3);

	cout << "arr1数组的最大数为：" << maxInt << endl;;
	cout << "arr2数组的最大数为：" << maxDouble << endl;
	cout << "arr3数组中最长的字符串为：" << maxString << endl;

	return 0;

}