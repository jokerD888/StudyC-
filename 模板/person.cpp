#define _CRT_SECURE_NO_WARNINGS 1
#include"person.h"
//类外实现
template<class T1,class T2>
Person<T1, T2>::Person(T1 name, T2 age)
{
	this->m_Age = age;
	this->m_Name = name;
}


template<class T1, class T2>
void Person<T1, T2>::ShowPerson()
{
	cout << "name: " <<this->m_Name << "\tage: " << this->m_Age << endl;
}
