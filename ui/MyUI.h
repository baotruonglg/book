#ifndef ui_MyUI_H_
#define ui_MyUI_H_

#include "../dataaccess/MemberData.h"
#include "../dataaccess/BookData.h"
#include "../dataaccess/BorrowReturnData.h"
#include "../businessobject/BusinessObject.h"
#include "../dataaccess/DataBusinessObject.h"
class MyUI {
private:
    MemberData memberdata;
    BookData bookdata;
    BorrowReturnData borrowreturndata;
public:
    void Display(DataBusinessObject* );
    void ChooseSentence();
    void ChooseData();
    void ChooseOption(int);
    void ListBooksBorrowedMost();
};
#endif