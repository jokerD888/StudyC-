#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;


//��̬���ŵ㣺
//1.������֯�ṹ����
//2.�ɶ���ǿ
//3.����ǰ�ںͺ��ڵ���չ�Լ�ά��

//�ֱ�������ͨд���Ͷ�̬���������ʵ��������������������ļ�������

//��ͨʵ��
class Calculator {
public:
	int getResult(string oper)
	{
		if (oper == "+") {
			return m_Num1 + m_Num2;
		}
		else if (oper == "-") {
			return m_Num1 - m_Num2;
		}
		else if (oper == "*") {
			return m_Num1 * m_Num2;
		}
		//���Ҫ�ṩ�µ����㣬��Ҫ�޸�Դ��
	}
public:
	int m_Num1;
	int m_Num2;
};

void test01()
{
	//��ͨʵ�ֲ���
	Calculator c;
	c.m_Num1 = 10;
	c.m_Num2 = 10;
	cout << c.m_Num1 << " + " << c.m_Num2 << " = " << c.getResult("+") << endl;

	cout << c.m_Num1 << " - " << c.m_Num2 << " = " << c.getResult("-") << endl;

	cout << c.m_Num1 << " * " << c.m_Num2 << " = " << c.getResult("*") << endl;
}

//--------------------------------------------------------------------------

//��̬ʵ��
//�����������
//��̬�ŵ㣺������֯�ṹ�������ɶ���ǿ������ǰ�ںͺ��ڵ���չ�Լ�ά��
class AbstractCalculator
{
public:

	virtual int getResult()
	{
		return 0;
	}

	int m_Num1;
	int m_Num2;
};

//�ӷ�������
class AddCalculator :public AbstractCalculator
{
public:
	int getResult()
	{
		return m_Num1 + m_Num2;
	}
};

//����������
class SubCalculator :public AbstractCalculator
{
public:
	int getResult()
	{
		return m_Num1 - m_Num2;
	}
};

//�˷�������
class MulCalculator :public AbstractCalculator
{
public:
	int getResult()
	{
		return m_Num1 * m_Num2;
	}
};


void test02()
{
	//�����ӷ�������
	AbstractCalculator* abc = new AddCalculator;
	abc->m_Num1 = 10;
	abc->m_Num2 = 10;
	cout << abc->m_Num1 << " + " << abc->m_Num2 << " = " << abc->getResult() << endl;
	delete abc;  //�����˼ǵ�����

	//��������������
	abc = new SubCalculator;
	abc->m_Num1 = 10;
	abc->m_Num2 = 10;
	cout << abc->m_Num1 << " - " << abc->m_Num2 << " = " << abc->getResult() << endl;
	delete abc;

	//�����˷�������
	abc = new MulCalculator;
	abc->m_Num1 = 10;
	abc->m_Num2 = 10;
	cout << abc->m_Num1 << " * " << abc->m_Num2 << " = " << abc->getResult() << endl;
	delete abc;
}

//��Ȼ��̬�Ա���ͨд��ʵ�ִ��������ܻ�ϴ�һЩ������̬�����ǳ������������ң�
// ǰ��ά����ֱ�Ӳ��Ҷ�Ӧ���ܵ����ࣩ������չ��ֱ����дһ�������ӿڣ���������֮ǰ�Ѿ����ƵĴ��룩(ǰ�պ󿪣������Ǵ���Ŀɶ��Զ�Ҫ������ͨд��
//�ܽ᣺C++�����ᳫ���ö�̬��Ƴ���ܹ�����Ϊ��̬�ŵ�ܶ�
int main() {

	//test01();

	test02();

	return 0;
}