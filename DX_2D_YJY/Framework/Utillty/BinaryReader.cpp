#include "framework.h"
#include "BinaryReader.h"

BinaryReader::BinaryReader(wstring filePath)
	:_size(0)
{
	_file = CreateFile(filePath.c_str(), GENERIC_READ, FILE_SHARE_READ,
		0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);
}

BinaryReader::~BinaryReader()
{
	CloseHandle(_file);
}

int BinaryReader::Int()
{
	int temp;
	assert(ReadFile(_file, &temp, sizeof(int), OUT & _size, nullptr));

	return temp;
}

UINT BinaryReader::Uint()
{
	UINT temp;
	assert(ReadFile(_file, &temp, sizeof(UINT), OUT & _size, nullptr));

	return temp;
}

float BinaryReader::Float()
{
	float temp;
	assert(ReadFile(_file, &temp, sizeof(float), OUT & _size, nullptr));

	return temp;
}

string BinaryReader::String()
{
	UINT size = Uint();

	char* temp = new char[size + 1];
	assert(ReadFile(_file, temp, sizeof(char) * size, OUT & _size, nullptr));

	return temp;
}


void BinaryReader::Byte(void** data, UINT dataSize)
{
	assert(ReadFile(_file, *data, dataSize, OUT & _size, nullptr));
}
