#include <iostream>
#include <fstream>
#include "Identity.h"
#include "GlobalFile.h"
using namespace std;

void Login(const string& fileName, int type) {
    Identity* person = nullptr;

    ifstream ifs;
    ifs.open(fileName, ios::in);

    if (!ifs.is_open()) {
        cout << "File is not exist\n";
        ifs.close();
        return;
    }

    int id = 0;
    string name;
    string pwd;

    if (type == 1) {  // student login
        cout << "Please Input Your Student ID: " << endl;
        cin >> id;
    } else if (type == 2) {  // teacher login
        cout << "Please Input Your Teacher ID: " << endl;
        cin >> id;
    }

    cout << "Please Input Your User Name: " << endl;
    cin >> name;

    cout << "Please Input Your Password: " << endl;
    cin >> pwd;

    if (type == 1) {  // Student login

    } else if (type == 2) {  // Teacher login

    } else if (type == 3) {  // Administer login
    }

    cout << "Failed to verify login!" << endl;
    system("clear");
    return;
}

int main() {
    int select = 0;

    while (true) {
        cout << "========  Welcome to the computer room reservation system!  "
                "========\n";
        cout << "Please enter your identity\n";
        cout << "\t\t -------------------------------------\n";
        cout << "\t\t|                                     |\n";
        cout << "\t\t|      1. Student                     |\n";
        cout << "\t\t|                                     |\n";
        cout << "\t\t|      2. Teacher                     |\n";
        cout << "\t\t|                                     |\n";
        cout << "\t\t|      3. Administrator               |\n";
        cout << "\t\t|                                     |\n";
        cout << "\t\t|      0. Quit System                 |\n";
        cout << "\t\t|                                     |\n";
        cout << "\t\t -------------------------------------\n";
        cout << "Please enter your choice: ";

        cin >> select;

        switch (select) {
            case 1:
                Login(STUDENT_FILE, 1);
                break;
            case 2:
                Login(TEACHER_FILE, 2);
                break;
            case 3:
                Login(ADMIN_FILE, 3);
                break;
            case 0:
                cout << "Hope to see you again\n";
                return 0;
            default:
                cout << "Incorrect input, please re-select\n";
                break;
        }
    }
    return 0;
}