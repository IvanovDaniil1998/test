#include "catalog.h"
#include "shop.h"
#include "warehouse.h"

#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

int main()
{
    system("chcp 1251>nul");
    string choise, temp;
    int ch;
    CATALOG *guide_catalog;
    SHOP *shop1;
    SHOP *shop2;
    SHOP *shop3;
    WAREHOUSE *warehouse1;

    guide_catalog = new CATALOG;
    shop1 = new SHOP("shop1.txt", "����� �������");
    shop2 = new SHOP("shop2.txt", "������� ������");
    shop3 = new SHOP("shop3.txt", "��������������");
    warehouse1 = new WAREHOUSE("warehouse.txt");
    shop1->set_next(shop2);
    shop2->set_next(shop3);
    shop3->set_next(warehouse1);

    cout << "������������ ��� � ����� �������� �������� �������������! ������������ � ����� ���������!" << endl;
    cout << "���� ��� ���-�� ��������������, �� ������ ������� ����� ����� ���!" << endl << endl;
    guide_catalog->show();
    cout << "�� ������ ������� �����? (��/���)" << endl;
    cin >> choise;
    while (choise != "���" && choise != "���")
    {
        cout << "\t������� ����� ����������������� ��� ������������: ";
        cin >> ch;
        if(ch > guide_catalog->get_amount())
        {
            cout << "� ���������, ������ ������ ��� � ��������." << endl;
        }
        else
        {
            cout << "\t�� �������: " << guide_catalog->get_name(ch) << endl;
            temp = guide_catalog->get_vendor_code(ch);
            if(shop1->product_search(temp) == true)
            {
                guide_catalog->purchased(ch);
                cout << "\t���������� �� ������������� ������ �������." << endl;
            }
        }
        cout << "������ �������� ���-�� ���? (��/���)" << endl;
        cin >> choise;
    }
    cout << "�� ��������!" << endl;
    return 0;
}
