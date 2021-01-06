#ifndef businessobject_Member_H_
#define businessobject_Member_H_

#include <string>
#include "BusinessObject.h"
using namespace std;

class Member : public BusinessObject {
private:
    int memberid;
    string membername;
    static int sIDMax;
public:
    Member();
    Member(int, string);
    int& GetIDMax();
    int GetMemberID();
    string GetMemberName();
    string PrintElement();
    int IncreaseID();
    friend istream& operator >> (istream&, Member&);
};
#endif
