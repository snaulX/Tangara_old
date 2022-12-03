#include "tgbuild_util.h"

char* combine_path(const char *path, const char *smth) {
    char *fpath = (char*)malloc(strlen(path)*sizeof(char) + strlen(smth)*sizeof(char) + 1 /* for '\'*/);
    sprintf(fpath, "%s\\%s", path, smth);
    return fpath;
}