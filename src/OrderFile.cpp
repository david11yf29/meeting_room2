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
        string key;
        string value;
        map<string, string> m;

        // intercept date
        int pos = date.find(":");
        if (pos != -1) {
            key = date.substr(0, pos);
            value = date.substr(pos + 1, date.size() - pos - 1);

            m.insert(make_pair(key, value));
        }

        // intercept period
        pos = interval.find(":");
        if (pos != -1) {
            key = interval.substr(0, pos);
            value = interval.substr(pos + 1, interval.size() - pos - 1);
            m.insert(make_pair(key, value));
        }

        // intercept student ID
        pos = stuId.find(":");
        if (pos != -1) {
            key = stuId.substr(0, pos);
            value = stuId.substr(pos + 1, stuId.size() - pos - 1);
            m.insert(make_pair(key, value));
        }

        // intercept student name
        pos = stuName.find(":");
        if (pos != -1) {
            key = stuName.substr(0, pos);
            value = stuName.substr(pos + 1, stuName.size() - pos - 1);
            m.insert(make_pair(key, value));
        }

        // intercept computer room number
        pos = roomId.find(":");
        if (pos != -1) {
            key = roomId.substr(0, pos);
            value = roomId.substr(pos + 1, roomId.size() - pos - 1);
            m.insert(make_pair(key, value));
        }

        // intercept review status
        pos = status.find(":");
        if (pos != -1) {
            key = status.substr(0, pos);
            value = status.substr(pos + 1, status.size() - pos - 1);
            m.insert(make_pair(key, value));
        }

        this->m_orderData.insert(make_pair(this->m_Size, m));
        this->m_Size++;
    }

    ifs.close();

    // test
    for (map<int, map<string, string> >::iterator it = m_orderData.begin();
         it != m_orderData.end(); it++) {
        cout << "Number of record = " << it->first << " value = " << endl;
        for (map<string, string>::iterator mit = (*it).second.begin();
             mit != it->second.end(); mit++)
            cout << " key = " << mit->first << " value = " << mit->second
                 << " ";
        cout << endl;
    }
}

void OrderFile::updateOrder() {}
