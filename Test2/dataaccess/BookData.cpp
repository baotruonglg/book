#include "BookData.h"

BookData::BookData() {
    _arrBook.resize(0);
}

Book BookData::Get(int i) {
    return _arrBook[i];
}

BusinessObject* BookData::GetPointer(int i) {
    return &_arrBook[i];
}

int BookData::GetSize() {
    return _arrBook.size();
}

void BookData::ReadFile(string filename) {
    if (_arrBook.size() != 0) {
        _arrBook.back().GetIDMax() = 0;
    }
    _arrBook.resize(0);
    ifstream fileIn(filename);
    int numberelement;
    fileIn >> numberelement;
    int _bookid;
    string _bookname;
    int _price;
    for (int i = 0; i < numberelement; i++) {
        fileIn >> _bookid; fileIn.ignore();
        getline(fileIn, _bookname);
        fileIn >> _price;
        Book m(_bookid, _bookname, _price);
        m.IncreaseID();
        _arrBook.push_back(m); 
    }
    fileIn.close();
}

void BookData::CreateData(Book& m) {
    m.IncreaseID();
    _arrBook.push_back(m);
}

void BookData::UpdateData(Book& m , int& i) {
    m.GetID() = _arrBook[i - 1].GetID();
    _arrBook[i - 1] = m;
}

void BookData::DeleteData(int x) {
    for (int i = 0; i < _arrBook.size(); i++) {
        if (_arrBook[i].GetID() == x) {
            _arrBook.erase(_arrBook.begin() + i);
        }
    }
}

void BookData::ExportToFile(string filename) {
    ofstream fileOut(filename);
    fileOut << _arrBook.size() << endl;
    for (int i = 0; i < _arrBook.size(); i++) {
        fileOut << _arrBook[i].GetBookID() << endl;
        fileOut << _arrBook[i].GetBookName() << endl;
        fileOut << _arrBook[i].GetPrice() << endl;
    }
    fileOut.close();
}
