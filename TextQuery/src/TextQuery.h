#pragma once

#include<iostream>
using namespace std;
#include<fstream>
#include<vector>
#include<map>
#include<set>
#include<sstream>
#include<string>

class QueryResult;
class TextQuery {
public:
	using line_no = vector<string>::size_type;
	TextQuery(ifstream&);
	QueryResult query(const string&) const;
private:
	shared_ptr<vector<string>> file;	//输入文件
	map<string, shared_ptr<set<line_no>>> wm;	//每个单词到它所在行号的集合的映射
};