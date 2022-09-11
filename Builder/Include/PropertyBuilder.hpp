#ifndef TANGARA_PROPERTYBUILDER_HPP
#define TANGARA_PROPERTYBUILDER_HPP
#include <string>
#include "IPropGetImpl.hpp"
#include "IPropSetImpl.hpp"
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
            _accessGet = access;
            _accessSet = access;
            return *this;
        }
        PropertyBuilder &SetGetAccess(tgAccessModifier access) {
            _accessGet = access;
            return *this;
        }
        PropertyBuilder &SetSetAccess(tgAccessModifier access) {
            _accessSet = access;
            return *this;
        }
        PropertyBuilder &Set(const IPropSetImpl &impl) {
            _isFinal = false;
            _setImpl = impl;
            return *this;
        }
        PropertyBuilder &Init(const IPropSetImpl &impl) {
            _isFinal = true;
            _setImpl = impl;
            return *this;
        }
        PropertyBuilder &Get(const IPropGetImpl &impl) {
            _getImpl = impl;
            return *this;
        }

        TBuilder &Build() {
            tgPropGetFuncPtr getImpl = _getImpl.GetImplementaion();
            if (!getImpl && _kind != MethodKind_Abstract) {
                // 11 is "_propField_" and 1 is '\0'
                size_t nameSize = (_name.length() + 12) * sizeof(char);
                char* fieldName = (char*) malloc(nameSize);
                sprintf_s(fieldName, nameSize, "_propField_%s", _name.c_str());
                _builder->CreateField(fieldName, _type)
                    .SetAccess(AccessModifier_Private)
                    .Build();
                // TODO: create function where we set and get this field
            }
            tgProp result = {CopyFromStr(_name), _type, _kind,
                             _getImpl.GetCustomObject(),
                             _accessGet, getImpl,
                             _accessSet, _setImpl.GetImplementaion(), _isFinal};
            _builder->AppendProp(result);
            return *_builder;
        }
    private:
        std::string _name;
        tgTypeRef _type;
        tgAccessModifier _accessGet = AccessModifier_Public;
        tgAccessModifier _accessSet = AccessModifier_Public;
        IPropSetImpl _setImpl;
        IPropGetImpl _getImpl;
        bool _isFinal = false;
        tgMethodKind _kind = MethodKind_Default;

        TBuilder* _builder;
    };
} // Tangara

#endif //TANGARA_PROPERTYBUILDER_HPP
