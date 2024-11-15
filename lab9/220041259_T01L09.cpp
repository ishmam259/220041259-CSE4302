#include<iostream>
using namespace std;

class SmartDevice{
    protected:
    string deviceID,brandName;
    int powerRating ;
    public:
    virtual void diagnose() = 0;
    
};


