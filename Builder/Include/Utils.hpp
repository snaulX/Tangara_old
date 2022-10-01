#ifndef TANGARA_UTILS_HPP
#define TANGARA_UTILS_HPP
#include <string>
#include <vector>

namespace Tangara {
    char* CopyFromStr(const std::string& str);

    char* StrNewCpy(char* str);

    template<typename T>
    T* CopyFromVector(const std::vector<T> &vec) {
        size_t size = vec.size() * sizeof(T);
        T* result = (T*) malloc(size);
        memcpy_s(result, size, vec.data(), size);
        return result;
    }
}

#endif //TANGARA_UTILS_HPP
