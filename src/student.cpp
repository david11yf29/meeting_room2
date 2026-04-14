#include <iostream>
#include "Student.h"
using namespace std;

Student::Student() {}
Student::Student(int id, const std::string& name, const std::string& pwd) {
    this->m_Id = id;
    this->m_Name = name;
    this->m_Pwd = pwd;

    ifstream ifs;
    ifs.open(COMPUTER_FILE, ios::in);

    ComputerRoom com;
    while (ifs >> com.m_ComId && ifs >> com.m_MaxNum) {
        vCom.push_back(com);
    }

    ifs.close();
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

void Student::applyOrder() {
    cout << "The computer room is open from Monday to Friday!" << endl;
    cout << "Please enter the time to apply for a reservation: " << endl;
    cout << "1. Monday" << endl;
    cout << "2. Tuesday" << endl;
    cout << "3. Wednesday" << endl;
    cout << "4. Thursday" << endl;
    cout << "5. Friday" << endl;

    int date = 0;
    int interval = 0;
    int room = 0;

    while (true) {
        if (cin >> date) {
            if (date >= 1 && date <= 5) {
                break;  // Input data is correct!
            }
            cout << "Incorrect input, please re-enter" << endl;
        } else {
            cout << "Invalid Input" << endl;
            cin.clear();
        }
    }

    cout << "Please enter the time period to applying for a reservation: "
         << endl;
    cout << "1. Morning" << endl;
    cout << "2. Afternoon" << endl;

    while (true) {
        if (cin >> interval) {
            if (interval >= 1 && interval <= 2) {
                break;
            }
            cout << "Incorrect input, please re-enter" << endl;
        } else {
            cout << "Invalid Input" << endl;
            cin.clear();
        }
    }

    cout << "Please choose the computer room:" << endl;
    for (int i = 0; i < vCom.size(); i++) {
        cout << "Computer room " << vCom[i].m_ComId
             << " capacity: " << vCom[i].m_MaxNum << endl;
    }

    while (true) {
        if (cin >> room) {
            if (room >= 1 && room <= 3) {
                break;
            }
            cout << "Incorrect input, please re-enter" << endl;
        } else {
            cout << "Invalid input" << endl;
            cin.clear();
        }
    }

    cout << "Your reservation is successfully applied and is under review by "
            "teachers!"
         << endl;

    ofstream ofs;
    ofs.open(ORDER_FILE, ios::app);

    ofs << "date:" << date << " ";
    ofs << "interval:" << interval << " ";
    ofs << "stuId:" << this->m_Id << " ";
    ofs << "stuName:" << this->m_Name << " ";
    ofs << "roomId:" << room << " ";
    ofs << "status:" << 1 << endl;

    ofs.close();
}

void Student::showMyOrder() {
    OrderFile of;
    if (of.m_Size == 0) {
        cout << "No reservation record!" << endl;
        return;
    }

    for (int i = 0; i < of.m_Size; i++) {
        if (this->m_Id == atoi(of.m_orderData[i]["stuId"].c_str())) {
            cout << i + 1 << ". ";
            cout << "Reservation date: " << of.m_orderData[i]["date"];
            cout << ", Period: "
                 << (of.m_orderData[i]["interval"] == "1" ? "Morning"
                                                          : "Afternoon");
            cout << ", Computer room number: " << of.m_orderData[i]["roomId"];
            cout << ", Student ID: " << of.m_orderData[i]["stuId"];
            cout << ", Student name: " << of.m_orderData[i]["stuName"];

            string status = ", Status: ";
            // 1--under review, 2--already reserved, -1--reserve failed,
            // 0--cancel reservation
            if (of.m_orderData[i]["status"] == "1")
                status += "under review";
            else if (of.m_orderData[i]["status"] == "2")
                status += "already reserved";
            else if (of.m_orderData[i]["status"] == "-1")
                status += "reserve failed, not approved";
            else
                status += "reservation canceled";

            cout << status << endl;
        }
    }
}

void Student::showAllOrder() {
    OrderFile of;

    if (of.m_Size == 0) {
        cout << "No reservation record!" << endl;
        return;
    }

    for (int i = 0; i < of.m_Size; i++) {
        cout << i + 1 << ". ";
        cout << "Reservation date: " << of.m_orderData[i]["date"];
        cout << ", Period: "
             << (of.m_orderData[i]["interval"] == "1" ? "Morning"
                                                      : "Afternoon");
        cout << ", Student ID: " << of.m_orderData[i]["stuId"];
        cout << ", Student name: " << of.m_orderData[i]["stuName"];
        cout << ", Computer room number: " << of.m_orderData[i]["roomId"];

        string status = ", Status: ";

        // 1--under review, 2--already reserved, -1--reserve failed, 0--cancel
        // reservation
        if (of.m_orderData[i]["status"] == "1")
            status += "under review";
        else if (of.m_orderData[i]["status"] == "2")
            status += "already reserved";
        else if (of.m_orderData[i]["status"] == "-1")
            status += "reserve failed, not approved";
        else
            status += "reservation canceled";

        cout << status << endl;
    }
}

void Student::cancelOrder() {}
