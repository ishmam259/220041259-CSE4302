#include<iostream>
using namespace std;


class Car{
    private:
        string make;
        string model;
        double fuelCapacity;
        double fuelLevel;

    public:

    Car(string make, string model, double fuelCapacity, double fuelLevel){
        this->make = make;
        this->model = model;
        this->fuelCapacity = fuelCapacity;
        this->fuelLevel = fuelLevel;
    }

    Car(){
        fuelLevel = 0;
    }

    void operator+(float addFuel){
        if (this->fuelLevel + addFuel > this->fuelCapacity){
            this->fuelLevel = this->fuelCapacity;
        }
        else{
            this->fuelLevel = this->fuelLevel + addFuel;
        }
    }

    void operator-(float decreaseFuel){
        if (this->fuelLevel - decreaseFuel < 0){
            this->fuelLevel = 0;
        }
        else{
            this->fuelLevel = this->fuelLevel - decreaseFuel;
        }

    }
    void operator+=(float addFuel){
        if (this->fuelLevel + addFuel > this->fuelCapacity){
            this->fuelLevel = this->fuelCapacity;
        }
        else{
            this->fuelLevel = this->fuelLevel + addFuel;
        }
    }

    bool operator==(Car const &second){
        return (this->make == second.make && this->model == second.model && this->fuelCapacity == second.fuelCapacity);
    }

    bool operator<(Car const &second){
        return (this->fuelLevel < second.fuelLevel);
    }

    bool operator>(Car const &second){
        return (this->fuelLevel > second.fuelLevel);
    }

    friend ostream &operator<<(ostream &out, const Car &car){
        out << "Make: " << car.make << endl;
        out << "Model: " << car.model << endl;
        out << "Fuel Capacity: " << car.fuelCapacity << " liters" << endl;
        out << "Fuel Level: " << car.fuelLevel << " liters" << endl;
        cout << endl;
        return out;
    }

    friend istream &operator>>(istream &in, Car &car){
        cout << "Enter car's manufacturer: ";
        in >> car.make;
        cout << "Enter car's model: ";
        in >> car.model;
        cout << "Enter car's fuel capacity: ";
        in >> car.fuelCapacity;
        cout << "Enter car's current fuel level: ";
        in >> car.fuelLevel;
        cout << endl;
        return in;
    }
};

int main(void){
    Car car1, car2;

    cin >> car1 >> car2;
    cout << car1 << car2;

    if (car1 == car2){
        cout << "1" << endl;
    }
    else if (car1 < car2){
        cout << "2" << endl;
    }
    else{
        cout << "3" << endl;
    }

    car2 += 5;

    if (car1 > car2){
        cout <<"Car1 has more fuel than Car2" << endl;
    }

    car1 - 5;

    if (car1 == car2){
        cout <<"Car1 is identical to Car2" << endl;
    }

    return 0;
}