#define _CRT_SECURE_NO_WARNINGS 1


#include"TextQuery.h"


TextQuery::TextQuery(ifstream& is) :file(new vector<string>) {
	string text;
	while (getline(is, text)) {
		file->push_back(text);		//保存此行文本
		int n = file->size() - 1;	//当前文本行号
		istringstream line(text);	//将行文本分解为单词
		string word;
		while (line >> word) {
			auto& lines = wm[word];
			if (!lines)
				lines.reset(new set<line_no>);
			lines->insert(n);
		}
	}
}





