#include<iostream>
using namespace std;

class Product{
    public:
    struct product{
        string productname,id;
        int quantity,price,totalinventoryprice,max;
    };
    product p1;
    Product(){
        p1.quantity=0;
        p1.totalinventoryprice=0;
    }
    void addToInventory(int addedQuantity){
        if(addedQuantity+p1.quantity<=p1.max){
            p1.quantity+=addedQuantity;
        }
        else{
            p1.quantity=p1.max;
        }
    }
    bool isAvailable(){
        if(p1.quantity>=0){
            return true;
        }
        else{
            return false;
        }
    } 
    void purchase(int purchasedQuantity){
        p1.quantity-=purchasedQuantity;
    } 
    void updatePrice(int discountPercent){
        p1.price+=(discountPercent*p1.price)/100;

    } 
    void displayInventoryValue(){
        cout<<"Inventory Value: "<<p1.quantity*p1.price<<endl;
    } 
    void displayDetails(){
        cout<<"Name: "<<p1.productname<<endl;
        cout<<"ID: "<<p1.id<<endl;
        cout<<"Unit Price: "<<p1.price<<endl;
        cout<<"Quantity: "<<p1.quantity<<endl;
        if(isAvailable()==1){
            cout<<"Available"<<endl;
        }
        else{
            cout<<"Not Available"<<endl;
        }
    }
    void displayTotalInventoryValue(){
        p1.totalinventoryprice+=p1.quantity*p1.price;
        cout<<"Total Inventory Price: "<<p1.totalinventoryprice<<endl;   
        cout<<endl;    
    } 
};

int main(){
    Product p2,p3,p4;
    p2.p1.productname="Apple";
    p2.p1.id="2200";
    p2.p1.price=10;
    p2.p1.quantity=30;
    p2.p1.max=100;

    p2.displayDetails(); 
    p2.addToInventory(50);
    p2.isAvailable(); 
    p2.purchase(40); 
    p2.updatePrice(5); 
    p2.displayInventoryValue() ;
    
    p2.displayTotalInventoryValue();

    p2.p1.productname="Lenovo";
    p2.p1.id="2100";
    p2.p1.price=20;
    p2.p1.quantity=40;
    p2.p1.max=100;

    p2.displayDetails(); 
    p2.addToInventory(50);
    p2.isAvailable(); 
    p2.purchase(40); 
    p2.updatePrice(5); 
    p2.displayInventoryValue();
    p2.displayTotalInventoryValue();

    p2.p1.productname="Samsung";
    p2.p1.id="2000";
    p2.p1.price=40;
    p2.p1.quantity=20;
    p2.p1.max=100;

    p2.displayDetails(); 
    p2.addToInventory(50);
    p2.isAvailable(); 
    p2.purchase(40); 
    p2.updatePrice(5); 
    p2.displayInventoryValue();
    p2.displayTotalInventoryValue();
}