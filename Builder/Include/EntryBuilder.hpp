#ifndef TANGARA_ENTRYBUILDER_HPP
#define TANGARA_ENTRYBUILDER_HPP
#include <algorithm>
#include "EntryArena.hpp"
#include "EntryRule.hpp"
#include "tg_structs.h"
#include "xxhash/xxhash32.h"
#include "tgbase.h"

namespace Tangara {
    struct ClassBuilder;
    struct StructBuilder;
    struct EnumBuilder;

    struct EntryBuilder {
    public:
        EntryBuilder(const char *entryName, EntryRule *rule);

        ~EntryBuilder();

        ClassBuilder CreateClass(const char* clName);
        ClassBuilder CreateFinalClass(const char* clName);
        StructBuilder CreateStruct(const char* stName);
        EnumBuilder CreateEnum(const char* enName);
        tgEntry Build();

        tgType* AppendType(const tgType& type);

        EntryArena<tgField> FieldArena;
        EntryArena<tgProp> PropArena;
        EntryArena<tgEvent> EventArena;
        EntryArena<tgMethod> MethodArena;
        EntryArena<tgCtor> CtorArena;
    private:
        std::string _name;
        EntryRule* _rule;

        std::vector<tgType> _types;
    };

} // Tangara

#endif //TANGARA_ENTRYBUILDER_HPP
