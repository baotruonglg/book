#ifndef businessobject_BorrowReturn_H_
#define businessobject_BorrowReturn_H_

#include "BusinessObject.h"

class BorrowReturn : public BusinessObject {
private:
    int _borrowreturnid;
    int _memberid;
    int _bookid;
    string _date;
    int _borrowreturn;
    static int sIDMax;
public:
    BorrowReturn();
    BorrowReturn(int, int, int, string, int);
    int IncreaseID();
    int& GetIDMax();
    int GetBorrowReturnID();
    int GetMemberID();
    int GetBookID();
    string GetDate();
    int GetBorrowReturn();
    string PrintElement();
    friend istream& operator >> (istream&, BorrowReturn& );
};
#endif