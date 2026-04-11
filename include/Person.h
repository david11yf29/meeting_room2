#pragma once
#include <iostream>
#include <string>

class Person {
   public:
    virtual void openMenu() = 0;
    std::string m_Name;
    std::string m_Pwd;
};