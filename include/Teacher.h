#pragma once
#include <string>
#include "Person.h"

class Teacher : public Person {
   public:
    Teacher();
    Teacher(int empId, const std::string& name, const std::string& pwd);

    void openMenu() override;

    void showAllOrder();
    void validOrder();

    int m_EmpId;
};