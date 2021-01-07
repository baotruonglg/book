#include "BorrowReturn.h"

BorrowReturn::BorrowReturn() {

}

BorrowReturn::BorrowReturn(int borrowreturnid, int memberid, int bookid, string date, int borrowreturn) {
    _borrowreturnid = borrowreturnid;
    _memberid = memberid;
    _bookid = bookid;
    _date = date;
    _borrowreturn = borrowreturn;
}

int BorrowReturn::IncreaseID() {
    return ID = ++sIDMax;
}

int& BorrowReturn::GetIDMax(){
    return sIDMax;
}

int BorrowReturn::GetBorrowReturnID(){
    return _borrowreturnid;
}

int BorrowReturn::GetMemberID(){
    return _memberid;
}

int BorrowReturn::GetBookID(){
    return _bookid;
}

string BorrowReturn::GetDate() {
    return _date;
}

int BorrowReturn::GetBorrowReturn() {
    return _borrowreturn;
}

string BorrowReturn::PrintElement(){
    string s;
    s += "BorrowReturnID: " + to_string(_borrowreturnid) + ", ";
    s += "MemberID: " + to_string(_memberid) + ", ";
    s += "BookID: " + to_string(_bookid) + ", ";
    s += "Date: " + _date + ", ";
    s += "BorrowReturn: " + to_string(_borrowreturn);
    return s; 
}

int BorrowReturn::sIDMax = 0;