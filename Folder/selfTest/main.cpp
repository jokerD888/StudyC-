#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;
#include<set>
#include"Folder.h"


void swap(Message& lhs, Message& rhs) {
	using std::swap;

	for (auto f : lhs.folders) {
		f->remMsg(&lhs);
	}
	for (auto f : rhs.folders) {
		f->remMsg(&rhs);
	}

	swap(lhs.folders, rhs.folders);
	swap(lhs.contents, rhs.contents);
	for (auto f : lhs.folders) {
		f->addMsg(&lhs);
	}
	for (auto f : rhs.folders) {
		f->addMsg(&rhs);
	}
}


void test() {
	Message s1("abc"),s2("123"),s3("ABC");	//创建消息1
	Folder f1, f2;			//创建消息目录1	
	s1.save(f1);		//消息1,2加入到目录1
	s1.save(f2);

	s2.save(f1);

	swap(s2, s3);


}

int main()
{

	test();
	return 0;
}