#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<iostream>
using namespace std;

template<class T>
class MyArray
{
public:
	//构造
	MyArray(int capacity)
	{
		//cout << "构造调用" << endl;//测试代码
		this->m_Capacity = capacity;
		this->m_Size = 0;
		pAddress = new T[this->m_Capacity];
	}
	//拷贝构造
	MyArray(const MyArray& arr)
	{
		//cout << "拷贝构造调用" << endl;//测试代码

		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		//this->pAddress=arr.pAddress//系统浅拷贝的代码
		this->pAddress = new T[this->m_Capacity];
		for (int i = 0; i < this->m_Size; i++)
		{
			//如果T为对象，而且还包含着指针，必须需要重载 = 操作符，普通类型可以不用
			this->pAddress[i] = arr.pAddress[i];
		}
	}
	//重载=操作符，防止浅拷贝问题
	MyArray& operator=(const MyArray& myarray)
	{
		//cout << "重载operator=调用" << endl;//测试代码

		if (this->pAddress != NULL)
		{
			delete[] this->pAddress;
			this->m_Capacity = 0;
			this->m_Size = 0;
		}

		this->m_Capacity = myarray.m_Capacity;
		this->m_Size = myarray.m_Size;
		this->pAddress = new T[this->m_Capacity];
		for (int i = 0; i < this->m_Size; i++)
		{
			this->pAddress[i] = myarray.pAddress[i];
		}

		return *this;
	}
	
	//尾插
	void PushBack(const T& val)
	{
		if (this->m_Size == this->m_Capacity)
		{
			return;
		}
		this->pAddress[this->m_Size] = val;
		this->m_Size++;//更新当前数组大小
	}

	//尾删
	void PopBack()
	{
		if (this->m_Size == 0)
		{
			return;
		}
		this->m_Size--;
	}

	//通过下标方式访问数组中元素
	//重载[]运算符
	T& operator[](int index)
	{
		return this->pAddress[index];
	}

	//返回数组容量
	int GetCapacity()
	{
		return this->m_Capacity;
	}
	//返回数组大小
	int GetSize()
	{
		return this->m_Size;
	}

	//析构
	~MyArray()
	{
		//cout << "析构调用" << endl;//测试代码

		if (this->pAddress != NULL)
		{
			delete[] this->pAddress;
			this->pAddress = NULL;
		}
	}
private:
	T* pAddress;//指向一个堆空间，用于储存数据
	int m_Capacity;//容量
	int m_Size;//当前空间大小
};