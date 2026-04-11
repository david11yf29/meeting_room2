#pragma once
#include <iostream>
#include <string>

class identity {
   public:
    virtual void openMenu() = 0;
    std::string m_Name;
    std::string m_Pwd;
};