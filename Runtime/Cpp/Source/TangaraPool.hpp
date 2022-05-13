#ifndef TANGARA_TANGARAPOOL_HPP
#define TANGARA_TANGARAPOOL_HPP
#include "Entry.hpp"

enum class TangaraDefineType {
    None,
    Interface,
    Class,
};

class TangaraPool {
public:
    static TangaraPool* Instance;

    TangaraPool();

    ~TangaraPool();

    void CreateInterface(const char* name);
    void CreateClass(const char* name);

    [[nodiscard]] Tangara::Entry* GetEntry() const { return entry; }
private:
    TangaraDefineType type;
    Tangara::Entry* entry;
};


#endif //TANGARA_TANGARAPOOL_HPP
