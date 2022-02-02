#define _CRT_SECURE_NO_WARNINGS 1
#include"Folder.h"


void Folder::addMsg(Message* m) {
	msg.insert(m);
}

void Folder::remMsg(Message* m) {
	msg.erase(m);
}

Folder::~Folder() {	

	for (auto m : msg) {		//������Ϣ���ϣ�ʹ��ÿ��Message��foldersȥ��������ϢĿ¼
		m->folders.erase(this);
	}
	cout << "Folder����" << endl;
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
	cout << "Message����" << endl;
}

Message& Message::operator=(const Message& rhs) {
	//��ͨ��ɾ��ָ���ٲ������������������Ҹ�ֵ���
	remove_from_Folders();
	contents = rhs.contents;
	folders = rhs.folders;
	add_to_Folder(rhs);
	return *this;
}
