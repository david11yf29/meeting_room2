#include "Administrator.h"
#include <iostream>
using namespace std;

Administrator::Administrator() {}
Administrator::Administrator(const std::string& name, const std::string& pwd) {
    this->m_Name = name;
    this->m_Pwd = pwd;
}

void Administrator::openMenu() {
    cout << "Welcome administrator: " << this->m_Name << " login!";
    cout << "\t\t -------------------------------------------\n";
    cout << "\t\t|                                          |\n";
    cout << "\t\t|       1. Add account                     |\n";
    cout << "\t\t|                                          |\n";
    cout << "\t\t|       2. View account                    |\n";
    cout << "\t\t|                                          |\n";
    cout << "\t\t|       3. View computer room              |\n";
    cout << "\t\t|                                          |\n";
    cout << "\t\t|       4. Clear reservation record        |\n";
    cout << "\t\t|                                          |\n";
    cout << "\t\t|       0. Logout                          |\n";
    cout << "\t\t|                                          |\n";
    cout << "\t\t ------------------------------------------\n";
    cout << "Please choose your operation: ";
}

void Administrator::addPerson() {}
void Administrator::showPerson() {}

void Administrator::showComputer() {}

void Administrator::clearRecord() {}
