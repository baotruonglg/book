#ifndef dataaccess_DataBusinessObject_H_
#define dataaccess_DataBusinessObject_H_

#include "../businessobject/BusinessObject.h"
class DataBusinessObject {
public:
    virtual BusinessObject* GetPointer(int) = 0;
    virtual int GetSize() = 0;
};
#endif