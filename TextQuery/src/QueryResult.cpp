#define _CRT_SECURE_NO_WARNINGS 1

#include"QueryResult.h"
#include"TextQuery.h"

QueryResult TextQuery::query(const string& sought) const {
	//���δ�ҵ�sought��������һ��ָ���set��ָ��
	static shared_ptr<set<line_no>> nodata(new set<line_no>);

	auto loc = wm.find(sought);
	if (loc == wm.end()) {
		return QueryResult(sought, nodata, file);	//δ�ҵ�
	} else {
		return QueryResult(sought, loc->second, file);
	}
}