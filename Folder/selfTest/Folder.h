//�������������࣬������������ļ���д����������֮�����໥��������Ҫʹ���������������ͣ�����Ը�
//���������һ���ļ���д������ʡȥ�����鷳����

#pragma once
#include<iostream>
using namespace std;
#include<set>


class Message;
//��ϢĿ¼��
class Folder {
public:
	//����Folder��������Ӱ�쵽Message����������Folder����Message������Message������ʱfoldersָ��Ŀռ��ѱ��ͷţ�
	//���ᵼ�·Ƿ����ʣ�������д��������
	~Folder();	
	//��msg��Ϣ��������Ӻ�ɾ��Message
	void addMsg(Message*);
	void remMsg(Message*);

//private:
	set<Message*> msg;	//��Ϣ����
};


class Message {
	friend class Folder;
	friend void swap(Message&, Message&);
public:
	explicit Message(const string& str = "") :
		contents(str) {}
	Message(const Message&);
	Message& operator=(const Message&);
	~Message();
	//�Ӹ���Folders���������/ɾ����Message
	void save(Folder&);
	void remove(Folder&);
	//private:
	string contents;		//ʵ����Ϣ�ı�
	set<Folder*> folders;	//������Message��Folder

	//�������ߺ������������캯����������ֵ����������
	//����Message��ӵ�ָ��������Folder��
	void add_to_Folder(const Message&);
	//��folders�е�ÿ��Folder��ɾ����Message
	void remove_from_Folders();
};
