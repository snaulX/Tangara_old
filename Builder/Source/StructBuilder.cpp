#include "StructBuilder.hpp"
#include "xxhash/xxhash32.h"
#include "tgbase.h"
#include "Utils.hpp"

namespace Tangara {
    static tgObject* emptyCtorImpl(size_t, tgObject*, void *custom_type) {
        auto* result = (tgObject*) malloc(sizeof(tgObject));
        result->type = (tgType*) custom_type;
        result->data_size = 0;
        result->data = nullptr;
        return result;
    }

    StructBuilder::StructBuilder(const char* name, EntryRule* rule, EntryBuilder& eb) : _rule(rule)
            , _entryBuilder(eb) {
        if (rule) {
            _name = rule->GetTypeName(name);
            _access = rule->GetTypeAccess();
        } else {
            _name = name;
        }
        _entryBuilder.FieldArena.Begin();
        _entryBuilder.MethodArena.Begin();
        _entryBuilder.PropArena.Begin();
        _entryBuilder.EventArena.Begin();
        _entryBuilder.CtorArena.Begin();
    }

    tgType StructBuilder::Build() {
        // Fields
        size_t fields_count = 0;
        tgField *fields = nullptr;
        _entryBuilder.FieldArena.End(&fields, fields_count);
        // Methods
        size_t methods_count = 0;
        tgMethod *methods = nullptr;
        _entryBuilder.MethodArena.End(&methods, methods_count);
        // Parents
        size_t parents_count = _parents.size();
        // Constructors
        auto* ctor_arena = &_entryBuilder.CtorArena;
        size_t ctors_count = ctor_arena->GetCount();
        tgCtor *ctors = nullptr;
        bool has_empty_ctor = false;
        for (int i = 0; i < ctors_count; i++) {
            tgCtor* ctor = &ctor_arena->GetRawData()[ctor_arena->GetLength()-ctors_count];
            if (ctor->params.params_count == 0) {
                has_empty_ctor = true;
                break;
            }
        }
        tgCtor *empty_ctor_ptr = nullptr;
        if (!has_empty_ctor) {
            tgParams empty_params = {0, nullptr, nullptr, nullptr, nullptr};
            tgCtor empty_ctor = {empty_params, AccessModifier_Public, nullptr, &emptyCtorImpl};
            empty_ctor_ptr = ctor_arena->Append(empty_ctor);
        }
        _entryBuilder.CtorArena.End(&ctors, ctors_count);
        // Properties
        size_t props_count = 0;
        tgProp *props = nullptr;
        _entryBuilder.PropArena.End(&props, props_count);
        // Events
        size_t events_count = 0;
        tgEvent *events = nullptr;
        _entryBuilder.EventArena.End(&events, events_count);
        // Last code
        const char* name = CopyFromStr(_name);
        uint hash = XXHash32::hash(name, strlen(name), TG_TYPE_SEED);
        tgType result = {hash, name, _access, TypeKind_Struct,
                         parents_count, CopyFromVector(_parents),
                         methods_count, methods,
                         ctors_count, ctors,
                         fields_count, fields,
                         props_count, props,
                         events_count, events};
        _parents.clear();
        if (empty_ctor_ptr) {
            tgType *type_in_entry = _entryBuilder.AppendType(result);
            empty_ctor_ptr->userptr = type_in_entry;
        }
        else {
            _entryBuilder.AppendType(result);
        }
        return result;
    }

    void StructBuilder::AppendField(const tgField &field) {
        _entryBuilder.FieldArena.Append(field);
    }

    void StructBuilder::AppendMethod(const tgMethod &method) {
        _entryBuilder.MethodArena.Append(method);
    }

    void StructBuilder::AppendProp(const tgProp &prop) {
        _entryBuilder.PropArena.Append(prop);
    }

    void StructBuilder::AppendEvent(const tgEvent &event) {
        _entryBuilder.EventArena.Append(event);
    }

    void StructBuilder::AppendCtor(const tgCtor &ctor) {
        _entryBuilder.CtorArena.Append(ctor);
    }

    FieldBuilder<StructBuilder> StructBuilder::CreateField(const char *name, const tgTypeRef &type) {
        return {name, type, this};
    }

    PropertyBuilder<StructBuilder> StructBuilder::CreateProperty(const char *name, const tgTypeRef &type) {
        return {name, type, this};
    }

    MethodBuilder<StructBuilder> StructBuilder::CreateMethod(const char *name) {
        return {name, this};
    }

    ConstructorBuilder<StructBuilder> StructBuilder::CreateConstructor() {
        return {this};
    }

    StructBuilder &StructBuilder::SetAccess(tgAccessModifier am) {
        _access = am;
        return *this;
    }

    StructBuilder &StructBuilder::Inherits(const tgTypeRef &type) {
        _parents.push_back(type);
        return *this;
    }

    StructBuilder::~StructBuilder() = default;
}