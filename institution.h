#pragma once

#include <string>

using namespace std;

struct RECORD{
    string vendor_code;
    int quantity;
};


class INSTITUTION{
protected:
    int amount;
    RECORD *store;
    INSTITUTION *next;
public:
    void set_next(INSTITUTION *temp){next = temp;};
    virtual bool product_search(string temp_code) = 0;
};

