#pragma once
#include <string>
#include "Person.h"

class Manager : public Person {
   public:
    Manager();
    Manager(const std::string& name, const std::string& pwd);

    void openMenu() override;

    void addPerson();
    void showPerson();

    void showComputer();

    void clearRecord();
};