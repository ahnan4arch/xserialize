#include "MemSerialize.h"

using namespace xutil;

MemSerialize::~MemSerialize()
{
}

MemSerialize::MemSerialize(char * buffer)
{
	this->buf = buffer;
	this->bufLen = strlen(buffer) + 1;
}
MemSerialize& MemSerialize::operator&(const int& val)
{
	int* pData = (int*)(buf + offset);
	*pData = val;
	offset += sizeof(int);
	return *this;
}
MemSerialize& MemSerialize::operator&(int& val)
{
	int* pData = (int*)(buf + offset);
	*pData = val;
	offset += sizeof(int);
	return *this;
}
MemSerialize& MemSerialize::operator&(const char* val)
{
	int len = strlen(val) + 1;
	memcpy(buf + offset, val, len);
	offset += len;
	return *this;
}
MemSerialize& MemSerialize::operator&(const string& val)
{
	int len = val.length() + 1;
	memcpy(buf + offset, val.c_str(), len);
	offset += len;
	return *this;
}
MemSerialize& MemSerialize::operator&(string& val)
{
	int len = val.length() + 1;
	memcpy(buf + offset, val.c_str(), len);
	offset += len;
	return *this;
}