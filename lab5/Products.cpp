#define minlength 3
#define maxlength 7

#include<iostream>
#include<string>
#include<string.h>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <algorithm>

using namespace std;

class Products{
    private:
    string name,category_name,description;
    int amount;
    static float price,discount;
    const int max;

    public:

    Products(): name(""),category_name(""),description(""),amount(0),max(100){
    };

    void set_name(string s){
        name=s;
    }
    string get_name(){
        return name;
    }

    void set_category_name(string s){
        category_name=s;
    }
    string get_category_name(){
        return category_name;
    }

    void set_description(string s){
        description=s;
    }
    string get_description(){
        return description;
    }

    void set_amount(int x){
        amount=x;
    }
    int get_amount(){
        return amount;
    }

    void set_price(float x){
        price=x;
    }
    float get_price(){
        return price;
    }

    void set_discount(float x){
        discount=x;
    }
    float get_discount(){
        return discount;
    }

    void PurchaseProduct(int amount1){
        if(amount<=0){
            cout<<"Product cannot be purchased."<<endl;
        }
        else{
            amount-=amount1;
        }
    }

    void RestockProduct(int amount1){
        if(amount>=max){
            cout<<"Product cannot be restocked."<<endl;
        }
        else{
            amount+=amount1;
        }
    }

    double calculateDiscount(int amountofProducts){
        if(amountofProducts>=5){
            price-=(discount/100)*price;
            return price;
        }
        else if(amountofProducts>=10){
            discount+=3;
            price-=(discount/100)*price;
            return price;
        }
        else{
            return price;
        }
    }

    double netTotal(int amountOfProducts){
        return amountOfProducts*price;
    }
};

float Products::price=0.0,discount=0.0;

string random(){
    int wordLength=minlength+rand()%(maxlength-minlength+1);
    string word = "";

    for (int i= 0;i<wordLength;++i){
        char randchar = 'a' + rand() % 26;
        word.push_back(randchar);
    }
    return word;
}

void displayInformation(Products &p1){
    cout<<"Name: "<< p1.get_name() << endl;
    cout<<"Category: "<< p1.get_category_name() << endl;
    cout<<"Description: "<< p1.get_description() << endl;
    cout<<"Amount Stored: "<< p1.get_amount() << endl;
    cout<<"Regular Price: $"<< p1.get_price() << endl;
    cout<<"Discount Rate: "<< p1.get_discount() << "%" << endl;
    cout<<endl;
    return;
}

void editInformationByKeyboard(Products p1[]){
    string name, category_name, description;
    int amount;
    float price, discount;

    cin >> name >> category_name;

    char ch;
    while (cin.get(ch)){
        if (ch == '.'){
            break;
        }
        description.push_back(ch);
    }

    cin>>amount>>price>>discount;

    p1.set_name(name);
    p1.set_category_name(category_name);
    p1.set_description(description);
    p1.set_amount(amount);
    p1.set_price(price);
    p1.set_discount(discount);

    displayInformation(p1);
}

void showAllDiscounts(Products p1[]){
    for (int i = 0; i < sizeof(p1); i++)
        cout << p1[i].calculateDiscount(p1[i].get_amount()) << endl;
    cout << endl;
}

float grossTotal(Products p1[]){
    srand(static_cast<unsigned int>(time(0)));
    int randomAmounts[sizeof(p1)];
    float sumPrice = 0.0;
    char response;

    for (int i = 0; i < sizeof(p1); i++){
        randomAmounts[i] = 1 + (rand() % p1[i].get_amount());
    }

    for (int i = 0; i < sizeof(p1); i++){
        cout << p1[i].netTotal(randomAmounts[i]) << endl;
        sumPrice += p1[i].netTotal(randomAmounts[i]);
    }

    cout << endl;
    cout << "Gross Total: " << sumPrice << endl;
    cout << "Would you like to confirm the purchase? [y/n]: ";
    cin >> response;

    if (response == 'y'){
        for (int i = 0; i < sizeof(p1); i++){
         p1[i].PurchaseProduct(randomAmounts[i]);
        }
    }
    else if (response == 'n'){
        cout << "Purchase command cancelled." << endl;
    }
}

void showAllAlphabetically(Products products[]){
    sort(products, products + sizeof(Products));

    for (int i = 0; i < sizeof(products); i++){
        cout << "Name: " << products[i].get_name() << endl;
        cout << "Stock: " << products[i].get_amount() << endl;
    }

    cout << endl;
}

void generateInformationRandom(Products p1[]){
    string name, category, description;

    for (int i = 0; i < 3; i++){
        name += random();
        if (i<2){
            name+=" ";
        }
    }

    category = random();
}
