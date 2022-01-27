#pragma once
#include<iostream>
using namespace std;
#include<fstream>
#include<vector>
#include<map>
#include<set>
#include<sstream>
#include<string>

class QueryResult {
	friend ostream& print(ostream&, const QueryResult&);		//声明友元，使得print函数访问
public:
	using line_no = vector<string>::size_type;

	QueryResult(string s, shared_ptr<set<line_no>> p, shared_ptr<vector<string>> f) :
		sought(s), lines(p), file(f) {}


private:
	string sought;	//查询单词
	shared_ptr<set<line_no>> lines;		//出现的行数
	shared_ptr<vector<string>> file;	//输入文件
};