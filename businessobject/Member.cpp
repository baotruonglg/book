#include "Member.h"

Member::Member() {

}

Member::Member(int memberid, string membername) {
    this->memberid = memberid;
    this->membername = membername;
}

int& Member::GetIDMax() {
    return sIDMax;
}

int Member::IncreaseID() {
    return ID = ++sIDMax;
}

int Member::GetMemberID() {
    return memberid;
}

string Member::GetMemberName() {
    return membername;
}

string Member::PrintElement() {
    string s;
    s += "MemberID: " + to_string(memberid) + ", ";
    s += "MemberName: " + membername;
    return s;
}

int Member::sIDMax = 0;