#include "EnumBuilder.hpp"
#include "Utils.hpp"

namespace Tangara {
    EnumBuilder::EnumBuilder(const char* name, EntryRule* rule, EntryBuilder& eb): _entryBuilder(eb) {
        if (rule) {
            _name = rule->GetTypeName(name);
            _access = rule->GetTypeAccess();
        } else {
            _name = name;
        }
        _entryBuilder.FieldArena.Begin();
    }

    tgType EnumBuilder::Build() {
        size_t fields_count = 0;
        tgField *fields = nullptr;
        _entryBuilder.FieldArena.End(&fields, fields_count);

        char* name = CopyFromStr(_name);
        uint hash = XXHash32::hash(name, strlen(name), TG_TYPE_SEED);
        tgType result = {hash, name, _access, TypeKind_Enum,
                         0, nullptr, // parents
                         0, nullptr, //methods
                         0, nullptr, // ctors
                         fields_count, fields,
                         0, nullptr, // props
                         0, nullptr // events
                         };
        return result;
    }

    EnumBuilder &EnumBuilder::SetAccess(tgAccessModifier am) {
        _access = am;
        RETURN_THIS()
    }

    EnumBuilder &EnumBuilder::Literal(const char *name) {
        //tgField literal = {StrNewCpy(name), type};
        //_entryBuilder.FieldArena.Append(literal);
        RETURN_THIS()
    }

    EnumBuilder::~EnumBuilder() = default;
}