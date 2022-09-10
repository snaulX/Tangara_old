#include "EntryBuilder.hpp"
#include "ClassBuilder.hpp"
#include "Utils.hpp"

namespace Tangara {
    EntryBuilder::~EntryBuilder() = default;

    EntryBuilder::EntryBuilder(const char *entryName, Tangara::EntryRule *rule)
    : _name(entryName), _rule(rule) {

    }

    ClassBuilder EntryBuilder::CreateClass(const char *clName) {
        return {clName, _rule, *this};
    }

    tgEntry EntryBuilder::Build() {
        PropAllocator.Trim(); // free extra space
        EventAllocator.Trim();
        FieldAllocator.Trim();
        MethodAllocator.Trim();

        const char* name = CopyFromStr(_name);
        uint hash = XXHash32::hash(name, strlen(name), TG_ENTRY_SEED);
        _types.shrink_to_fit(); // free all allocated extra space in vector because we will not add new elements in further
        std::sort(_types.begin(), _types.end(), tgCompareTypes);
        tgEntry result = {hash, name, false,
                          _types.size(), CopyFromVector(_types),
                          FieldAllocator.GetLength(), FieldAllocator.GetRawData(),
                          PropAllocator.GetLength(), PropAllocator.GetRawData(),
                          MethodAllocator.GetLength(), MethodAllocator.GetRawData(),
                          EventAllocator.GetLength(), EventAllocator.GetRawData()};
        return result;
    }

    void EntryBuilder::AppendType(const tgType &type) {
        _types.push_back(type);
    }
}