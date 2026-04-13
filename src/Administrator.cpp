#include "Administrator.h"
#include <iostream>
#include <fstream>
using namespace std;

Administrator::Administrator() {}
Administrator::Administrator(const std::string& name, const std::string& pwd) {
    this->m_Name = name;
    this->m_Pwd = pwd;

    this->initVector();

    ifstream ifs;
    ifs.open(COMPUTER_FILE, ios::in);
    if (!ifs.is_open()) {
        cout << "File reading failed!" << endl;
        return;
    }

    ComputerRoom com;
    while (ifs >> com.m_ComId && ifs >> com.m_MaxNum) {
        vCom.push_back(com);
    }
    ifs.close();
    cout << "The number of computer room is: " << vCom.size() << endl;
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

    this->initVector();
}

void printStudent(Student& stu) {
    cout << "Student ID: " << stu.m_Id << " Name: " << stu.m_Name
         << " Password: " << stu.m_Pwd << endl;
}

void printTeacher(Teacher& tea) {
    cout << "Teacher ID: " << tea.m_EmpId << " Name: " << tea.m_Name
         << " Password: " << tea.m_Pwd << endl;
}

void Administrator::showPerson() {
    cout << "Please select the content to display: " << endl;
    cout << "1. View all students" << endl;
    cout << "2. View all teachers" << endl;

    int select = 0;
    cin >> select;

    if (select == 1) {
        cout << "All student information are as follows: " << endl;
        for_each(vStu.begin(), vStu.end(), printStudent);
    } else {
        cout << "All teacher information are as follows: " << endl;
        for_each(vTea.begin(), vTea.end(), printTeacher);
    }
}

void Administrator::showComputer() {
    cout << "Computer Information Show: " << endl;
    for (vector<ComputerRoom>::iterator it = vCom.begin(); it != vCom.end();
         it++) {
        cout << "Computer Id: " << it->m_ComId << endl;
        cout << "Computer Capacity: " << it->m_MaxNum << endl;
    }
}

void Administrator::clearRecord() {
    ofstream ofs(ORDER_FILE, ios::trunc);
    ofs.close();

    cout << "Had Cleaned the Order Information" << endl;
}

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
