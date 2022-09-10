#ifndef TANGARA_PROPERTYBUILDER_HPP
#define TANGARA_PROPERTYBUILDER_HPP
#include <string>
#include "tg_enums.h"
#include "tg_structs.h"
#include "tg_funcs.h"

namespace Tangara {
    template<typename TBuilder>
    struct PropertyBuilder {
    public:
        PropertyBuilder(const char* name, const tgTypeRef &type, TBuilder* builder)
                : _name(name), _type(type), _builder(builder)
        { }

        ~PropertyBuilder() = default;

        PropertyBuilder &SetKind(tgMethodKind kind) {
            _kind = kind;
            return *this;
        }
        PropertyBuilder &SetAccess(tgAccessModifier access) {
            _access = access;
            return *this;
        }

        TBuilder &Build() {
            tgProp result = {CopyFromStr(_name), _type, _kind,
                             nullptr,
                             AccessModifier_Public, nullptr,
                             AccessModifier_Public, nullptr, false};
            _builder->AppendProp(result);
            return *_builder;
        }
    private:
        std::string _name;
        tgTypeRef _type;
        tgAccessModifier _access = AccessModifier_Private;
        tgMethodKind _kind = MethodKind_Default;

        TBuilder* _builder;
    };
} // Tangara

#endif //TANGARA_PROPERTYBUILDER_HPP
