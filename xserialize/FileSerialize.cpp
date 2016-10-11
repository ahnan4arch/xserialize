#include "FileSerialize.h"


FileSerialize::FileSerialize(const char* fileName) :ofs(fileName), indent(-1)
{
	ofs.fill('\t');
}

FileSerialize::FileSerialize(std::string& fileName):ofs(fileName.c_str()), indent(-1)
{
	ofs.fill('\t');
}


FileSerialize::~FileSerialize()
{
}

FileSerialize & FileSerialize::operator&(const int & val)
{
	Format();
	ofs << val
		<<std::endl;
	return *this;
}
FileSerialize & FileSerialize::operator&(int & val)
{
	Format();
	ofs << val
		<< std::endl;
	return *this;
}
FileSerialize & FileSerialize::operator&(const char * val)
{
	Format();
	ofs << *val
		<<std::endl;
	return *this;
}

FileSerialize & FileSerialize::operator&(const string & val)
{
	Format();
	ofs << val
		<<std::endl;
	return *this;
}
FileSerialize & FileSerialize::operator&(string & val)
{
	Format();
	ofs << val
		<< std::endl;
	return *this;
}

void FileSerialize::BeginObject()
{
	Format();
	indent++;	
	ofs << "{" << std::endl;
}

void FileSerialize::EndObject()
{
	indent--;
	Format();
	ofs << "}" << std::endl;
}
void FileSerialize::BeginArray()
{
	indent++;
	Format();
	ofs << "[" << std::endl;
}

void FileSerialize::EndArray()
{
	Format();
	ofs << "]" << std::endl;
	indent--;
}

void FileSerialize::Format()
{
	for (int i = 0; i < indent; i++)
	{
		ofs << '\t';
	}
}
