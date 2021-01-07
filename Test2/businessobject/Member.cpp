#include "Member.h"

Member::Member() {

}

Member::Member(int memberid, string membername) {
    _memberid = memberid;
    _membername = membername;
}

int Member::IncreaseID() {
    return ID = ++sIDMax;
}

int& Member::GetIDMax(){
    return sIDMax;
}

int Member::GetMemberID(){
    return _memberid;
}

string Member::GetMemberName(){
    return _membername;
}

string Member::PrintElement(){
    string s;
    s += "MemberID: " + to_string(_memberid) + ", ";
    s += "MemberName: " + _membername;
    return s; 
}

int Member::sIDMax = 0;
