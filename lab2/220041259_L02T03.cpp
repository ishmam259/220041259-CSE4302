#include <iostream>
using namespace std;

struct fraction{
    int numerator, denominator, answer;
};

int main(){
    fraction fraction1, fraction2, answer;
    char dummy;
    cout << "Enter first fraction: ";

    cin >> fraction1.numerator >> dummy >> fraction1.denominator;

    cout << "Enter second fraction: ";

    cin >> fraction2.numerator >> dummy >> fraction2.denominator;

    answer.numerator = (fraction1.numerator * fraction2.denominator) + (fraction2.numerator * fraction1.denominator);

    answer.denominator = fraction2.denominator * fraction1.denominator;
    
    cout << "Sum" << " " << "=" << " " << answer.numerator << dummy << answer.denominator << endl;
}