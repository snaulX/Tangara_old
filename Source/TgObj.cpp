#include "TgObj.h"
#include <memory>

TgObj *TgPtr(void *data, uint32_t type_hash) {
    auto *tgObj = (TgObj *) malloc(sizeof(TgObj));
    tgObj->type_hash = type_hash;
    tgObj->data = data;
    tgObj->size = sizeof(data);
    return tgObj;
}

void TgDestroy(TgObj *tgObj) {
    free(tgObj->data);
    free(tgObj);
}
