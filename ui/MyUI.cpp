#include "MyUI.h"
#include <map>
void MyUI::Display(DataBusinessObject* databusinessobject) {
    for (int i = 0; i < databusinessobject->GetSize(); i++) {
        BusinessObject* businessobject = databusinessobject->GetPointer(i);
        cout << "ID: " << businessobject->GetID() << ", " << businessobject->PrintElement() << endl; 
    }
    cout << endl << endl;
}

void MyUI::ListBooksBorrowedMost() {
    
}

void MyUI::ChooseSentence() {
    int choice;
    do {
        system("cls");
        cout << endl << endl << endl;
        cout << "***********************MENU*************************" << endl;
        cout << "** 1. Create, Read, Update, Delete.                *" << endl;
        cout << "** 2. List of books is borrowed the most.          *" << endl;
        cout << "** 3. List of people owed the most.                *" << endl;
        cout << "** 0. Exit.                                        *" << endl;
        cout << "**                                                 *" << endl;
        cout << "****************************************************" << endl;
        cout << endl;
        cout << "** Your choice: ";
        cin >> choice;
        switch(choice) {
            case 1:
                ChooseData();
                break;
            case 2:
                ListBooksBorrowedMost();
                break;
            case 3:
                break;
            case 4:
                break;
            case 0:
                exit('0');
                break;
            default:
                exit('0');
                break;
        }
        if (choice != 0) {
            system("pause");
            system("cls");
        }
    } while(true);
}

void MyUI::ChooseData() {
    int choice;
    bool k = true;
    do {
        system("cls");
        cout << endl << endl << endl;
        cout << "***********************MENU*************************" << endl;
        cout << "** 1. Member class                                 *" << endl;
        cout << "** 2. Book class                                   *" << endl;
        cout << "** 3. Borrow return class                          *" << endl;
        cout << "** 4. Return.                                      *" << endl;
        cout << "** 0. Exit.                                        *" << endl;
        cout << "**                                                 *" << endl;
        cout << "****************************************************" << endl;
        cout << endl;
        cout << "** Your choice: ";
        cin >> choice;
        switch(choice) {
            case 1:
                ChooseOption(choice);
                break;
            case 2:
                ChooseOption(choice);
                break;
            case 3:
                ChooseOption(choice);
                break;
            case 4:
                k = false;
                break;
            case 0:
                exit('0');
                break;
            default:
                exit('0');
                break;
        }
    } while(k);
}

void MyUI::ChooseOption(int n) {
    int choice;
    bool k = true;
    do {
        system("cls");
        cout << endl << endl << endl;
        cout << "***********************MENU*************************" << endl;
        cout << "** 1. Create element.                              *" << endl;
        cout << "** 2. Update element.                              *" << endl;
        cout << "** 3. Delete element                               *" << endl;
        cout << "** 4. Read file.                                   *" << endl;
        cout << "** 5. Return.                                      *" << endl;
        cout << "** 0. Exit.                                        *" << endl;
        cout << "**                                                 *" << endl;
        cout << "****************************************************" << endl;
        cout << endl;
        cout << "** Your choice: ";
        cin >> choice;
        switch(choice) {
            case 1:
                if (n == 1) {
                    Member m;
                    cin >> m;
                    memberdata.Create(m);
                    Display(&memberdata);
                }
                else if (n == 2) {
                    Book b;
                    cin >> b;
                    bookdata.Create(b);
                    Display(&bookdata);
                }
                else {
                    BorrowReturn br;
                    cin >> br;
                    borrowreturndata.Create(br);
                    Display(&borrowreturndata);
                }
                break;
            case 2:
                if (n == 1) {
                    int person;
                    cout << "Enter the person who you want to update: ";
                    cin >> person;
                    Member m;
                    cin >> m;
                    memberdata.Update(m, person);
                    Display(&memberdata);
                }
                else if (n == 2) {
                    int person;
                    cout << "Enter the person who you want to update: ";
                    cin >> person;
                    Book b;
                    cin >> b;
                    bookdata.Update(b, person);
                    Display(&bookdata);
                }
                else {
                    int person;
                    cout << "Enter the person who you want to update: ";
                    cin >> person;
                    BorrowReturn br;
                    cin >> br;
                    borrowreturndata.Update(br, person);
                    Display(&borrowreturndata);
                }   
                break;
            case 3:
                if (n == 1) {
                    int person;
                    cout << "Enter the person who you want to delete: ";
                    cin >> person;
                    memberdata.Delete(person);
                    Display(&memberdata);
                }
                else if (n == 2) {
                    int person;
                    cout << "Enter the person who you want to delete: ";
                    cin >> person;
                    bookdata.Delete(person);
                    Display(&bookdata);
                }
                else {
                    int person;
                    cout << "Enter the person who you want to delete: ";
                    cin >> person;
                    borrowreturndata.Delete(person);
                    Display(&borrowreturndata);
                }
                break;
            case 4:
                if (n == 1) {
                    memberdata.ReadFile("data/MemberData.txt");
                    Display(&memberdata);
                }
                else if (n == 2) {
                    bookdata.ReadFile("data/BookData.txt");
                    Display(&bookdata);
                }
                else {
                    borrowreturndata.ReadFile("data/BorrowReturnData.txt");
                    Display(&borrowreturndata);
                }
                break;
            case 5:
                k = false;
                break;
            case 0:
                exit('0');
                break;
            default:
                exit('0');
                break;
        }
        if (choice != 0 && choice != 5) {
            system("pause");
            system("cls");
        }
    } while(k);
}
