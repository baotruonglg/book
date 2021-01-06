#include "BorrowReturn.h"

BorrowReturn::BorrowReturn() {

}

BorrowReturn::BorrowReturn(int borrowreturnid, int memberid, int bookid, string date, string borrowreturnname, int price, int borrow) {
    this->borrowreturnid = borrowreturnid;
    this->memberid = memberid;
    this->bookid = bookid;
    this->date = date;
    this->borrowreturnname = borrowreturnname;
    this->price = price;
    this->borrow = borrow;
}

int& BorrowReturn::GetIDMax() {
    return sIDMax;
}

int BorrowReturn::IncreaseID() {
    return ID = ++sIDMax;
}

int BorrowReturn::GetBorrowReturnID() {
    return borrowreturnid;
}

string BorrowReturn::GetBorrowReturnName() {
    return borrowreturnname;
}

int BorrowReturn::GetPrice() {
    return price;
}   

int BorrowReturn::GetBorrow() {
    return borrow;
}

string BorrowReturn::GetDate() {
    return date;
}

int BorrowReturn::GetMemberID() {
    return memberid;
}

int BorrowReturn::GetBookID() {
    return bookid;
}


string BorrowReturn::PrintElement() {
    string s;
    s += "BorrowID: " + to_string(borrowreturnid) + ", ";
    s += "MemberID: " + to_string(memberid) + ", ";
    s += "BookID: " + to_string(bookid) + ", ";
    s += "Date: " + date + ", ";
    s += "Name: " + borrowreturnname + ", ";
    s += "Price: " + to_string(price) + ", ";
    s += "Borrow: " + to_string(borrow);
    return s;
}

int BorrowReturn::sIDMax = 0;