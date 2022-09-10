#include <cstdlib>
#include "EntryRule.hpp"
#include "EntryBuilder.hpp"
#include "ClassBuilder.hpp"
#include "NativeMethodImpl.hpp"
#include "TgRef.hpp"
#include "TgValue.hpp"

using namespace Tangara;

tgObject* EnigmaLabs_MyClass_Foo(tgObject *obj, size_t params_size, tgObject *params, void *custom_obj) {
    return nullptr;
}

int main()
{
    auto rule = EntryRule();
    rule.Namespace("EnigmaLabs");
    rule.TypeAccess(AccessModifier_Private);
    auto eb = EntryBuilder("EnigmaLabs", &rule);
    auto mct = eb.CreateClass("MyClass")
        .SetAccess(AccessModifier_Public)
        .CreateField("fieldName", TgRef("FieldType"))
            .SetAccess(AccessModifier_Internal)
            .Build()
        .CreateMethod("Foo")
            .Return(TgRef("TypeName"))
            .Params()
                .Param("paramName", TgRef("CString"), TgValue::CStr("default value"))
                .Build()
            .Implementation(NativeMethodImpl(&EnigmaLabs_MyClass_Foo))
            .Build()
        /*.CreateConstructor()
            .Params().Build()
            .Implementation(NativeCtorImpl(ptrOnCtorFunc))
            .Build()*/
        .CreateProperty("MyProp", TgRef("PropType")).Build()
        .Build();
    printf("Param value: \"%s\"\n", (char*)mct.methods[0].params.default_values[0].value);
    auto eerule = EntryRule(&rule);
    eerule.UsingNamespace("Enigma.Engine");
    //eerule.Enable();
    eb.CreateClass("MyEntity")
        .Inherits(TgRef("Entity"))
        .CreateProperty("ReloadTime", TgRef("int"))
            .SetKind(MethodKind_Static)
            //.SetAttribute("ConsoleVar", TgArgs(TgValue::CStr("reload_time")))
            .Build()
        .Build();
    //eerule.Disable();
    eerule.Free();
    tgEntry el = eb.Build();

    printf("Entry name %s\n", el.name);
    printf("Entry fields:\n");
    for (int j = 0; j < el.fields_size; ++j) {
        tgField f = el.fields[j];
        printf("%s %s with access %d and kind %d\n", (char*)f.type.ref_data,//tgResolveTypeRef(&f.type, &el)->name,
               f.name, f.access, f.kind);
    }
    for (int i = 0; i < el.types_size; ++i) {
        tgType t = el.types[i];
        printf("Type %s of kind %d and access %d\n", t.name, t.kind, t.access);
        printf("Fields:\n");
        for (int j = 0; j < t.fields_size; ++j) {
            tgField f = t.fields[j];
            printf("%s %s with access %d and kind %d\n", (char*)f.type.ref_data,//tgResolveTypeRef(&f.type, &el)->name,
                   f.name, f.access, f.kind);
        }
        printf("Properties:\n");
        for (int j = 0; j < t.props_size; ++j) {
            tgProp p = t.props[j];
            printf("%s %s with kind %d\n", (char*)p.type.ref_data,//tgResolveTypeRef(&p.type, &el)->name,
                   p.name, p.kind);
        }
    }
}
