#include<iostream>
using namespace std;

class RationalNumber{
    private:
    int numerator,denominator;

    public:
    void assign(int numerator1,int denominator1){
        if(denominator1==0){
            cout<<"You can not assign 0 as denominator."<<endl;
        }
        numerator=numerator1;
        denominator=denominator1;
    }
    double convert(){
        return numerator/denominator;
    }
    
    void print(){
        cout<<"The Rational Number is "<<numerator<<"/"<<denominator<<"."<<endl;
    }
    void invert(){
        if(numerator==0){
            cout<<"You can not assign 0 as denominator."<<endl;
        }
       swap(numerator,denominator);
    }

};

int main(){
    RationalNumber r1;

    r1.assign(3,2);
    r1.convert();
    r1.print();
    r1.invert();
}