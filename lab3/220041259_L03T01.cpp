#include<iostream>
using  namespace std;

class Temperature{
    private:
    double temperature;
    double increment;

    public:
    void setIncrementStep(double increment1){
        increment=increment1;
    }
    double getTemperature(){
        return temperature;

    }
    void increment(){
        temperature+=increment;
    }
    void resetTemperature(){
        temperature=0;
    }

};

int main(){
    Temperature t1;
    t1.getTemperature();
    t1.setIncrementStep(5);
}