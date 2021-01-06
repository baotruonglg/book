#ifndef dataaccess_DataBusinessObject_H_
#define dataaccess_DataBusinessObject_H_

#include "../businessobject/BusinessObject.h"

class DataBusinessObject {
public:
    virtual int GetSize() = 0;
    virtual BusinessObject* GetPointer(int) = 0;
};
#endif 