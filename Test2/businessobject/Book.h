#ifndef businessobject_Book_H_
#define businessobject_Book_H_

#include "BusinessObject.h"

class Book : public BusinessObject {
private:
    int _bookid;
    string _bookname;
    int _price;
    static int sIDMax;
public:
    Book();
    Book(int, string, int);
    int IncreaseID();
    int& GetIDMax();
    int GetBookID();
    string GetBookName();
    int GetPrice();
    string PrintElement();
    friend istream& operator >> (istream&, Book& );
};
#endif