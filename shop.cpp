#include "institution.h"
#include "shop.h"

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

SHOP::SHOP()
{
    amount = 0;
    store = NULL;
    next = NULL;
    name = "Безымянный";
}

SHOP::SHOP(string file_name, string temp)
{
    ifstream file;
    string temp_string;
    int temp_int;

    name = temp;
    next = NULL;
    file.open(file_name.c_str());
    if (!file.is_open())
    {
        cout << "Файл " << file_name << " не найден!" << endl;
        amount = 0;
        store = NULL;
    }
    else
    {
        amount = 0;
        if (!file.eof())
        {
            getline(file, temp_string);
        }
        if (!file.eof())
        {
            store = new RECORD;
            amount++;
            getline(file, temp_string, ' ');
            store->vendor_code = temp_string;
            file >> temp_int;
            store->quantity = temp_int;
            getline(file, temp_string);
        }
        while (!file.eof())
        {
            RECORD *temp;
            temp = new RECORD[amount];
            for (int i=0; i<amount; ++i)
                temp[i] = store[i];
            amount++;
            store = new RECORD[amount];
            for (int i=0; i<(amount-1); ++i)
                store[i] = temp[i];

            getline(file, temp_string, ' ');
            store[amount-1].vendor_code = temp_string;
            file >> temp_int;
            store[amount-1].quantity = temp_int;
            getline(file, temp_string);
        }
        file.close();
    }
}

bool SHOP::product_search(string temp_code)
{
    for(int i=0; i<amount; ++i)
    {
        if (store[i].vendor_code == temp_code && store[i].quantity > 0)
        {
            store[i].quantity--;
            cout << "\tОформлена доставка из магазина " << name << "."  << endl;
            return true;
        }
    }
    if(next != NULL)
    {
        if (next->product_search(temp_code) == true)
            return true;
    }
    return false;
}
