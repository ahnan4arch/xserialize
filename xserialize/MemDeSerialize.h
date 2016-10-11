#pragma once
#include <cstring>
#include <string>
#include "BaseArchive.h"

using namespace std;
namespace xutil
{
	class MemDeSerialize :
		public ArchiveBase
	{
	public:
		MemDeSerialize(char* buffer);
		~MemDeSerialize();

		MemDeSerialize& operator &(int& val);
		
		MemDeSerialize& operator &(char* val);
		
		MemDeSerialize& operator &(string& val);		
	};
}