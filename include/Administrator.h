#pragma once
#include <string>
#include "Person.h"

class Administrator : public Person {
   public:
    Administrator();
    Administrator(const std::string& name, const std::string& pwd);

    void openMenu() override;

    void addPerson();
    void showPerson();

    void showComputer();

    void clearRecord();
};