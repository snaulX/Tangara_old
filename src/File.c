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

void tgWriteClassBlock(FILE* file, TgClassBlock* classBlock)
{
    //fwrite(classBlock->classes, CLASS_SIZE, classBlock->count, file);
    fwrite(classBlock, sizeof(TgClassBlock), 1, file);
}
void tgReadClassBlock(FILE* file, TgClassBlock* classBlock)
{
    //fread(classBlock->classes, CLASS_SIZE, classBlock->count, file);
    fread(classBlock, sizeof(TgClassBlock), 1, file);
}
