#include <iostream>
#include <string>

using namespace std;


class Person {
protected:
    string name;

public:
    Person(string name) : name(name) {}

    virtual void display() const {
        cout << "Name: " << name << endl;
    }
};

class Employee : public Person {
private:
    int employeeID;
protected:
    float salary;

public:
    Employee(string name, int employeeID, float salary) 
        : Person(name), employeeID(employeeID), salary(salary) {}

    void display() const override {
        cout << "Name: " << name << endl;
        cout << "Employee ID: " << employeeID << endl;
        cout << "Salary: " << salary << endl;
    }
};

class Intern : public Employee {
private:
    string schoolName;

public:
    Intern(string name, int employeeID, float salary, string schoolName)
        : Employee(name, employeeID, salary), schoolName(schoolName) {}

    void display() const override {
        Employee::display();
        cout << "School Name: " << schoolName << endl;
    }
};
class Manager : protected Employee {
private:
    string department;

public:
    Manager(string name, int employeeID, float salary, string department)
        : Employee(name, employeeID, salary), department(department) {}

    void display() const override {
        Employee::display();
        cout << "Department: " << department << endl;
    }
};

class Director : public Manager {
private:
    float bonus;

public:
    Director(string name, int employeeID, float salary, string department, float bonus)
        : Manager(name, employeeID, salary, department), bonus(bonus) {}

    void display() const override {
        Manager::display();
        cout << "Bonus: " << bonus << endl;
    }
};

int main() {
    Intern intern("Alice", 1001, 1500.00, "XYZ University");
    cout << "Intern Details:" << endl;
    intern.display();
    cout << endl;

    Manager manager("Bob", 1002, 6000.00, "IT Department");
    cout << "Manager Details:" << endl;
    manager.display();
    cout << endl;

    Director director("Charlie", 1003, 12000.00, "Operations", 5000.00);
    cout << "Director Details:" << endl;
    director.display();
    cout << endl;

    return 0;
}
