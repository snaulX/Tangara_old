#include "File.h"

FILE* tgOpenWrite(const char* file_name)
{
	FILE* fp = fopen(file_name, "wb, ccs=UTF-8");
	if (fp == NULL)
	{
		perror("File not found");
	}
	return fp;
}
void tgCloseFile(FILE* file)
{
	fclose(file);
}

FILE* tgOpenRead(const char* file_name)
{
	FILE* fp = fopen(file_name, "rb, ccs=UTF-8");
	if (fp == NULL)
	{
		perror("File not found");
	}
	return fp;
}
