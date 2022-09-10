#ifndef TANGARA_PARAMETERBUILDER_HPP
#define TANGARA_PARAMETERBUILDER_HPP

namespace Tangara {
    template<typename TBuilder>
    struct ParameterBuilder {
    public:
        explicit ParameterBuilder(TBuilder* builder) : _builder(builder) { }

        ~ParameterBuilder() = default;

        ParameterBuilder &Param(const char* name, const tgTypeRef &type, const tgConstValue& value = _emptyValue) {
            AddParam(name, type, value, ParamKind_Default);
            return *this;
        }
        ParameterBuilder &Params(const char* name, const tgTypeRef &type, const tgConstValue& value = _emptyValue) {
            AddParam(name, type, value, ParamKind_Params);
            return *this;
        }
        ParameterBuilder &Out(const char* name, const tgTypeRef &type, const tgConstValue& value = _emptyValue) {
            AddParam(name, type, value, ParamKind_Out);
            return *this;
        }
        ParameterBuilder &In(const char* name, const tgTypeRef &type, const tgConstValue& value = _emptyValue) {
            AddParam(name, type, value, ParamKind_In);
            return *this;
        }
        ParameterBuilder &Ref(const char* name, const tgTypeRef &type, const tgConstValue& value = _emptyValue) {
            AddParam(name, type, value, ParamKind_Ref);
            return *this;
        }

        TBuilder &Build() {
            _types.shrink_to_fit(); // Free allocated and never used memory in vectors
            _names.shrink_to_fit();
            _kinds.shrink_to_fit();
            _values.shrink_to_fit();

            tgParams params = {_types.size(), CopyFromVector(_types), CopyFromVector(_names),
                               CopyFromVector(_kinds), CopyFromVector(_values)};
            _builder->SetParams(params);
            return *_builder;
        }

    private:
        constexpr static tgConstValue _emptyValue = {ValueType_Null, nullptr};

        std::vector<tgTypeRef> _types;
        std::vector<const char*> _names;
        std::vector<tgParamKind> _kinds;
        std::vector<tgConstValue> _values;

        TBuilder* _builder;

        inline void AddParam(const char* name, const tgTypeRef &type, const tgConstValue& value, tgParamKind kind) {
            _names.push_back(name);
            _types.push_back(type);
            _values.push_back(value);
            _kinds.push_back(kind);
        }
    };

} // Tangara

#endif //TANGARA_PARAMETERBUILDER_HPP
