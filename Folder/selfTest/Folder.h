//本程序有两个类，本想两个类分文件编写，但两个类之间又相互包含且需要使用完整的数据类型，耦合性高
//故两类放于一个文件编写，反而省去不少麻烦事情

#pragma once
#include<iostream>
using namespace std;
#include<set>


class Message;
//消息目录类
class Folder {
public:
	//对于Folder的析构会影响到Message的析构，若Folder先于Message析构，Message再析构时folders指向的空间已被释放，
	//将会导致非法访问，所以重写析构函数
	~Folder();	
	//在msg消息集合中添加和删除Message
	void addMsg(Message*);
	void remMsg(Message*);

//private:
	set<Message*> msg;	//消息集合
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
	//从给定Folders集合中添加/删除本Message
	void save(Folder&);
	void remove(Folder&);
	//private:
	string contents;		//实际消息文本
	set<Folder*> folders;	//包含本Message的Folder

	//两条工具函数，辅助构造函数、拷贝赋值和析构函数
	//将本Message添加到指定参数的Folder中
	void add_to_Folder(const Message&);
	//从folders中的每个Folder中删除本Message
	void remove_from_Folders();
};
