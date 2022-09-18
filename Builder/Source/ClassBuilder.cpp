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
        _entryBuilder.FieldArena.Begin();
        _entryBuilder.MethodArena.Begin();
        _entryBuilder.PropArena.Begin();
        _entryBuilder.EventArena.Begin();
        _entryBuilder.CtorArena.Begin();
    }

    tgType ClassBuilder::Build() {
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
        size_t ctors_count = 0;
        tgCtor *ctors = nullptr;
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
        tgType result = {hash, name, _access, TypeKind_Class,
                         parents_count, CopyFromVector(_parents),
                         methods_count, methods,
                         ctors_count, ctors,
                         fields_count, fields,
                         props_count, props,
                         events_count, events};
        _parents.clear();
        _entryBuilder.AppendType(result);
        return result;
    }

    void ClassBuilder::AppendField(const tgField &field) {
        _entryBuilder.FieldArena.Append(field);
    }

    void ClassBuilder::AppendMethod(const tgMethod &method) {
        _entryBuilder.MethodArena.Append(method);
    }

    void ClassBuilder::AppendProp(const tgProp &prop) {
        _entryBuilder.PropArena.Append(prop);
    }

    void ClassBuilder::AppendEvent(const tgEvent &event) {
        _entryBuilder.EventArena.Append(event);
    }

    void ClassBuilder::AppendCtor(const tgCtor &ctor) {
        _entryBuilder.CtorArena.Append(ctor);
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

    ConstructorBuilder<ClassBuilder> ClassBuilder::CreateConstructor() {
        return {this};
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