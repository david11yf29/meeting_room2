#pragma once
#include <string>
#include "Person.h"

class Student : public Person {
   public:
    Student();
    Student(int id, const std::string& name, const std::string& pwd);

    void openMenu() override;

    void applyOrder();
    void showMyOrder();
    void showAllOrder();
    void cancelOrder();

    int m_Id;
};