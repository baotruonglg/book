#include "MyUI.h"
#include <map>
void MyUI::Display(DataBusinessObject* databusinessobject) {
    cout << endl << endl;
    for (int i = 0; i < databusinessobject->GetSize(); i++) {
        BusinessObject * businessobject = databusinessobject->GetPointer(i);
        cout << "ID: " << businessobject->GetID() << ", " << businessobject->PrintElement() << endl;
    }
    cout << endl;
}

void MyUI::StoreData(string& foldername) {
    mkdir(("backupdata/" + foldername).c_str());
    memberdata.ExportToFile("backupdata/" + foldername + "/MemberData.txt");
    bookdata.ExportToFile("backupdata/" + foldername + "/BookData.txt");
    borrowreturndata.ExportToFile("backupdata/" + foldername + "/BorrowReturnData.txt");
    ofstream fileOut("backupdata/backupfilename.txt", ios::app);
    fileOut << foldername << endl;
}
    
void MyUI::RestoreData() {
    ifstream fileIn("backupdata/backupfilename.txt");
    vector<string> filename;
    string temp;
    while(getline(fileIn, temp)) {
        filename.push_back(temp);
    }
    cout << endl << endl;
    for (int i = 0; i < filename.size(); i++) {
        cout << "** " << i + 1 << ". " << filename[i] << endl;
    }
    cout << endl; 
    int choice;
    cout << "** Your choice: ";
    cin >> choice;
    cout << filename[choice - 1];
    bookdata.ReadFile("backupdata/" + filename[choice - 1] + "/BookData.txt");
    memberdata.ReadFile("backupdata/" + filename[choice - 1] + "/MemberData.txt");
    borrowreturndata.ReadFile("backupdata/" + filename[choice - 1] + "/BorrowReturnData.txt");
    Display(&memberdata);
    Display(&bookdata);
    Display(&borrowreturndata);
}

void MyUI::ListBookBorrowedMost(int N) {
    vector<int> number;
    number.resize(borrowreturndata.GetSize());
    for (int i = 0; i < borrowreturndata.GetSize(); i++) {
        number.push_back(borrowreturndata.Get(i).GetBookID());
    }
    map<int, int> listbook;
    for (int i = 0; borrowreturndata.GetSize(); i++) {
        listbook[number[i]] = 0;
    }
    
    for (int i = 0; i < listbook.size(); i++) {
        cout << listbook[number[i]] << " ";
    }
}

void MyUI::ListMemberOwnest(int) {
    
}

void MyUI::ChooseSentence() {
    int choice;
    do {
        system("cls");
        cout << endl << endl << endl;
        cout << "******************************MENU******************************" << endl;
        cout << "** 1. Read all files.                                          *" << endl;
        cout << "** 2. Create, Update, Delete data.                             *" << endl;
        cout << "** 3. Store data to backupdata.                                *" << endl;
        cout << "** 4. Restore data from backupdata.                            *" << endl;
        cout << "** 5. List books are borrowed the most.                        *" << endl;
        cout << "** 6. List member ownest.                                      *" << endl;
        cout << "** 0. Exit.                                                    *" << endl;
        cout << "**                                                             *" << endl;
        cout << "****************************************************************" << endl;
        cout << endl;
        cout << "** Your choice: ";
        cin >> choice;
        cin.ignore();
        switch(choice) {
            case 1:
                bookdata.ReadFile("data/BookData.txt");
                memberdata.ReadFile("data/MemberData.txt");
                borrowreturndata.ReadFile("data/BorrowReturnData.txt");
                Display(&memberdata);
                Display(&bookdata);
                Display(&borrowreturndata);
                break;
            case 2:
                ChooseClass();
                break;
            case 3:
                {string foldername;
                cout << "Enter folder name which you want to store: ";
                getline(cin, foldername);
                StoreData(foldername);}
                break;
            case 4:
                RestoreData();
                break;
            case 5:
                ListBookBorrowedMost(2);
                break;
            case 6:
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
    } while (true);
}
void MyUI::ChooseClass() {
    int choice; 
    bool k = true;
    do {
        system("cls");
        cout << endl << endl << endl;
        cout << "******************************MENU******************************" << endl;
        cout << "** 1. Member class.                                            *" << endl;
        cout << "** 2. Book class.                                              *" << endl;
        cout << "** 3. Borrowreturn class.                                      *" << endl;
        cout << "** 4. Return.                                                  *" << endl;
        cout << "** 0. Exit.                                                    *" << endl;
        cout << "**                                                             *" << endl;
        cout << "****************************************************************" << endl;
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
    } while (k);
}
void MyUI::ChooseOption(int n) {
    int choice; 
    bool k = true;
    do {
        system("cls");
        cout << endl << endl << endl;
        cout << "******************************MENU******************************" << endl;
        cout << "** 1. Create data.                                             *" << endl;
        cout << "** 2. Update data.                                             *" << endl;
        cout << "** 3. Delete data.                                             *" << endl;
        cout << "** 4. Return.                                                  *" << endl;
        cout << "** 0. Exit.                                                    *" << endl;
        cout << "**                                                             *" << endl;
        cout << "****************************************************************" << endl;
        cout << endl;
        cout << "** Your choice: ";
        cin >> choice;
        switch(choice) {
            case 1:
                if (n == 1) {
                    Member m;
                    cin >> m;
                    memberdata.CreateData(m);
                    Display(&memberdata);
                }
                else if (n == 2) {
                    Book m;
                    cin >> m;
                    bookdata.CreateData(m);
                    Display(&bookdata);
                }
                else {
                    BorrowReturn m;
                    cin >> m;
                    borrowreturndata.CreateData(m);
                    Display(&borrowreturndata);
                }
                break;
            case 2:
                int id;
                cout << "Enter ID which you want to update: ";
                cin >> id;
                if (n == 1) {
                    Member m;
                    cin >> m;
                    memberdata.UpdateData(m, id);
                    Display(&memberdata);
                }
                else if (n == 2) {
                    Book m;
                    cin >> m;
                    bookdata.UpdateData(m, id);
                    Display(&bookdata);
                }
                else {
                    BorrowReturn m;
                    cin >> m;
                    borrowreturndata.UpdateData(m, id);
                    Display(&borrowreturndata);
                }
                break;
            case 3:
                int iddeletem;
                cout << "Enter ID which you want to delete: ";
                cin >> iddeletem;
                if (n == 1) {
                    memberdata.DeleteData(iddeletem);
                    Display(&memberdata);
                }
                else if (n == 2) {
                    bookdata.DeleteData(iddeletem);
                    Display(&bookdata);
                }
                else {
                    borrowreturndata.DeleteData(iddeletem);
                    Display(&borrowreturndata);
                }
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
        if (choice != 0 && choice != 4) {
            system("pause");
            system("cls");
        }
    } while (k);
}