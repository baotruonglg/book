#ifndef ui_Input_H_
#define ui_Input_H_

#include "../businessobject/Book.h"
#include "../businessobject/BorrowReturn.h"
#include "../businessobject/Member.h"
#include <iostream>
using namespace std;

istream& operator >> (istream& is, Book& b);
istream& operator >> (istream& is, BorrowReturn& br);
istream& operator >> (istream& is, Member& m);
#endif
