#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<iostream>
using namespace std;

//6.��дģ�庯��, ������һ��T����Ԫ����ɵ������һ����ʾ����Ԫ����Ŀ��������Ϊ����������������������Ԫ�ء�
//�ڳ����ж������в��ԣ��ó���ʹ��һ������6��intԪ�ص������һ������4��doubleԪ�ص����������øú�����
//���򻹰���һ�����廯������charָ������������е�ָ��������Ϊ����������������ַ����ĵ�ַ��
//����ж���������ַ������򷵻����е�1���ַ����ĵ�ַ��ʹ����5���ַ���ָ����ɵ����������Ըþ��廯��


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
//��
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

	cout << "arr1����������Ϊ��" << maxInt << endl;;
	cout << "arr2����������Ϊ��" << maxDouble << endl;
	cout << "arr3����������ַ���Ϊ��" << maxString << endl;

	return 0;

}