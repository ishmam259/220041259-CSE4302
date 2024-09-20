#include<iostream>;
using namespace std;


class BankAccount{
    private:
    string name,accountnumber,type;
    long long int balance1;


    public:
    void customerDetails(string name1,string accountno){
        name=name1;
        accountnumber=accountno;
    }

    void accountType(string type1){
        type=type1;
    }
    void balance(long long int balance2){
        balance1=balance2;
        cout<<balance1<<endl;
    }
    void deposit(long long int deposit){
        balance1+=deposit;
        cout<<balance1<<endl;
    }
    void withdraw(long long int withdraw){
        cout<<balance1<<endl;
        balance1-=withdraw;
    }
    void display(){
        cout<<"Name: "<<name<<endl;
        cout<<"Account Number: "<<accountnumber<<endl;
        cout<<"Account Type: "<<type<<endl;
        cout<<"Balance: "<<balance1<<endl;
    }
};

int main(){
    BankAccount customer;

    customer.customerDetails("Montu","220041259");
    customer.accountType("Current");
    customer.balance(2000);
    customer.deposit(10);
    customer.withdraw(5);
    customer.display();
}