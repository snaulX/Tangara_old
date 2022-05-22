#include "TgObj.h"
#include <memory>

TgObj *TgPtr(void *data, uint32_t type_hash) {
    auto *tgObj = (TgObj *) malloc(sizeof(TgObj));
    tgObj->type_hash = type_hash;
    tgObj->data = data;
    tgObj->size = sizeof(data);
    return tgObj;
}
TgObj *TgNull() {
    return TgPtr(nullptr, "void");
}
TgObj *TgInt(int data) {
    auto *dataPtr = (int *) malloc(sizeof(int));
    *dataPtr = data;
    auto *tgObj = (TgObj *) malloc(sizeof(TgObj));
    tgObj->type_hash = "int";
    tgObj->data = dataPtr;
    tgObj->size = sizeof(int);
    return tgObj;
}
TgObj *TgFloat(float data) {
    auto *dataPtr = (float *) malloc(sizeof(float));
    *dataPtr = data;
    auto *tgObj = (TgObj *) malloc(sizeof(TgObj));
    tgObj->type_hash = "float";
    tgObj->data = dataPtr;
    tgObj->size = sizeof(float);
    return tgObj;
}
void TgDestroy(TgObj *tgObj) {
    free(tgObj->data);
    free(tgObj);
}
