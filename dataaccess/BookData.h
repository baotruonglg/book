#ifndef dataaccess_BookData_H_
#define dataaccess_BookData_H_

#include "DataBusinessObject.h"
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include "../businessobject/Book.h"
using namespace std;

class BookData : public DataBusinessObject {
private:
    vector<Book> arrBook;
public:
    BookData();
    int GetSize();
    BusinessObject* GetPointer(int);
    Book Get(int);
    void ReadFile(string);
    void Create(Book&);
    void Update(Book&, int&);
    void Delete(int&);
};
#endif 