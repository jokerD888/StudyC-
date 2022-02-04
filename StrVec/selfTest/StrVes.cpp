#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<algorithm>
#include<utility>
#include<memory>


class StrVec {
public:
	StrVec() :elements(nullptr), first_free(nullptr), cap(nullptr) {}
	StrVec(const StrVec&);
	StrVec& operator=(const StrVec&);
	~StrVec();

	void push_back(const string&);
	size_t size() const { return first_free - elements; }
	size_t capacity() const { return cap - elements; }
	string* begin() const { return elements; }
	string* end() const { return first_free; }
private:
	//分配元素
	static allocator<string> alloc;	
	//被添加元素的函数所使用
	void chk_n_alloc() {
		if (size() == capacity()) reallocate();
	}
	//工具函数，被拷贝构造函数，赋值运算符和析构函数所使用
	pair<string*, string*> alloc_n_copy(const string*, const string*);
	void free();
	void reallocate();

	string* cap;			//指向数组尾后位置的指针
	string* first_free;		//指向数组第一个空闲元素的地址
	string* elements;		//指向数组首元素的指针

};

allocator<string> StrVec::alloc;

void StrVec::push_back(const string& s) {
	chk_n_alloc();	//确保有空间容纳新元素
	alloc.construct(first_free++, s);
}

pair<string*, string*> StrVec::alloc_n_copy(const string* b, const string* e) {
	//分配空间保存给定范围元素
	auto data = alloc.allocate(e - b);
	return { data,uninitialized_copy(b,e,data) };
}

void StrVec::free() {
	//检查elements是否为空，deallocate不能传空指针
	if (elements) {
		for (auto p = first_free; p != elements;/*空*/)
			alloc.destroy(--p);
		alloc.deallocate(elements, cap - elements);
	}
}

StrVec::StrVec(const StrVec& s) {
	auto newdata = alloc_n_copy(s.begin(), s.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}

StrVec::~StrVec() { free(); }

StrVec& StrVec::operator=(const StrVec& rhs) {
	auto data = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}

void StrVec::reallocate() {
	//分配两倍大的内存空间
	auto newCapacity = size() ? 2 * size() : 1;
	//分配新内存
	auto newData = alloc.allocate(newCapacity);
	//将数据从旧内存移动到新内存
	auto dest = newData;
	auto elem = elements;
	for (size_t i = 0; i != size(); ++i) {
		alloc.construct(dest++, std::move(*elem++));
	}
	free();//释放旧空间
	//更新数据结构
	elements = newData;
	first_free = dest;
	cap = elements + newCapacity;
}

int main() {
	StrVec s;
	s.push_back("123");

	s.push_back("11");
	s.push_back("1222");
	s.push_back("ANC");
	
	cout <<*s.begin();
	cout << *(s.begin()+1);
	cout << *(s.begin()+2); 
	cout << *(s.begin()+3);

	return 0;

}

