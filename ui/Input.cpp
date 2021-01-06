#include "Input.h"
#include <iostream>
using namespace std;

istream& operator >> (istream& is, Member& m) {
    cout << "Enter member id: "; is >> m.memberid; is.ignore();
    cout << "Enter member name: "; getline(is, m.membername);
    return is;
}

istream& operator >> (istream& is, Book& b) {
    cout << "Enter book id: "; is >> b.bookid; is.ignore();
    cout << "Enter book name: "; getline(is, b.bookname);
    cout << "Enter price: "; is >> b.price;
    return is;
}

istream& operator >> (istream& is, BorrowReturn& br) {
    cout << "Enter borrow return id: "; is >> br.borrowreturnid; is.ignore();
    cout << "Enter member id: "; is >> br.memberid;
    cout << "Enter book id: "; is >> br.bookid; is.ignore();
    cout << "Enter date: "; getline(is, br.date);
    cout << "Enter borrowreturn name: "; getline(is, br.borrowreturnname);
    cout << "Enter price: "; is >> br.price;
    cout << "Enter borrow: "; is >> br.borrow;
    return is;
}
