#define _CRT_SECURE_NO_WARNINGS 1

#include"employee.h"

Employee::Employee(int id, string name, int did)
{
	m_Id = id;
	m_Name = name;
	m_DeptId = did;
}
//��ʾ������Ϣ
void Employee::showInfo()
{
	cout << "ְ����ţ� " << m_Id
		<< "\tְ��������" << m_Name
		<< "\t��λ��" << getDeptName()
		<< "\t��λְ��: ��ɾ�����������" << endl;
}
//��ȡְλ����
string Employee::getDeptName()
{
	return string("Ա��");
}

