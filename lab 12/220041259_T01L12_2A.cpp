#include <iostream>
#include <fstream>
#include <vector>
#include <deque>
#include <list>
#include <algorithm>
using namespace std;

class Creature {
private:
    string name;
    string species;
    string healthStatus;
    int age;

public:
    Creature(string name, string species, string healthstatus, int age) 
        : name(name), species(species), healthStatus(healthstatus), age(age) {}

    string GetName() const { return name; }
    string GetSpecies() const { return species; }
    string gethealth() const { return healthStatus; }
    int GetAge() const { return age; }

    void setHealthRecovery(string healthstatus) { healthStatus = healthstatus; }

    void Display() const {
        cout << "Name: " << name << endl;
        cout << "Species: " << species << endl;
        cout << "Health Status: " << healthStatus << endl;
        cout << "Age: " << age << endl;
    }

    string toString() const {
        return name + " " + species + " " + healthStatus + " " + to_string(age);
    }

    bool operator==(const Creature& other) const {
        return name == other.name && species == other.species;
    }
};

class Sanctuary {
private:
    vector<Creature> inhabitants;
    deque<Creature> recoveryZone;
    list<Creature> releasedCreatures;

public:
    void addInSanctuary(Creature creature) {
        inhabitants.push_back(creature);
    }

    void AddInRecovery(Creature creature) {
        recoveryZone.push_back(creature);
    }

    void RecoveryToSanctuary(const Creature& creature) {
        auto it = find(recoveryZone.begin(), recoveryZone.end(), creature);
        if (it != recoveryZone.end()) {
            Creature temp = *it;
            recoveryZone.erase(it);
            inhabitants.push_back(temp);
        } else {
            cout << "Creature not found in recovery zone.\n";
        }
    }

    void ReleaseCreature(const Creature& creature) {
        auto it = find(inhabitants.begin(), inhabitants.end(), creature);
        if (it != inhabitants.end()) {
            Creature temp = *it;
            inhabitants.erase(it);
            releasedCreatures.push_back(temp);
        } else {
            cout << "Creature not found in sanctuary.\n";
        }
    }

    void display() const {
        cout << "Sanctuary Creatures:\n";
        for (const auto& c : inhabitants) {
            c.Display();
            cout << endl;
        }

        cout << "Recovering Creatures:\n";
        for (const auto& c : recoveryZone) {
            c.Display();
            cout << endl;
        }

        cout << "Released Creatures:\n";
        for (const auto& c : releasedCreatures) {
            c.Display();
            cout << endl;
        }
    }

    void releaseCreature() {
        inhabitants.erase(remove_if(inhabitants.begin(), inhabitants.end(), [&](const Creature& c) { return c.gethealth() == "healthy"; }), inhabitants.end());
    }

    void addCreature() {
        string name, species, healthstatus;
        int age;
        cin >> name >> species >> healthstatus >> age;
        inhabitants.emplace_back(name, species, healthstatus, age);
    }

    void sendToRecovery() {
        string name, species, healthstatus;
        int age;
        cin >> name >> species >> healthstatus >> age;

        Creature creature(name, species, healthstatus, age);
        if (healthstatus == "injured" || healthstatus == "resting") {
            recoveryZone.push_back(creature);
        }
    }

    void returnFromRecovery() {
        string name, species, healthstatus;
        int age;
        cin >> name >> species >> healthstatus >> age;

        Creature creature(name, species, healthstatus, age);
        auto it = find(recoveryZone.begin(), recoveryZone.end(), creature);
        if (it != recoveryZone.end()) {
            Creature temp = *it;
            temp.setHealthRecovery("healthy");
            recoveryZone.erase(it);
            inhabitants.push_back(temp);
        } else {
            cout << "No creatures found in recovery zone.\n";
        }
    }

   
    void saveData() {
        ofstream outInhabitants("inhabitants.txt");
        for (const auto& c : inhabitants) outInhabitants << c.toString() << endl;
        outInhabitants.close();

        ofstream outRecovery("recovery.txt");
        for (const auto& c : recoveryZone) outRecovery << c.toString() << endl;
        outRecovery.close();

        ofstream outReleased("released.txt");
        for (const auto& c : releasedCreatures) outReleased << c.toString() << endl;
        outReleased.close();
    }

    void loadData() {
        ifstream inInhabitants("inhabitants.txt");
        string name, species, health;
        int age;
        while (inInhabitants >> name >> species >> health >> age) {
            inhabitants.emplace_back(name, species, health, age);
        }
        inInhabitants.close();
    
        ifstream inRecovery("recovery.txt");
        while (inRecovery >> name >> species >> health >> age) {
            recoveryZone.emplace_back(name, species, health, age);
        }
        inRecovery.close();
    
        ifstream inReleased("released.txt");
        while (inReleased >> name >> species >> health >> age) {
            releasedCreatures.emplace_back(name, species, health, age);
        }
        inReleased.close();
    }
};

int main() {
    Sanctuary sanctuary;
    int choice;
    do {
        cout << "\n1. Add Creature\n2. Send to Recovery\n3. Return from Recovery\n4. Release Creature\n5. Display Sanctuary\n6. Save Data\n7. Load Data\n8. Exit\nChoice: ";
        cin >> choice;
        switch (choice) {
            case 1: sanctuary.addCreature(); break;
            case 2: sanctuary.sendToRecovery(); break;
            case 3: sanctuary.returnFromRecovery(); break;
            case 4: sanctuary.releaseCreature(); break;
            case 5: sanctuary.display(); break;
            case 6: sanctuary.saveData(); break;
            case 7: sanctuary.loadData(); break;
            case 8: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 8);
    return 0;
}
