#include "MemberData.h"

MemberData::MemberData() {
    arrMember.resize(0);
}

int MemberData::GetSize() {
    return arrMember.size();
}

BusinessObject* MemberData::GetPointer(int i) {
    return &arrMember[i];
}

Member MemberData::Get(int i) {
    return arrMember[i];
}


void MemberData::ReadFile(string filename) {
    if (arrMember.size() != 0) {
        arrMember.back().GetIDMax() = 0;
    }
    arrMember.resize(0);
    ifstream fileIn(filename);
    int numberelement;
    int memberid;
    string membername;
    fileIn >> numberelement;
    for (int i = 0; i < numberelement; i++) {
        fileIn >> memberid;
        fileIn.ignore();
        getline(fileIn, membername);
        Member m(memberid, membername);
        m.IncreaseID();
        arrMember.push_back(m);
    }
    fileIn.close();
}

void MemberData::Create(Member& b) {
    b.IncreaseID();
    arrMember.push_back(b);
}

void MemberData::Update(Member& b, int& i) {
    b.GetID() = arrMember[i - 1].GetID();
    arrMember[i - 1] = b;
}

void MemberData::Delete(int& i) {
    arrMember.erase(arrMember.begin() + i - 1);
}
