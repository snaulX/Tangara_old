#include "EntryBuilder.hpp"
#include "ClassBuilder.hpp"
#include "StructBuilder.hpp"
#include "Utils.hpp"

namespace Tangara {
    EntryBuilder::~EntryBuilder() = default;

    EntryBuilder::EntryBuilder(const char *entryName, Tangara::EntryRule *rule)
    : _name(entryName), _rule(rule) {

    }

    ClassBuilder EntryBuilder::CreateClass(const char *clName) {
        return {clName, _rule, *this};
    }


    ClassBuilder EntryBuilder::CreateFinalClass(const char *clName) {
        ClassBuilder cb = {clName, _rule, *this};
        cb.SetFinal();
        return cb;
    }

    tgEntry EntryBuilder::Build() {
        PropArena.Trim(); // free extra space
        EventArena.Trim();
        FieldArena.Trim();
        MethodArena.Trim();
        CtorArena.Trim();

        const char* name = CopyFromStr(_name);
        uint hash = XXHash32::hash(name, strlen(name), TG_ENTRY_SEED);
        _types.shrink_to_fit(); // free all allocated extra space in vector because we will not add new elements in further
        std::sort(_types.begin(), _types.end(), tgCompareTypes);
        tgEntry result = {hash, name, false,
                          _types.size(), CopyFromVector(_types),
                          FieldArena.GetLength(), FieldArena.GetRawData(),
                          PropArena.GetLength(), PropArena.GetRawData(),
                          MethodArena.GetLength(), MethodArena.GetRawData(),
                          EventArena.GetLength(), EventArena.GetRawData(),
                          CtorArena.GetLength(), CtorArena.GetRawData()};
        return result;
    }

    tgType* EntryBuilder::AppendType(const tgType &type) {
        _types.push_back(type);
        return &_types.back();
    }

    StructBuilder EntryBuilder::CreateStruct(const char *stName) {
        return {stName, _rule, *this};
    }
}