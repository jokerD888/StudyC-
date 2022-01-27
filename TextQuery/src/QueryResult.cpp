#define _CRT_SECURE_NO_WARNINGS 1

#include"QueryResult.h"
#include"TextQuery.h"

QueryResult TextQuery::query(const string& sought) const {
	//如果未找到sought，将返回一个指向此set的指针
	static shared_ptr<set<line_no>> nodata(new set<line_no>);

	auto loc = wm.find(sought);
	if (loc == wm.end()) {
		return QueryResult(sought, nodata, file);	//未找到
	} else {
		return QueryResult(sought, loc->second, file);
	}
}