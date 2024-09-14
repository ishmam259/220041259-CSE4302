#include <iostream>
using namespace std;

enum etype{
    laborer,
    secretary,
    manager,
    accountant,
    executive,
    researcher
};

int main(){
    char type;
    etype l = laborer, s = secretary, m = manager, a = accountant, e = executive, r = researcher;
    cout << "Enter employee type : ";
    cin >> type;
    cout << "Employee type is ";
    switch (type){
    case 'l':
        cout << "laborer";
        break;
    case 's':
        cout << "secretary";
        break;
    case 'm':
        cout << "manager";
        break;
    case 'a':
        cout << "accountant";
        break;
    case 'e':
        cout << "executive";
        break;
    case 'r':
        cout << "researcher";
        break;
    }
}