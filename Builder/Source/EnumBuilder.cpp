#include "EnumBuilder.hpp"
#include "Utils.hpp"
#include "TgValue.hpp"
#include "tg_funcs.h"

namespace Tangara {
    EnumBuilder::EnumBuilder(const char* name, EntryRule* rule, EntryBuilder& eb): _rule(rule), _entryBuilder(eb) {
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
        tgType* allocated_type = _entryBuilder.AppendType(result);
        for (uint i = 0; i < fields_count; i++) {
            allocated_type->fields[i].type.cached_type = allocated_type;
        }
        return *allocated_type;
    }

    EnumBuilder &EnumBuilder::SetAccess(tgAccessModifier am) {
        _access = am;
        RETURN_THIS()
    }

    EnumBuilder &EnumBuilder::Literal(const char *name) {
        tgField literal = {StrNewCpy((char*)name), tgCreateDirectTypeRef(nullptr), AccessModifier_Public,
                           FieldKind_Const, TgValue::UInt(_defaultValue++)};
        _entryBuilder.FieldArena.Append(literal);
        RETURN_THIS()
    }

    EnumBuilder::~EnumBuilder() = default;
}