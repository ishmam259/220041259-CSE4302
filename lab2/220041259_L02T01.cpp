#include<iostream>
using namespace std;


int main(){
    int a,b,c,d;
    char dummy;
    cout<<"Enter first fraction: ";
    cin>>a>>dummy>>b;
    cout<<"Enter second fraction: ";
    cin>>c>>dummy>>d;
    cout<<"Sum"<<" "<<"="<<" "<<(a*d+b*c)<<dummy<<b*d<<endl;
}