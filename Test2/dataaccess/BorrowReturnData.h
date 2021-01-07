#ifndef dataaccess_BorrowReturnData_H_
#define dataaccess_BorrowReturnData_H_

#include "../businessobject/BorrowReturn.h"
#include "DataBusinessObject.h" 
#include <vector>
#include <fstream>

class BorrowReturnData : public DataBusinessObject {
private:
    vector<BorrowReturn> _arrBorrowReturn;
public:
    BorrowReturnData();
    BorrowReturn Get(int);
    BusinessObject* GetPointer(int);
    int GetSize();
    void ReadFile(string);
    void CreateData(BorrowReturn&);
    void UpdateData(BorrowReturn&, int&);
    void DeleteData(int);
    void ExportToFile(string);
};
#endif