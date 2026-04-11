#pragma once
#include <string>
#include "Identity.h"

class Teacher : public Identity {
   public:
    Teacher();
    Teacher(int empId, const std::string& name, const std::string& pwd);

    void openMenu() override;

    void showAllOrder();
    void validOrder();

    int getId() const;

   private:
    int m_EmpId;
};