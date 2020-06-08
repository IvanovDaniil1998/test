#pragma once

#include "institution.h"

using namespace std;

class WAREHOUSE: public INSTITUTION{
public:
    WAREHOUSE();
    WAREHOUSE(string file_name);
    bool product_search(string temp_code);
};

