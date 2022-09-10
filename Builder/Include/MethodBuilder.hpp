#ifndef TANGARA_METHODBUILDER_HPP
#define TANGARA_METHODBUILDER_HPP

#include <string>
#include "tg_structs.h"
#include "tg_funcs.h"
#include "IMethodImpl.hpp"
#include "ParameterBuilder.hpp"

namespace Tangara {

    template<typename TBuilder>
    class MethodBuilder {
    public:
        MethodBuilder(const char* name, TBuilder* builder) : _name(name), _builder(builder)
        { }

        ~MethodBuilder() = default;

        MethodBuilder &Return(const tgTypeRef& type) {
            _returnType = type;
            return *this;
        }
        MethodBuilder &Implementation(const IMethodImpl& impl) {
            _impl = impl;
            return *this;
        }
        ParameterBuilder<MethodBuilder> Params() {
            return ParameterBuilder<MethodBuilder>(this);
        }
        MethodBuilder &SetAccess(tgAccessModifier modifier) {
            _access = modifier;
            return *this;
        }
        MethodBuilder &SetKind(tgMethodKind kind) {
            _kind = kind;
            return *this;
        }

        TBuilder &Build() {
            tgMethod method = {CopyFromStr(_name), _access, _kind,
                               _returnType, _params, 0, nullptr,
                               _impl.GetCustomObject(), _impl.GetImplementaion()};
            _builder->AppendMethod(method);
            return *_builder;
        }

        void SetParams(const tgParams& params) {
            _params = params;
        }
    private:
        std::string _name;
        tgTypeRef _returnType;
        tgAccessModifier _access = AccessModifier_Private;
        tgMethodKind _kind = MethodKind_Default;
        IMethodImpl _impl;
        tgParams _params{};

        TBuilder* _builder;
    };

} // Tangara

#endif //TANGARA_METHODBUILDER_HPP
