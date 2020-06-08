#pragma once

#include "institution.h"

using namespace std;

class SHOP: public INSTITUTION{
private:
    string name;
public:
    SHOP();
    SHOP(string file_name, string temp);
    bool product_search(string temp_code);
};

