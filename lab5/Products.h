#ifndef Products_H
#define Products_H

#include <string>

using namespace std;
class Products {

private:
    string name;
    string category_name;
    string description;
    int amount;
    float price;
    float discount;

public:

    Products();

    void set_name(string s);
    string get_name();
    void set_category_name(string s);
    string get_category_name();
    void set_description(string s);
    string get_description();
    void set_amount(int x);
    int get_amount();
    void set_price(float x);
    float get_price();
    void set_discount(float x);
    float get_discount();
    void PurchaseProduct(int amount1);
    void RestockProduct(int amount1);
    double calculateDiscount(int amountofProducts);
    double netTotal(int amountOfProducts);




    
};

void EditInformationByKeyboard (Products &product);

void generateInformationRandom (Products &product);

void ShowAllDiscount(Products ar[], int size);

void grossTotal(Products ar[], int size);

void ShowAllAlphabetically(Products ar[], int size);

#endif 
