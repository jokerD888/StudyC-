#define _CRT_SECURE_NO_WARNINGS 1


#include"TextQuery.h"


TextQuery::TextQuery(ifstream& is) :file(new vector<string>) {
	string text;
	while (getline(is, text)) {
		file->push_back(text);		//��������ı�
		int n = file->size() - 1;	//��ǰ�ı��к�
		istringstream line(text);	//�����ı��ֽ�Ϊ����
		string word;
		while (line >> word) {
			auto& lines = wm[word];
			if (!lines)
				lines.reset(new set<line_no>);
			lines->insert(n);
		}
	}
}





