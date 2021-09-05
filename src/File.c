#include "File.h"

FILE* open_write(const char* file_name)
{
	FILE* fp = fopen(file_name, "wb");
	if (fp == NULL)
	{
		perror("File not found");
	}
	return fp;
}
void close_file(FILE* file)
{
	fclose(file);
}
void write_class(FILE* file, Class cl)
{
	fwrite(&cl, CLASS_SIZE, 1, file);
}
void write_func(FILE* file, Func func)
{
	fwrite(&func, FUNC_SIZE, 1, file);
}
void write_var(FILE* file, Var var)
{
	fwrite(&var, VAR_SIZE, 1, file);
}

FILE* open_read(const char* file_name)
{
	FILE* fp = fopen(file_name, "rb");
	if (fp == NULL)
	{
		perror("File not found");
	}
	return fp;
}
void read_class(FILE* file, Class* cl)
{
	fread(cl, CLASS_SIZE, 1, file);
}

void write_class_block(FILE* file, ClassBlock* classBlock)
{
    //fwrite(classBlock->classes, CLASS_SIZE, classBlock->count, file);
    fwrite(classBlock, sizeof(ClassBlock), 1, file);
}
void read_class_block(FILE* file, ClassBlock* classBlock)
{
    //fread(classBlock->classes, CLASS_SIZE, classBlock->count, file);
    fread(classBlock, sizeof(ClassBlock), 1, file);
}
