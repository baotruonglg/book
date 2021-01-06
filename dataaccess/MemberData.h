#ifndef dataaccess_MemberData_H_
#define dataaccess_MemberData_H_

#include "DataBusinessObject.h"
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include "../businessobject/Member.h"
using namespace std;

class MemberData : public DataBusinessObject {
private:
    vector<Member> arrMember;
public:
    MemberData();
    int GetSize();
    BusinessObject* GetPointer(int);
    Member Get(int);
    void ReadFile(string);
    void Create(Member&);
    void Update(Member&, int&);
    void Delete(int&);
};
#endif 