#include "MemDeSerialize.h"


using namespace xutil;

xutil::MemDeSerialize::MemDeSerialize(char * buffer)
{
	this->buf = buffer;
	this->bufLen = strlen(buffer) + 1;
}

MemDeSerialize::~MemDeSerialize()
{
}
MemDeSerialize& MemDeSerialize::operator &(int& val)
{
	int* pData = (int*)(buf + offset);
	val = *pData;
	offset += sizeof(int);
	return *this;
}
MemDeSerialize& MemDeSerialize::operator &(char* val)
{
	int len = strlen(buf + offset) + 1;
	memcpy(val, buf + offset, len);
	offset += len;
	return *this;
}
MemDeSerialize& MemDeSerialize::operator &(string& val)
{
	int len = strlen(buf + offset) + 1;
	val.assign(buf + offset);
	offset += len;
	return *this;
}