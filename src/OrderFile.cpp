#include "OrderFile.h"
#include <fstream>
#include <iostream>

using namespace std;

OrderFile::OrderFile() {
    ifstream ifs;
    ifs.open(ORDER_FILE, ios::in);

    string date;
    string interval;
    string stuId;
    string stuName;
    string roomId;
    string status;

    this->m_Size = 0;

    while (ifs >> date && ifs >> interval && ifs >> stuId && ifs >> stuName &&
           ifs >> roomId && ifs >> status) {
        cout << date << endl;
        cout << interval << endl;
        cout << stuId << endl;
        cout << stuName << endl;
        cout << roomId << endl;
        cout << status << endl;
        cout << endl;
    }
}

void OrderFile::updateOrder() {}
