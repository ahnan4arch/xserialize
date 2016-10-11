#pragma once
#include <string>
#include <fstream>
using namespace std;
class FileSerialize
{
public:
	FileSerialize(const char* fileName);
	FileSerialize(std::string& fileName);
	~FileSerialize();

	FileSerialize& operator &(const int& val);
	FileSerialize& operator &(int& val);
	FileSerialize& operator &(const char* val);
	FileSerialize& operator &(const string& val);
	FileSerialize& operator &(string& val);

	void BeginObject();
	void EndObject();
	void BeginArray();
	void EndArray();
private:
	void Format();
	std::ofstream ofs;
	int indent;
};

