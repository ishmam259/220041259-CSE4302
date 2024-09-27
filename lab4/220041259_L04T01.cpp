#include<iostream>
using namespace std;

class Product{
    private:
    struct product{
        string productname,id;
        int quantity,price,totalinventoryprice,max;
    };
    public:
    product p1;
    Product(){
        p1.quantity=0;
        p1.totalinventoryprice=0;
        p1.productname="";
        p1.price=0;
        p1.max=0;
        p1.id="";
    }
    Product(string name,string id,int quantity,int price,int max){
        p1.quantity=quantity;
        p1.productname=name;
        p1.price=price;
        p1.max=max;
        p1.id=id;
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
    Product p2[3];
    
    p2[0]=Product("Apple","1001",20,10,100);

    p2[0].displayDetails(); 
    p2[0].addToInventory(50);
    p2[0].isAvailable(); 
    p2[0].purchase(40); 
    p2[0].updatePrice(5); 
    p2[0].displayInventoryValue();
    p2[0].displayTotalInventoryValue();

    p2[1]=Product("Lenovo","1001",20,10,100);

    p2[1].displayDetails(); 
    p2[1].addToInventory(50);
    p2[1].isAvailable(); 
    p2[1].purchase(40); 
    p2[1].updatePrice(5); 
    p2[1].displayInventoryValue();
    p2[1].displayTotalInventoryValue();

    p2[2]=Product("Samsung","101",20,10,100);

    p2[2].displayDetails(); 
    p2[2].addToInventory(50);
    p2[2].isAvailable(); 
    p2[2].purchase(40); 
    p2[2].updatePrice(5); 
    p2[2].displayInventoryValue() ;
    
    
    
}