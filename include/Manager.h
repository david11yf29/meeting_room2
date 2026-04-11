#pragma once
#include <string>
#include "Identity.h"

class Manager : public Identity {
   public:
    Manager();
    Manager(const std::string& name, const std::string& pwd);

    void openMenu() override;

    void addPerson();

    void showAllOrder();
    void validOrder();

    int getId() const;

   private:
    int m_EmpId;
};