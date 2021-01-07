#ifndef businessobject_Member_H_
#define businessobject_Member_H_

#include "BusinessObject.h"

class Member : public BusinessObject {
private:
    int _memberid;
    string _membername;
    static int sIDMax;
public:
    Member();
    Member(int, string);
    int IncreaseID();
    int& GetIDMax();
    int GetMemberID();
    string GetMemberName();
    string PrintElement();
    friend istream& operator >> (istream&, Member& );
};
#endif