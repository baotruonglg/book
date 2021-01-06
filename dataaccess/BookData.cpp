#include "BookData.h"

BookData::BookData() {
    arrBook.resize(0);
}

int BookData::GetSize() {
    return arrBook.size();
}

BusinessObject* BookData::GetPointer(int i) {
    return &arrBook[i];
}

Book BookData::Get(int i) {
    return arrBook[i];
}

void BookData::ReadFile(string filename) {
    if (arrBook.size() != 0) {
        arrBook.back().GetIDMax() = 0;
    }
    arrBook.resize(0);
    ifstream fileIn(filename);
    int numberelement;
    int bookid;
    string bookname;
    int price;
    fileIn >> numberelement;
    for (int i = 0; i < numberelement; i++) {
        fileIn >> bookid;
        fileIn.ignore();
        getline(fileIn, bookname);
        fileIn >> price;
        Book b(bookid, bookname, price);
        b.IncreaseID();
        arrBook.push_back(b);
    }
    fileIn.close();
}

void BookData::Create(Book& b) {
    b.IncreaseID();
    arrBook.push_back(b);
}

void BookData::Update(Book& b, int& i) {
    b.GetID() = arrBook[i - 1].GetID();
    arrBook[i - 1] = b;
}

void BookData::Delete(int& i) {
    arrBook.erase(arrBook.begin() + i - 1);
}

