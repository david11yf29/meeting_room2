#include <iostream>
#include "Student.h"
using namespace std;

Student::Student() {}
Student::Student(int id, const std::string& name, const std::string& pwd) {
    this->m_Id = id;
    this->m_Name = name;
    this->m_Pwd = pwd;
}

void Student::openMenu() {
    cout << "Welcome student representative: " << this->m_Name << " login!";
    cout << "\t\t ------------------------------------------\n";
    cout << "\t\t|                                          |\n";
    cout << "\t\t|        1. Apply Reservation              |\n";
    cout << "\t\t|                                          |\n";
    cout << "\t\t|        2. View Your Reservation          |\n";
    cout << "\t\t|                                          |\n";
    cout << "\t\t|        3. View All Reservation           |\n";
    cout << "\t\t|                                          |\n";
    cout << "\t\t|        4. Cancel Reservation             |\n";
    cout << "\t\t|                                          |\n";
    cout << "\t\t|        0. Logout                         |\n";
    cout << "\t\t|                                          |\n";
    cout << "\t\t ------------------------------------------\n";
    cout << "Please choose your operation: ";
}

void Student::applyOrder() {}

void Student::showMyOrder() {}

void Student::showAllOrder() {}

void Student::cancelOrder() {}
