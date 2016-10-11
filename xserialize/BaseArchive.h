#pragma once
namespace xutil
{
	class ArchiveBase
	{
	protected:
		int offset;
		int bufLen;
		char* buf;
		ArchiveBase() :offset(0), bufLen(0), buf(NULL)
		{
		}
	};
}