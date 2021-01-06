#include "Book.h"

Book::Book() {

}

Book::Book(int Bookid, string Bookname, int price) {
    this->bookid = Bookid;
    this->bookname = Bookname;
    this->price = price;
}

int& Book::GetIDMax() {
    return sIDMax;
}

int Book::IncreaseID() {
    return ID = ++sIDMax;
}

int Book::GetBookID() {
    return bookid;
}

string Book::GetBookName() {
    return bookname;
}

string Book::PrintElement() {
    string s;
    s += "BookID: " + to_string(bookid) + ", ";
    s += "Book Name: " + bookname + ", ";
    s += "Price: " + to_string(price);
    return s;
}

int Book::sIDMax = 0;