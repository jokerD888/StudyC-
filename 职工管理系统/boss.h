#define _CRT_SECURE_NO_WARNINGS 1
#include "worker.h"

//�ϰ���
class Boss :public Worker
{
public:

	Boss(int id, string name, int dId);

	//��ʾ������Ϣ
	virtual void showInfo();

	//��ȡְ����λ����
	virtual string getDeptName();
};
