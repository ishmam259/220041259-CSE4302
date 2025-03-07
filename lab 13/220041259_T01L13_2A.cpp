#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <vector>

using namespace std;

class Creature {
protected:
    string name;
    string species;
    int id;

public:
    Creature(string n, string s, int i) : name(n), species(s), id(i) {}

    virtual void display() const {
        cout << "ID: " << id << ", Name: " << name << ", Species: " << species << endl;
    }

    int getID() const { return id; }
    string getName() const { return name; }
};

class ActiveCreature : public Creature {
private:
    string healthStatus;
    vector<string> dailyActivities;

public:
    ActiveCreature(string n, string s, int i, string h)
        : Creature(n, s, i), healthStatus(h) {}

    void addActivity(string activity) {
        dailyActivities.push_back(activity);
        if (dailyActivities.size() > 3) {
            healthStatus = "Tired";
        }
    }

    void setHealth(string status) { healthStatus = status; }

    bool needsRecovery() const { return healthStatus != "Healthy"; }

    void display() const override {
        Creature::display();
        cout << "Health: " << healthStatus << ", Activities: ";
        for (const auto& act : dailyActivities) {
            cout << act << " ";
        }
        cout << endl;
    }
};

class RecoveringCreature : public Creature {
private:
    set<string> recoveryStatus;

public:
    RecoveringCreature(string n, string s, int i) : Creature(n, s, i) {
        recoveryStatus.insert("Resting");
    }

    void updateRecovery(string status) { recoveryStatus.insert(status); }

    bool isRecovered() const { return recoveryStatus.count("Fully Recovered") > 0; }

    void display() const override {
        Creature::display();
        cout << "Recovery Status: ";
        for (const auto& status : recoveryStatus) {
            cout << status << " ";
        }
        cout << endl;
    }
};

class Sanctuary {
private:
    map<int, ActiveCreature> activeCreatures;
    map<int, RecoveringCreature> recoveringCreatures;

public:
    void addCreature() {
        int id;
        string name, species, health;
        cout << "Enter ID, Name, Species, and Health status: ";
        cin >> id >> name >> species >> health;
        activeCreatures[id] = ActiveCreature(name, species, id, health);
    }

    void sendToRecovery(int id) {
        if (activeCreatures.count(id)) {
            ActiveCreature& ac = activeCreatures[id];
            if (ac.needsRecovery()) {
                recoveringCreatures[id] = RecoveringCreature(ac.getName(), "Recovering", id);
                activeCreatures.erase(id);
                cout << "Creature moved to recovery.\n";
            } else {
                cout << "Creature is healthy.\n";
            }
        } else {
            cout << "Active creature not found.\n";
        }
    }

    void modifyHealth(int id) {
        if (activeCreatures.count(id)) {
            string newHealth;
            cout << "Enter new health status: ";
            cin >> newHealth;
            activeCreatures[id].setHealth(newHealth);
        } else {
            cout << "Active creature not found.\n";
        }
    }

    void modifyRecovery(int id) {
        if (recoveringCreatures.count(id)) {
            string newStatus;
            cout << "Enter new recovery status: ";
            cin >> newStatus;
            recoveringCreatures[id].updateRecovery(newStatus);
        } else {
            cout << "Recovering creature not found.\n";
        }
    }

    void returnFromRecovery(int id) {
        if (recoveringCreatures.count(id)) {
            RecoveringCreature& rc = recoveringCreatures[id];
            if (rc.isRecovered()) {
                activeCreatures[id] = ActiveCreature(rc.getName(), "Restored", id, "Healthy");
                recoveringCreatures.erase(id);
                cout << "Creature returned to active status.\n";
            } else {
                cout << "Creature is still recovering.\n";
            }
        } else {
            cout << "Recovering creature not found.\n";
        }
    }

    void releaseCreature(int id) {
        if (activeCreatures.erase(id) || recoveringCreatures.erase(id)) {
            cout << "Creature released to the wild.\n";
        } else {
            cout << "Creature not found.\n";
        }
    }

    void loadData() {
        ifstream file("sanctuary_data.txt");
        int id;
        string name, status;
        while (file >> id >> name >> status) {
            if (status == "Active") {
                activeCreatures[id] = ActiveCreature(name, "Unknown", id, "Healthy");
            } else {
                recoveringCreatures[id] = RecoveringCreature(name, "Recovering", id);
            }
        }
        cout << "Data loaded.\n";
    }
};

int main() {
    Sanctuary sanctuary;
    int choice, id;

    do {
        cout << "\n1. Add Creature\n2. Send to Recovery\n3. Modify Health\n4. Modify Recovery Status\n5. Return from Recovery\n6. Release Creature\n7. Save Data\n8. Load Data\n9. Display Sanctuary\n0. Exit\n";
        cin >> choice;

        switch (choice) {
            case 1: sanctuary.addCreature(); break;
            case 2: cout << "Enter ID: "; cin >> id; sanctuary.sendToRecovery(id); break;
            case 3: cout << "Enter ID: "; cin >> id; sanctuary.modifyHealth(id); break;
            case 4: cout << "Enter ID: "; cin >> id; sanctuary.modifyRecovery(id); break;
            case 5: cout << "Enter ID: "; cin >> id; sanctuary.returnFromRecovery(id); break;
            case 6: cout << "Enter ID: "; cin >> id; sanctuary.releaseCreature(id); break;
            case 8: sanctuary.loadData(); break;
        }
    } while (choice != 0);

    return 0;
}


