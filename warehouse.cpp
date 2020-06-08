#include "institution.h"
#include "warehouse.h"

#include <string>
#include <iostream>
#include <fstream>

using namespace std;


WAREHOUSE::WAREHOUSE()
{
    amount = 0;
    store = NULL;
    next = NULL;
}

WAREHOUSE::WAREHOUSE(string file_name)
{
    ifstream file;
    string temp_string;
    int temp_int;

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

bool WAREHOUSE::product_search(string temp_code)
{
    string choise;
    for(int i=0; i<amount; ++i)
    {
        if (store[i].vendor_code == temp_code && store[i].quantity > 0)
        {
            cout << "\tТовар в наличии на складе. Забронировать товар для самовывоза? (Да/Нет)" << endl << "\t";
            cin >> choise;
            if (choise == "Да" || choise == "да")
            {
                store[i].quantity--;
                cout << "\tТовар забронирован." << endl;
                return true;
            }
            else
            {
                cout << "\tЗаказ отменён." << endl;
                return false;
            }
        }
    }
    if(next != NULL)
    {
        if (next->product_search(temp_code) == true)
            return true;
    }
    cout << "\tИзвините, товара нет в наличии." << endl;
    return false;
}
