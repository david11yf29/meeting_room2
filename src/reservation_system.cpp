#include <iostream>
using namespace std;

int main() {
    int select = 0;

    while (true) {
        cout << "========  Welcome to the computer room reservation system!  "
                "========"
             << endl;
        cout << endl << "Please enter your identity" << endl;
        cout << "\t\t -------------------------------------\n" << endl;
        cout << "\t\t|                                     |\n" << endl;
        cout << "\t\t|      1. Student                     |\n" << endl;
        cout << "\t\t|                                     |\n" << endl;
        cout << "\t\t|      2. Teacher                     |\n" << endl;
        cout << "\t\t|                                     |\n" << endl;
        cout << "\t\t|      3. Administrator               |\n" << endl;
        cout << "\t\t|                                     |\n" << endl;
        cout << "\t\t|      0. Quit System                 |\n" << endl;
        cout << "\t\t|                                     |\n" << endl;
        cout << "\t\t -------------------------------------\n" << endl;
        cout << "Please enter your choice: " << endl;

        cin >> select;

        switch (select) {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 0:
                cout << "Hope to see you again" << endl;
                return 0;
            default:
                cout << "Incorrect input, please re-select" << endl;
                break;
        }
    }
    return 0;
}