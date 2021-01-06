#ifndef businessobject_BorrowReturn_H_
#define businessobject_BorrowReturn_H_

#include <string>
#include "BusinessObject.h"
using namespace std;

class BorrowReturn : public BusinessObject {
private:
    int borrowreturnid;
    int memberid;
    int bookid;
    string date;
    string borrowreturnname;
    int price;
    int borrow;
    static int sIDMax;
public:
    BorrowReturn();
    BorrowReturn(int, int, int, string, string, int, int);
    int& GetIDMax();
    int GetBorrowReturnID();
    string GetBorrowReturnName();
    int GetPrice();
    int GetBorrow();
    string GetDate();
    int GetMemberID();
    int GetBookID();
    string PrintElement();
    int IncreaseID();
    friend istream& operator >> (istream&, BorrowReturn& );
};
#endif