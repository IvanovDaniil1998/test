#pragma once

#include "guide.h"

class CATALOG{
private:
    int amount;
	GUIDE *guides;
public:
    CATALOG();
    int get_amount();
    string get_vendor_code(int temp);
    string get_name(int temp);
    void purchased(int temp);
    void show();
};

