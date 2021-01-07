#ifndef ui_MyUI_H_
#define ui_MyUI_H_

#include "../dataaccess/MemberData.h"
#include "../dataaccess/BorrowReturnData.h"
#include "../dataaccess/BookData.h"
#include <direct.h>
#include <iostream>
using namespace std;

class MyUI {
private:
    BookData bookdata;
    MemberData memberdata;
    BorrowReturnData borrowreturndata;
public:
    void Display(DataBusinessObject* );
    void ChooseSentence();
    void ChooseClass();
    void ChooseOption(int);
    void StoreData(string&);
    void RestoreData();
    void ListBookBorrowedMost(int);
    void ListMemberOwnest(int);
};
#endif