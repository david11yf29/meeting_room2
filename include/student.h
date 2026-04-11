#pragma once
#include <string>
#include "Identity.h"

class Student : public Identity {
   public:
    Student();
    Student(int id, const std::string& name, const std::string& pwd);

    void openMenu() override;

    void applyOrder();
    void showMyOrder();
    void showAllOrder();
    void cancelOrder();

    int getId() const;

   private:
    int m_Id;
};