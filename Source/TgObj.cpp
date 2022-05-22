#include "TgObj.h"
#include <memory>

TgObj *TgPtr(void *data, const char* type_name) {
    auto *tgObj = (TgObj *) malloc(sizeof(TgObj));
    tgObj->type_name = type_name;
    tgObj->data = data;
    tgObj->size = sizeof(data);
    return tgObj;
}
TgObj *TgInt(int data) {
    auto *dataPtr = (int *) malloc(sizeof(int));
    *dataPtr = data;
    auto *tgObj = (TgObj *) malloc(sizeof(TgObj));
    tgObj->type_name = "int";
    tgObj->data = dataPtr;
    tgObj->size = sizeof(int);
    return tgObj;
}
TgObj *TgFloat(float data) {
    auto *dataPtr = (float *) malloc(sizeof(float));
    *dataPtr = data;
    auto *tgObj = (TgObj *) malloc(sizeof(TgObj));
    tgObj->type_name = "float";
    tgObj->data = dataPtr;
    tgObj->size = sizeof(float);
    return tgObj;
}
void TgDestroy(TgObj *tgObj) {
    free(tgObj->data);
    free(tgObj);
}
