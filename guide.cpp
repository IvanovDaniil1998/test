#include "guide.h"

#include <string>

using namespace std;

void GUIDE::set_name(string temp)
{
    name = temp;
}
void GUIDE::set_publishing_house(string temp)
{
    publishing_house = temp;
}
void GUIDE::set_year(int temp)
{
    year = temp;
}
void GUIDE::set_num_pages(int temp)
{
    num_pages = temp;
}
void GUIDE::set_illustrations(bool temp)
{
    illustrations = temp;
}
void GUIDE::set_city_map(bool temp)
{
    city_map = temp;
}
void GUIDE::set_binding(string temp)
{
    binding = temp;
}
void GUIDE::set_format(string temp)
{
    format = temp;
}
void GUIDE::set_author(string temp)
{
    author = temp;
}
void GUIDE::set_quantity(int temp)
{
    quantity = temp;
}
void GUIDE::set_vendor_code(string temp)
{
    vendor_code = temp;
}

string GUIDE::get_name()
{
    return name;
}
string GUIDE::get_publishing_house()
{
    return publishing_house;
}
int GUIDE::get_year()
{
    return year;
}
int GUIDE::get_num_pages()
{
    return num_pages;
}
bool GUIDE::get_illustrations()
{
    return illustrations;
}
bool GUIDE::get_city_map()
{
    return city_map;
}
string GUIDE::get_binding()
{
    return binding;
}
string GUIDE::get_format()
{
    return format;
}
string GUIDE::get_author()
{
    return author;
}
int GUIDE::get_quantity()
{
    return quantity;
}
string GUIDE::get_vendor_code()
{
    return vendor_code;
}

void GUIDE::purchased(int order)
{
    quantity -= order;
}
