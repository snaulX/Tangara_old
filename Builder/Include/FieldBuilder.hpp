#ifndef TANGARA_FIELDBUILDER_HPP
#define TANGARA_FIELDBUILDER_HPP
#include <string>
#include "tg_enums.h"
#include "tg_structs.h"
#include "tg_funcs.h"
#include "Utils.hpp"

namespace Tangara {
    template<typename TBuilder>
    struct FieldBuilder {
    public:
        FieldBuilder(const char* name, const tgTypeRef &type, TBuilder* builder)
        : _builder(builder), _name(name), _type(type)
        { }

        ~FieldBuilder() = default;

        FieldBuilder &SetAccess(tgAccessModifier modifier) {
            _access = modifier;
            return *this;
        }
        FieldBuilder &SetKind(tgFieldKind kind) {
            _kind = kind;
            return *this;
        }
        FieldBuilder &DefaultValue(const tgConstValue &value) {
            _defaultValue = value;
            return *this;
        }

        TBuilder &Build() {
            tgField f = {CopyFromStr(_name), _type, _access, _kind, _defaultValue};
            _builder->AppendField(f);
            return *_builder;
        }

    private:
        std::string _name;
        tgTypeRef _type;
        tgAccessModifier _access = AccessModifier_Private;
        tgFieldKind _kind = FieldKind_Default;
        tgConstValue _defaultValue = {ValueType_Null, nullptr};

        TBuilder* _builder;
    };

} // Tangara

#endif //TANGARA_FIELDBUILDER_HPP
