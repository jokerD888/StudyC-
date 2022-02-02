#define _CRT_SECURE_NO_WARNINGS 1
#include"Folder.h"


void Folder::addMsg(Message* m) {
	msg.insert(m);
}

void Folder::remMsg(Message* m) {
	msg.erase(m);
}

Folder::~Folder() {	

	for (auto m : msg) {		//遍历消息集合，使得每条Message中folders去除本条消息目录
		m->folders.erase(this);
	}
	cout << "Folder析构" << endl;
}


void Message::save(Folder& f) {
	folders.insert(&f);
	f.addMsg(this);
}

void Message::remove(Folder& f) {
	folders.erase(&f);
	f.remMsg(this);
}

void Message::add_to_Folder(const Message& m) {
	for (auto f : m.folders) {
		f->addMsg(this);
	}
}

Message::Message(const Message& m) :contents(m.contents) {
	add_to_Folder(m);
}

void Message::remove_from_Folders() {
	for (auto f : folders) {
		f->remMsg(this);
	}
}

Message::~Message() {
	remove_from_Folders();
	cout << "Message析构" << endl;
}

Message& Message::operator=(const Message& rhs) {
	//先通过删除指针再插入它们来处理了自我赋值情况
	remove_from_Folders();
	contents = rhs.contents;
	folders = rhs.folders;
	add_to_Folder(rhs);
	return *this;
}
