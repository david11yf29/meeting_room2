#pragma once
#include <string>
#include "DataPaths.h"
#include <map>

class OrderFile {
   public:
    OrderFile();

    void updateOrder();

    int m_Size;

    std::map<int, std::map<std::string, std::string>> m_orderData;
};