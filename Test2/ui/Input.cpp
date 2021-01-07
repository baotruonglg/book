#include "Input.h"

istream& operator >> (istream& is, Book& b) {
    cout << "Enter book id: "; is >> b._bookid; is.ignore();
    cout << "Enter book name: "; getline(is, b._bookname);
    cout << "Enter price: "; is >> b._price;
    return is;
}

istream& operator >> (istream& is, BorrowReturn& br) {
    cout << "Enter borrowreturn id: "; is >> br._borrowreturnid;
    cout << "Enter member id: "; is >> br._memberid;
    cout << "Enter book id: "; is >> br._bookid; is.ignore();
    cout << "Enter date: "; getline(is, br._date);
    cout << "Enter borrowreturn: "; is >> br._borrowreturn;
    return is;
}

istream& operator >> (istream& is, Member& m) {
    cout << "Enter member id: "; is >> m._memberid; is.ignore();
    cout << "Enter member name: "; getline(is, m._membername);
    return is;
}
