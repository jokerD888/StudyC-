#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<iostream>
using namespace std;

template<class T>
class MyArray
{
public:
	//����
	MyArray(int capacity)
	{
		//cout << "�������" << endl;//���Դ���
		this->m_Capacity = capacity;
		this->m_Size = 0;
		pAddress = new T[this->m_Capacity];
	}
	//��������
	MyArray(const MyArray& arr)
	{
		//cout << "�����������" << endl;//���Դ���

		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		//this->pAddress=arr.pAddress//ϵͳǳ�����Ĵ���
		this->pAddress = new T[this->m_Capacity];
		for (int i = 0; i < this->m_Size; i++)
		{
			//���TΪ���󣬶��һ�������ָ�룬������Ҫ���� = ����������ͨ���Ϳ��Բ���
			this->pAddress[i] = arr.pAddress[i];
		}
	}
	//����=����������ֹǳ��������
	MyArray& operator=(const MyArray& myarray)
	{
		//cout << "����operator=����" << endl;//���Դ���

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
	
	//β��
	void PushBack(const T& val)
	{
		if (this->m_Size == this->m_Capacity)
		{
			return;
		}
		this->pAddress[this->m_Size] = val;
		this->m_Size++;//���µ�ǰ�����С
	}

	//βɾ
	void PopBack()
	{
		if (this->m_Size == 0)
		{
			return;
		}
		this->m_Size--;
	}

	//ͨ���±귽ʽ����������Ԫ��
	//����[]�����
	T& operator[](int index)
	{
		return this->pAddress[index];
	}

	//������������
	int GetCapacity()
	{
		return this->m_Capacity;
	}
	//���������С
	int GetSize()
	{
		return this->m_Size;
	}

	//����
	~MyArray()
	{
		//cout << "��������" << endl;//���Դ���

		if (this->pAddress != NULL)
		{
			delete[] this->pAddress;
			this->pAddress = NULL;
		}
	}
private:
	T* pAddress;//ָ��һ���ѿռ䣬���ڴ�������
	int m_Capacity;//����
	int m_Size;//��ǰ�ռ��С
};