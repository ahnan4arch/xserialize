#include <stdio.h>
#include <string>
#include <map>
#include <vector>

#include "MemSerialize.h"
#include "MemDeSerialize.h"
#include "FileSerialize.h"
#include "serializeImpl.h"

using namespace xutil;
using namespace std;
class User
{
public:
	int userId;
	string userNo;
	string userName;
};

template<class Archive>
void xserialize(Archive& ar, User& val)
{
	ar & val.userId;
	ar & val.userName;
	ar & val.userNo;
}
struct Session
{
	int sessionId;
	User onlineUser;
};

template<class Archive>
void xserialize(Archive& ar, Session& val)
{
	ar & val.sessionId;
	ar & val.onlineUser;
}
void test1()
{
	char buf[1024] = { 0 };
	User u;
	Session s;
	Session s2;
	Session s3;
	u.userId = 1;
	u.userName = "xianhongdong";
	u.userNo = "05010233";
	s.sessionId = 100;
	s.onlineUser = u;
	vector<User> vct1;
	vector<User> vct2;

	vct1.push_back(u);
	vct1.push_back(u);

	MemSerialize seAr(buf);
	MemDeSerialize desAr(buf);
	int a = 10;
	int b = 1;
	std::map<int, string> mm;
	std::map<int, string> mm2;
	std::map<int, User> m3;
	std::map<int, User> m4;

	mm[1] = "001";
	mm[2] = "002";
	mm[3] = "003";
	m3[1] = u;
	const Session& cs = s;
	seAr & a;
	seAr & s;
	seAr & cs;
	seAr & mm;
	seAr & m3;
	seAr & vct1;
	
	desAr & b;
	desAr & s2;
	desAr & s3;
	desAr & mm2;
	desAr & m4;
	desAr & vct2;

	char buf2[1024] = { 0 };
	MemSerialize archvie(buf2);
	archvie & b;
	archvie & s2;
	archvie & s3;
	archvie & mm2;
	archvie & m4;
	archvie & vct2;

	if (0 == memcmp(buf, buf2, 1024))
	{
		printf("test success\n");
	}
	else
	{
		printf("test failed\n");
	}
	FileSerialize  fs("test.txt");
	fs & s;
	fs & vct1;

}
int main()
{
	try {
		test1();
	}
	catch (runtime_error err)
	{
		printf("%s\n", err.what());
	}
	getchar();
	return		0;
}