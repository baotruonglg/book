#ifndef dataaccess_BookData_H_
#define dataaccess_BookData_H_

#include "../businessobject/Book.h"
#include "DataBusinessObject.h" 
#include <vector>
#include <fstream>

class BookData : public DataBusinessObject {
private:
    vector<Book> _arrBook;
public:
    BookData();
    Book Get(int);
    BusinessObject* GetPointer(int);
    int GetSize();
    void ReadFile(string);
    void CreateData(Book&);
    void UpdateData(Book&, int&);
    void DeleteData(int);
    void ExportToFile(string);
};
#endif