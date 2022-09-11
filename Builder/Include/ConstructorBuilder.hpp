#ifndef TANGARA_CONSTRUCTORBUILDER_HPP
#define TANGARA_CONSTRUCTORBUILDER_HPP

#include "tg_structs.h"
#include "tg_funcs.h"
#include "IMethodImpl.hpp"
#include "ParameterBuilder.hpp"
#include "ICtorImpl.hpp"

namespace Tangara {

    template<typename TBuilder>
    class ConstructorBuilder {
    public:
        ConstructorBuilder(TBuilder* builder) : _builder(builder)
        { }

        ~ConstructorBuilder() = default;

        ConstructorBuilder &Implementation(const ICtorImpl& impl) {
            _impl = impl;
            return *this;
        }
        ParameterBuilder<ConstructorBuilder> Params() {
            return ParameterBuilder<ConstructorBuilder>(this);
        }
        ConstructorBuilder &SetAccess(tgAccessModifier modifier) {
            _access = modifier;
            return *this;
        }

        TBuilder &Build() {
            tgCtor ctor = {_params, _access, _impl.GetCustomObject(), _impl.GetImplementaion()};
            _builder->AppendCtor(ctor);
            return *_builder;
        }

        void SetParams(const tgParams& params) {
            _params = params;
        }
    private:
        tgAccessModifier _access = AccessModifier_Public;
        ICtorImpl _impl;
        tgParams _params{};

        TBuilder* _builder;
    };

} // Tangara

#endif //TANGARA_CONSTRUCTORBUILDER_HPP
