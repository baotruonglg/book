#include "MemberData.h"

MemberData::MemberData() {
    _arrMember.resize(0);
}

Member MemberData::Get(int i) {
    return _arrMember[i];
}

BusinessObject* MemberData::GetPointer(int i) {
    return &_arrMember[i];
}

int MemberData::GetSize() {
    return _arrMember.size();
}

void MemberData::ReadFile(string filename) {
    if (_arrMember.size() != 0) {
        _arrMember.back().GetIDMax() = 0;
    }
    _arrMember.resize(0);
    ifstream fileIn(filename);
    int numberelement;
    fileIn >> numberelement;
    int _memberid;
    string _membername;
    for (int i = 0; i < numberelement; i++) {
        fileIn >> _memberid; fileIn.ignore();
        getline(fileIn, _membername);
        Member m(_memberid, _membername);
        m.IncreaseID();
        _arrMember.push_back(m); 
    }
    fileIn.close();
}

void MemberData::CreateData(Member& m) {
    m.IncreaseID();
    _arrMember.push_back(m);
}

void MemberData::UpdateData(Member& m , int& i) {
    m.GetID() = _arrMember[i - 1].GetID();
    _arrMember[i - 1] = m;
}

void MemberData::DeleteData(int x) {
    for (int i = 0; i < _arrMember.size(); i++) {
        if (_arrMember[i].GetID() == x) {
            _arrMember.erase(_arrMember.begin() + i);
        }
    }
}

void MemberData::ExportToFile(string filename) {
    ofstream fileOut(filename);
    fileOut << _arrMember.size() << endl;
    for (int i = 0; i < _arrMember.size(); i++) {
        fileOut << _arrMember[i].GetMemberID() << endl;
        fileOut << _arrMember[i].GetMemberName() << endl;
    }
    fileOut.close();
}
