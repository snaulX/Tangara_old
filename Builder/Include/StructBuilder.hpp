#ifndef TANGARA_STRUCTBUILDER_HPP
#define TANGARA_STRUCTBUILDER_HPP
#include <string>
#include <vector>
#include "EntryRule.hpp"
#include "FieldBuilder.hpp"
#include "EntryBuilder.hpp"
#include "PropertyBuilder.hpp"
#include "MethodBuilder.hpp"
#include "ConstructorBuilder.hpp"

namespace Tangara {

    struct StructBuilder {
    public:
        StructBuilder(const char* name, EntryRule* rule, EntryBuilder& eb);

        ~StructBuilder();

        FieldBuilder<StructBuilder> CreateField(const char* name, const tgTypeRef &type);
        PropertyBuilder<StructBuilder> CreateProperty(const char *name, const tgTypeRef &type);
        MethodBuilder<StructBuilder> CreateMethod(const char *name);
        ConstructorBuilder<StructBuilder> CreateConstructor();
        StructBuilder &SetAccess(tgAccessModifier am);
        StructBuilder &Inherits(const tgTypeRef &type);
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

#endif //TANGARA_STRUCTBUILDER_HPP
