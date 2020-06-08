#include "catalog.h"
#include "guide.h"

#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include <fstream>

using namespace std;

CATALOG::CATALOG()
{
    ifstream file;
    string temp_string;
    int temp_int;
    bool temp_bool;

    file.open("site.txt");
    if (!file.is_open())
    {
        cout << "Файл site.txt не найден!" << endl;
        amount = 0;
        guides = NULL;
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
            guides = new GUIDE;
            amount++;
            getline(file, temp_string, '\t');
            guides->set_name(temp_string);
            getline(file, temp_string, '\t');
            guides->set_publishing_house(temp_string);
            file >> temp_int;
            guides->set_year(temp_int);
            file >> temp_int;
            guides->set_num_pages(temp_int);
            getline(file, temp_string, '\t');
            getline(file, temp_string, '\t');
            if (temp_string == "да")
                temp_bool = true;
            else
                temp_bool = false;
            guides->set_illustrations(temp_bool);
            getline(file, temp_string, '\t');
            if (temp_string == "да")
                temp_bool = true;
            else
                temp_bool = false;
            guides->set_city_map(temp_bool);
            getline(file, temp_string, '\t');
            guides->set_binding(temp_string);
            getline(file, temp_string, '\t');
            guides->set_format(temp_string);
            getline(file, temp_string, '\t');
            guides->set_author(temp_string);
            file >> temp_int;
            guides->set_quantity(temp_int);
            getline(file, temp_string, '\t');
            getline(file, temp_string);
            guides->set_vendor_code(temp_string);
        }
        while (!file.eof())
        {
            GUIDE *temp;
            temp = new GUIDE[amount];
            for (int i=0; i<amount; ++i)
                temp[i] = guides[i];
            amount++;
            guides = new GUIDE[amount];
            for (int i=0; i<(amount-1); ++i)
                guides[i] = temp[i];

            getline(file, temp_string, '\t');
            guides[amount-1].set_name(temp_string);
            getline(file, temp_string, '\t');
            guides[amount-1].set_publishing_house(temp_string);
            file >> temp_int;
            guides[amount-1].set_year(temp_int);
            file >> temp_int;
            guides[amount-1].set_num_pages(temp_int);
            getline(file, temp_string, '\t');
            getline(file, temp_string, '\t');
            if (temp_string == "да")
                temp_bool = true;
            else
                temp_bool = false;
            guides[amount-1].set_illustrations(temp_bool);
            getline(file, temp_string, '\t');
            if (temp_string == "да")
                temp_bool = true;
            else
                temp_bool = false;
            guides[amount-1].set_city_map(temp_bool);
            getline(file, temp_string, '\t');
            guides[amount-1].set_binding(temp_string);
            getline(file, temp_string, '\t');
            guides[amount-1].set_format(temp_string);
            getline(file, temp_string, '\t');
            guides[amount-1].set_author(temp_string);
            file >> temp_int;
            guides[amount-1].set_quantity(temp_int);
            getline(file, temp_string, '\t');
            getline(file, temp_string);
            guides[amount-1].set_vendor_code(temp_string);
        }
        file.close();
    }
}

int CATALOG::get_amount()
{
    return amount;
}

string CATALOG::get_vendor_code(int temp)
{
    return guides[temp-1].get_vendor_code();
}

string CATALOG::get_name(int temp)
{
    return guides[temp-1].get_name();
}

void CATALOG::purchased(int temp)
{
    guides[temp-1].purchased(1);
}

void CATALOG::show()
{
    if (guides == NULL)
    {
        cout << "Каталог пуст" << endl;
    }
    else
    {
        cout << " №|               название              | издательство |  год | стр.| фото|карта| переплет| формат  |   автор    | к-во" << endl;
        cout << "________________________________________________________________________________________________________________________" << endl;
        for(int i=0; i<amount; ++i)
        {
            printf("%2d| %-35s | %-12s | %d | %3d |", i+1, (guides[i].get_name()).c_str(), (guides[i].get_publishing_house()).c_str(), guides[i].get_year(), guides[i].get_num_pages());
            if (guides[i].get_illustrations() == true)
                cout << "  да |";
            else
                cout << " нет |";
            if (guides[i].get_city_map() == true)
                cout << "  да |";
            else
                cout << " нет |";
            printf(" %-7s | %-7s | %-10s | %3d", (guides[i].get_binding()).c_str(), (guides[i].get_format()).c_str(), (guides[i].get_author()).c_str(), guides[i].get_quantity());
            cout << endl;
        }
    }
    return;
}


