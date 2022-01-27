#define _CRT_SECURE_NO_WARNINGS 1
#include "QueryResult.h"
#include "TextQuery.h"


string makePlural(size_t ctr, const string& word, const string& ending) {
	return ctr > 1 ? word + ending : word;
}
ostream& print(ostream& os, const QueryResult& qr) {
	//打印出现数量信息
	os << qr.sought << " occurs " << qr.lines->size() << " "
		<< makePlural(qr.lines->size(), "time", "s") << endl;

	//打印单词出现的每一行
	for (auto num : *qr.lines) {
		os << "\t(line " << num + 1 << ")" << *(qr.file->begin() + num) << endl;
	}

	return os;
}

void runQueries(ifstream& infile) {
	TextQuery tq(infile);

	while (true) {
		cout << "enter word to look for, or q to quit: ";
		string s;

		if (!(cin >> s) || s == "q")  break;

		print(cout, tq.query(s)) << endl;

	}
}

int main()
{
	ifstream in("test.txt");
	runQueries(in);
	return 0;
}
