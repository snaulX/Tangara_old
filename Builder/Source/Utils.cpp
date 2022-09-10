#include "Utils.hpp"

namespace Tangara {
    char* CopyFromStr(const std::string& str) {
        size_t str_size = (str.length() + 1) * sizeof(char);
        char* result = (char*) malloc(str_size);
        strcpy_s(result, str_size, str.c_str());
        //str.copy(result, str_size-1);
        //result[str_size-1] = '\0';
        return result;
    }
}
