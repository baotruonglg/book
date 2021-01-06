#ifndef ui_Input_H_
#define ui_Input_H_

#include "../businessobject/BorrowReturn.h"
#include "../businessobject/Book.h"
#include "../businessobject/Member.h"

istream& operator >> (istream&, Member&);
istream& operator >> (istream&, Book&);
istream& operator >> (istream&, BorrowReturn& );
#endif