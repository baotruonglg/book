#ifndef dataaccess_MemberData_H_
#define dataaccess_MemberData_H_

#include "../businessobject/Member.h"
#include "DataBusinessObject.h" 
#include <vector>
#include <fstream>

class MemberData : public DataBusinessObject {
private:
    vector<Member> _arrMember;
public:
    MemberData();
    Member Get(int);
    BusinessObject* GetPointer(int);
    int GetSize();
    void ReadFile(string);
    void CreateData(Member&);
    void UpdateData(Member&, int&);
    void DeleteData(int);
    void ExportToFile(string);
};
#endif