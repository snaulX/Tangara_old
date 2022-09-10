#ifndef TANGARA_ENTRYBUILDER_HPP
#define TANGARA_ENTRYBUILDER_HPP
#include <algorithm>
#include "EntryAllocator.hpp"
#include "EntryRule.hpp"
#include "tg_structs.h"
#include "xxhash/xxhash32.h"
#include "tgbase.h"

namespace Tangara {
    struct ClassBuilder;

    struct EntryBuilder {
    public:
        EntryBuilder(const char *entryName, EntryRule *rule);

        ~EntryBuilder();

        ClassBuilder CreateClass(const char* clName);
        tgEntry Build();

        void AppendType(const tgType& type);

        EntryAllocator<tgField> FieldAllocator;
        EntryAllocator<tgProp> PropAllocator;
        EntryAllocator<tgEvent> EventAllocator;
        EntryAllocator<tgMethod> MethodAllocator;
    private:
        std::string _name;
        EntryRule* _rule;

        std::vector<tgType> _types;
    };

} // Tangara

#endif //TANGARA_ENTRYBUILDER_HPP
