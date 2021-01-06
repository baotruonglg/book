#ifndef dataaccess_BorrowReturnData_H_
#define dataaccess_BorrowReturnData_H_

#include "DataBusinessObject.h"
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include "../businessobject/BorrowReturn.h"
using namespace std;

class BorrowReturnData : public DataBusinessObject {
private:
    vector<BorrowReturn> arrBorrowReturn;
public:
    BorrowReturnData();
    int GetSize();
    BusinessObject* GetPointer(int);
    BorrowReturn Get(int);
    void ReadFile(string);
    void Create(BorrowReturn&);
    void Update(BorrowReturn&, int&);
    void Delete(int&);
};
#endif 