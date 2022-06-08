#include <iostream>
#include "MyClass.hpp"
#include "Entry.hpp"
#include "TgStd.h"
#include "Utils.hpp"

using namespace Tangara;

int main()
{
    auto* entry = (Entry*)tgLoadEntry();
    Class *cl = entry->GetClass("EnigmaLabs.MyClass");
    TgObj *obj = cl->New(Tangara::EmptyParams());
    TgObj* params[] = {TgInt(10)};
    cl->Run(obj, "SetNumb", {1, params});
    TgObj* nameParams[] = {TgStr("Alex")};
    cl->Run(obj, "Greetings", {1, nameParams});
    TgObj *tgNumb = cl->Run(obj, "GetNumb", Tangara::EmptyParams());
    std::cout << *((int*)tgNumb->data) << std::endl;

    Class *snaulx = entry->GetClass("Snaulx");
    TgObj *snaulxParams[] = {TgStr("Sanya")};
    TgObj *snObj = snaulx->New({1, snaulxParams});
    TgObj *clParams[] = {TgMakePtr(obj)};
    snaulx->Run(snObj, "PrintName", {1, clParams});
}