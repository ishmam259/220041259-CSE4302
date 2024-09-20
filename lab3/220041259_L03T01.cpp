#include<iostream>
using  namespace std;

class Temperature{
    private:
    double temperature;
    double increment1;

    public:
    void setIncrementStep(double increment2){
        increment1=increment2;
    }
    double getTemperature(){
        return temperature;

    }
    void increment(){
        temperature+=increment1;
    }
    void resetTemperature(){
        temperature=0;
    }

};

int main(){
    Temperature t1;
    t1.getTemperature();
    t1.setIncrementStep(5);
    t1.increment();
    t1.resetTemperature();
}