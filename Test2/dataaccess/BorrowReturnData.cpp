#include "BorrowReturnData.h"

BorrowReturnData::BorrowReturnData() {
    _arrBorrowReturn.resize(0);
}

BorrowReturn BorrowReturnData::Get(int i) {
    return _arrBorrowReturn[i];
}

BusinessObject* BorrowReturnData::GetPointer(int i) {
    return &_arrBorrowReturn[i];
}

int BorrowReturnData::GetSize() {
    return _arrBorrowReturn.size();
}

void BorrowReturnData::ReadFile(string filename) {
    if (_arrBorrowReturn.size() != 0) {
        _arrBorrowReturn.back().GetIDMax() = 0;
    }
    _arrBorrowReturn.resize(0);
    ifstream fileIn(filename);
    int numberelement;
    fileIn >> numberelement;
    int _borrowreturnid;
    int _memberid;
    int _bookid;
    string _date;
    int _borrowreturn;
    for (int i = 0; i < numberelement; i++) {
        fileIn >> _borrowreturnid;
        fileIn >> _memberid;
        fileIn >> _bookid; fileIn.ignore();
        getline(fileIn, _date);
        fileIn >> _borrowreturn;
        BorrowReturn m(_borrowreturnid, _memberid, _bookid, _date, _borrowreturn);
        m.IncreaseID();
        _arrBorrowReturn.push_back(m); 
    }
    fileIn.close();
}

void BorrowReturnData::CreateData(BorrowReturn& m) {
    m.IncreaseID();
    _arrBorrowReturn.push_back(m);
}

void BorrowReturnData::UpdateData(BorrowReturn& m , int& i) {
    m.GetID() = _arrBorrowReturn[i - 1].GetID();
    _arrBorrowReturn[i - 1] = m;
}

void BorrowReturnData::DeleteData(int x) {
    for (int i = 0; i < _arrBorrowReturn.size(); i++) {
        if (_arrBorrowReturn[i].GetID() == x) {
            _arrBorrowReturn.erase(_arrBorrowReturn.begin() + i);
        }
    }
}

void BorrowReturnData::ExportToFile(string filename) {
    ofstream fileOut(filename);
    fileOut << _arrBorrowReturn.size() << endl;
    for (int i = 0; i < _arrBorrowReturn.size(); i++) {
        fileOut << _arrBorrowReturn[i].GetBorrowReturnID() << endl;
        fileOut << _arrBorrowReturn[i].GetMemberID() << endl;
        fileOut << _arrBorrowReturn[i].GetBookID() << endl;
        fileOut << _arrBorrowReturn[i].GetDate() << endl;
        fileOut << _arrBorrowReturn[i].GetBorrowReturn() << endl;
    }
    fileOut.close();
}
