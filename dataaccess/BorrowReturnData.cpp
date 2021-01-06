#include "BorrowReturnData.h"

BorrowReturnData::BorrowReturnData() {
    arrBorrowReturn.resize(0);
}

int BorrowReturnData::GetSize() {
    return arrBorrowReturn.size();
}

BusinessObject* BorrowReturnData::GetPointer(int i) {
    return &arrBorrowReturn[i];
}

BorrowReturn BorrowReturnData::Get(int i) {
    return arrBorrowReturn[i];
}

void BorrowReturnData::ReadFile(string filename) {
    if (arrBorrowReturn.size() != 0) {
        arrBorrowReturn.back().GetIDMax() = 0;
    }
    arrBorrowReturn.resize(0);
    ifstream fileIn(filename);
    int numberelement;
    int borrowreturnid;
    int memberid;
    int bookid;
    string date;
    string borrowreturnname;
    int price;
    int borrow;
    fileIn >> numberelement;
    for (int i = 0; i < numberelement; i++) {
        fileIn >> borrowreturnid;
        fileIn >> memberid;
        fileIn >> bookid;
        fileIn.ignore();
        getline(fileIn, date);
        getline(fileIn, borrowreturnname);
        fileIn >> price;
        fileIn >> borrow;
        BorrowReturn b(borrowreturnid, memberid, bookid, date, borrowreturnname, price, borrow);
        b.IncreaseID();
        arrBorrowReturn.push_back(b);
    }
    fileIn.close();
}

void BorrowReturnData::Create(BorrowReturn& br) {
    br.IncreaseID();
    arrBorrowReturn.push_back(br);
}

void BorrowReturnData::Update(BorrowReturn& br, int& i) {
    br.GetID() = arrBorrowReturn[i - 1].GetID();
    arrBorrowReturn[i - 1] = br;
}

void BorrowReturnData::Delete(int& i) {
    arrBorrowReturn.erase(arrBorrowReturn.begin() + i - 1);
}