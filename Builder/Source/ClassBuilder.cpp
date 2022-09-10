#include "ClassBuilder.hpp"
#include "xxhash/xxhash32.h"
#include "tgbase.h"
#include "Utils.hpp"

namespace Tangara {
    ClassBuilder::ClassBuilder(const char* name, EntryRule* rule, EntryBuilder& eb) : _rule(rule)
    , _entryBuilder(eb) {
        if (rule) {
            _name = rule->GetTypeName(name);
            _access = rule->GetTypeAccess();
        } else {
            _name = name;
        }
        _entryBuilder.FieldAllocator.Begin();
        _entryBuilder.MethodAllocator.Begin();
        _entryBuilder.PropAllocator.Begin();
        _entryBuilder.EventAllocator.Begin();
    }

    tgType ClassBuilder::Build() {
        // Fields
        size_t fields_count = 0;
        tgField *fields = nullptr;
        _entryBuilder.FieldAllocator.End(&fields, fields_count);
        // Methods
        size_t methods_count = 0;
        tgMethod *methods = nullptr;
        _entryBuilder.MethodAllocator.End(&methods, methods_count);
        // Parents
        size_t parents_count = _parents.size();
        size_t parents_size = parents_count * sizeof(tgTypeRef);
        tgTypeRef *parents = (tgTypeRef*)malloc(parents_size);
        memcpy_s(parents, parents_size, _parents.data(), parents_size);
        _parents.clear(); // remove all data from vector
        _parents.shrink_to_fit(); // free all allocated memory
        // Constructors
        size_t ctors_count = 0;
        tgCtor *ctors = nullptr;
        // Properties
        size_t props_count = 0;
        tgProp *props = nullptr;
        _entryBuilder.PropAllocator.End(&props, props_count);
        // Events
        size_t events_count = 0;
        tgEvent *events = nullptr;
        _entryBuilder.EventAllocator.End(&events, events_count);
        // Last code
        const char* name = CopyFromStr(_name);
        uint hash = XXHash32::hash(name, strlen(name), TG_TYPE_SEED);
        tgType result = {hash, name, _access, TypeKind_Class,
                         parents_count, parents,
                         methods_count, methods,
                         ctors_count, ctors,
                         fields_count, fields,
                         props_count, props,
                         events_count, events};
        _entryBuilder.AppendType(result);
        return result;
    }

    void ClassBuilder::AppendField(const tgField &field) {
        _entryBuilder.FieldAllocator.Append(field);
    }

    void ClassBuilder::AppendMethod(const tgMethod &method) {
        _entryBuilder.MethodAllocator.Append(method);
    }

    void ClassBuilder::AppendProp(const tgProp &prop) {
        _entryBuilder.PropAllocator.Append(prop);
    }

    void ClassBuilder::AppendEvent(const tgEvent &event) {
        _entryBuilder.EventAllocator.Append(event);
    }

    FieldBuilder<ClassBuilder> ClassBuilder::CreateField(const char *name, const tgTypeRef &type) {
        return {name, type, this};
    }

    PropertyBuilder<ClassBuilder> ClassBuilder::CreateProperty(const char *name, const tgTypeRef &type) {
        return {name, type, this};
    }

    MethodBuilder<ClassBuilder> ClassBuilder::CreateMethod(const char *name) {
        return {name, this};
    }

    ClassBuilder &ClassBuilder::SetAccess(tgAccessModifier am) {
        _access = am;
        return *this;
    }

    ClassBuilder &ClassBuilder::Inherits(const tgTypeRef &type) {
        _parents.push_back(type);
        return *this;
    }

    ClassBuilder::~ClassBuilder() = default;
}