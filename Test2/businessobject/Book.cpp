#include "Book.h"

Book::Book() {

}

Book::Book(int bookid, string bookname, int price) {
    _bookid = bookid;
    _bookname = bookname;
    _price = price;
}

int Book::IncreaseID() {
    return ID = ++sIDMax;
}

int& Book::GetIDMax(){
    return sIDMax;
}

int Book::GetBookID(){
    return _bookid;
}

string Book::GetBookName(){
    return _bookname;
}

int Book::GetPrice() {
    return _price;
}

string Book::PrintElement(){
    string s;
    s += "BookID: " + to_string(_bookid) + ", ";
    s += "BookName: " + _bookname + ", ";
    s += "Price: " + to_string(_price);
    return s; 
}

int Book::sIDMax = 0;