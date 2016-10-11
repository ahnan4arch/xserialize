#pragma once
#include <cstring>
#include <string>
#include "BaseArchive.h"

using namespace std;
namespace xutil
{
	class MemSerialize :
		public ArchiveBase
	{
	public:
		~MemSerialize();

		MemSerialize(char* buffer);

		MemSerialize& operator &(const int& val);
		MemSerialize& operator &(int& val);

		MemSerialize& operator &(const char* val);

		MemSerialize& operator &(const string& val);
		MemSerialize& operator &(string& val);
	};
}
