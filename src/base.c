#include "base.h"

Data* _getDataFromArrayData(ArrayData arr, unsigned index)
{
    if (index >= arr.count)
        err("Index greater or equals then length of array")
    return &arr.data[index];
}
