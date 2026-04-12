#include "Administrator.h"
#include <iostream>
#include "Student.h"
using namespace std;

Administrator::Administrator() {}
Administrator::Administrator(const std::string& name, const std::string& pwd) {
    this->m_Name = name;
    this->m_Pwd = pwd;

    this->initVector();
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

void Administrator::addPerson() {
    cout << "Please enter the add account type" << endl;
    cout << "1. Add Student" << endl;
    cout << "2. Add Teacher" << endl;

    string fileName;
    string tip;
    string errorTip;

    ofstream ofs;

    int select = 0;

    cin >> select;

    if (select == 1) {
        fileName = STUDENT_FILE;
        tip = "Please enter student ID: ";
        errorTip = "Duplicate student ID, please re-enter: ";
    } else {
        fileName = TEACHER_FILE;
        tip = "Please enter teacher ID: ";
        errorTip = "Duplicate teacher ID, please re-enter: ";
    }

    ofs.open(fileName, ios::out | ios::app);

    int id;
    string name;
    string pwd;

    cout << tip << endl;

    while (true) {
        cin >> id;
        bool repeat = checkRepeat(id, select);
        if (repeat) {
            cout << errorTip;
        } else {
            break;
        }
    }

    cout << "Please enter username: " << endl;
    cin >> name;

    cout << "Please enter password: " << endl;
    cin >> pwd;

    ofs << id << " " << name << " " << pwd << " " << endl;
    cout << "Account successfully created!" << endl;

    ofs.close();
}
void Administrator::showPerson() {}

void Administrator::showComputer() {}

void Administrator::clearRecord() {}

void Administrator::initVector() {
    vStu.clear();
    vTea.clear();

    ifstream ifs;
    ifs.open(STUDENT_FILE, ios::in);
    if (!ifs.is_open()) {
        cout << "File reading failed!" << endl;
        return;
    }

    Student s;
    while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd) {
        vStu.push_back(s);
    }

    cout << "The current number of students is: " << vStu.size() << endl;
    ifs.close();

    ifs.open(TEACHER_FILE, ios::in);
    if (!ifs.is_open()) {
        cout << "File reading failed!" << endl;
        return;
    }

    Teacher t;
    while (ifs >> t.m_EmpId && ifs >> t.m_Name && ifs >> t.m_Pwd) {
        vTea.push_back(t);
    }

    cout << "The current number of teachers is: " << vTea.size() << endl;
    ifs.close();
}

bool Administrator::checkRepeat(int id, int type) {
    if (type == 1) {
        for (vector<Student>::iterator it = vStu.begin(); it != vStu.end();
             it++) {
            if (id == it->m_Id) {
                return true;
            }
        }
    } else {
        for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end();
             it++) {
            if (id == it->m_EmpId) {
                return true;
            }
        }
    }

    return false;
}
