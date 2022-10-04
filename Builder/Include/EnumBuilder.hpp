#ifndef TANGARA_ENUMBUILDER_HPP
#define TANGARA_ENUMBUILDER_HPP
#include "EntryBuilder.hpp"

namespace Tangara {

    class EnumBuilder {
    public:
        EnumBuilder(const char* name, EntryRule* rule, EntryBuilder& eb);

        ~EnumBuilder();

        EnumBuilder &SetAccess(tgAccessModifier am);
        EnumBuilder &Literal(const char* name);
        tgType Build();
    private:
        EntryRule* _rule;

        std::string _name;
        tgAccessModifier _access = AccessModifier_Internal;
        EntryBuilder& _entryBuilder;

        uint32_t _defaultValue = 0;
    };

} // Tangara

#endif //TANGARA_ENUMBUILDER_HPP
