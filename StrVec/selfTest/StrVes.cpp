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
	//����Ԫ��
	static allocator<string> alloc;	
	//�����Ԫ�صĺ�����ʹ��
	void chk_n_alloc() {
		if (size() == capacity()) reallocate();
	}
	//���ߺ��������������캯������ֵ�����������������ʹ��
	pair<string*, string*> alloc_n_copy(const string*, const string*);
	void free();
	void reallocate();

	string* cap;			//ָ������β��λ�õ�ָ��
	string* first_free;		//ָ�������һ������Ԫ�صĵ�ַ
	string* elements;		//ָ��������Ԫ�ص�ָ��

};

allocator<string> StrVec::alloc;

void StrVec::push_back(const string& s) {
	chk_n_alloc();	//ȷ���пռ�������Ԫ��
	alloc.construct(first_free++, s);
}

pair<string*, string*> StrVec::alloc_n_copy(const string* b, const string* e) {
	//����ռ䱣�������ΧԪ��
	auto data = alloc.allocate(e - b);
	return { data,uninitialized_copy(b,e,data) };
}

void StrVec::free() {
	//���elements�Ƿ�Ϊ�գ�deallocate���ܴ���ָ��
	if (elements) {
		for (auto p = first_free; p != elements;/*��*/)
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
	//������������ڴ�ռ�
	auto newCapacity = size() ? 2 * size() : 1;
	//�������ڴ�
	auto newData = alloc.allocate(newCapacity);
	//�����ݴӾ��ڴ��ƶ������ڴ�
	auto dest = newData;
	auto elem = elements;
	for (size_t i = 0; i != size(); ++i) {
		alloc.construct(dest++, std::move(*elem++));
	}
	free();//�ͷžɿռ�
	//�������ݽṹ
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

