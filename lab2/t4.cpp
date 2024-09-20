#include<iostream>
using namespace std;

int n,year,mileage;
string brandname,carname,fuelname,dummy;

void carinfo(int n,string brandname,string carname,int year,string fuelname,int mileage){
    cout<<"Car"<<" ";
    cin>>n;
    cout<<":"<<endl;
    cout<<"Brand: ";
    cin>>brandname;
    cout<<"Model: ";
    cin>>carname;
    cout<<"Year: ";
    cin>>year;
    cout<<"Fuel Type: ";
    cin>>fuelname;
    cout<<"Mileage: ";
    cin>>mileage>>dummy;
}

void fueleff(int mileage,string fuelname){
    if(mileage>15 && fuelname!="electric"){
        cout<<"This car is fuel-efficient."<<endl;
    }
    else if(mileage<=15 && fuelname!="electric"){
        cout<<"This car is not fuel-efficient."<<endl;
    }
    else if(fuelname=="electric"){
        cout<<"This car is electric, efficiency measured in km/charge."<<endl;
        cout<<"This car is not fuel-efficient."<<endl;
    }
}

int main(){
    for(int i=0;i<3;i++){
        carinfo(n,brandname,carname,year,fuelname,mileage);
        fueleff(mileage,fuelname);
    }


    
    






}