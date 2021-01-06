#ifndef businessobject_Book_H_
#define businessobject_Book_H_

#include <string>
#include "BusinessObject.h"
using namespace std;

class Book : public BusinessObject {
private:
    int bookid;
    string bookname;
    int price;
    static int sIDMax;
public:
    Book();
    Book(int, string, int);
    int& GetIDMax();
    int GetBookID();
    string GetBookName();
    int GetPrice();
    string PrintElement();
    int IncreaseID();
    friend istream& operator >> (istream&, Book&);
};
#endif