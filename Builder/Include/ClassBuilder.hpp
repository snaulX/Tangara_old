#ifndef TANGARA_CLASSBUILDER_HPP
#define TANGARA_CLASSBUILDER_HPP
#include <string>
#include <vector>
#include "EntryRule.hpp"
#include "FieldBuilder.hpp"
#include "EntryBuilder.hpp"
#include "PropertyBuilder.hpp"
#include "MethodBuilder.hpp"
#include "ConstructorBuilder.hpp"

namespace Tangara {
    struct ClassBuilder {
    public:
        ClassBuilder(const char* name, EntryRule* rule, EntryBuilder& eb);

        ~ClassBuilder();

        FieldBuilder<ClassBuilder> CreateField(const char* name, const tgTypeRef &type);
        PropertyBuilder<ClassBuilder> CreateProperty(const char *name, const tgTypeRef &type);
        MethodBuilder<ClassBuilder> CreateMethod(const char *name);
        ConstructorBuilder<ClassBuilder> CreateConstructor();
        ClassBuilder &SetAccess(tgAccessModifier am);
        ClassBuilder &Inherits(const tgTypeRef &type);
        tgType Build();

        void AppendProp(const tgProp &prop);
        void AppendEvent(const tgEvent &event);
        void AppendField(const tgField &field);
        void AppendMethod(const tgMethod &method);
        void AppendCtor(const tgCtor &ctor);
    private:
        EntryRule* _rule;

        std::vector<tgTypeRef> _parents;
        std::string _name;
        tgAccessModifier _access = AccessModifier_Internal;
        EntryBuilder& _entryBuilder;
    };

} // Tangara

#endif //TANGARA_CLASSBUILDER_HPP
