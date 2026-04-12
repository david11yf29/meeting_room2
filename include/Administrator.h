#pragma once
#include <string>
#include "Person.h"
#include <fstream>
#include "DataPaths.h"
#include "Student.h"
#include "Teacher.h"
#include <vector>

class Administrator : public Person {
   public:
    Administrator();
    Administrator(const std::string& name, const std::string& pwd);

    void openMenu() override;

    void addPerson();
    void showPerson();

    void showComputer();

    void clearRecord();

    void initVector();

    std::vector<Student> vStu;

    std::vector<Teacher> vTea;
};