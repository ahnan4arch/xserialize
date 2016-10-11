#pragma once
#include <string>
#include <map>
#include <vector>
#include <typeinfo>
#include "MemSerialize.h"
#include "MemDeSerialize.h"
#include "FileSerialize.h"

using namespace std;
using namespace xutil;

template<class Archive, class TObject>
void xserialize(Archive& archive, TObject& val);
/*template<class Archive, class TObject>
void xserialize(Archive& archive, TObject val)
{
	string msg;
	msg += "the ";
	msg += typeid(val).name();
	msg += " does not define the xserialize method";
	throw runtime_error(msg.c_str());
}*/

template<class Archive,class TObject>
Archive& operator&(Archive& archive, TObject& val)
{
	xserialize(archive, val);
	return archive;
}

template<class Archive, class TObject>
Archive& operator&(Archive& archive, const TObject& val)
{
	archive & const_cast<TObject&>(val);
	return archive;
}

template<class TObject>
MemSerialize& operator&(MemSerialize& archive, std::vector<TObject>& val)
{
	int size = val.size();
	archive & size;
	for (int i = 0; i < size; i++)
	{
		archive & val[i];
	}
	return archive;
}
template<class TObject>
MemDeSerialize& operator&(MemDeSerialize& archive, std::vector<TObject>& val)
{
	int size = 0;
	archive & size;
	for (int i = 0; i < size; i++)
	{
		TObject obj;
		archive & obj;
		val.push_back(obj);
	}
	return archive;
}
template<class TKEY, class TObject>
MemSerialize& operator&(MemSerialize& archive, std::map<TKEY, TObject>& val)
{
	int size = val.size();
	archive & size;
	for (typename std::map<TKEY, TObject>::iterator it = val.begin(); it != val.end(); it++)
	{
		archive & it->first;
		archive & it->second;
	}
	return archive;
}
template<class TKEY, class TObject>
MemDeSerialize& operator&(MemDeSerialize& archive, std::map<TKEY, TObject>& val)
{
	int size = 0;
	archive & size;
	for (int i = 0; i < size; i++)
	{
		TKEY key;
		TObject obj;
		archive & key;
		archive & obj;
		val.insert(make_pair( key, obj));
	}
	return archive;
}
template<class TObject>
FileSerialize& operator&(FileSerialize& archive, TObject& val)
{
	archive.BeginObject();
	xserialize(archive, val);
	archive.EndObject();
	return archive;
}
template<class TObject>
FileSerialize& operator&(FileSerialize& archive, std::vector<TObject>& val)
{
	int size = val.size();
	archive.BeginArray();
	for (int i = 0; i < size; i++)
	{
		archive & val[i];
	}
	archive.EndArray();
	return archive;
}