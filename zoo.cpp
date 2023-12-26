#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;

class Animal {
public:
    string animalName, species, cageNumber, sound;
    int age;

    Animal() : age(0) {}

    virtual void getDetails() {
        cout << "\n\t\tEnter Animal's Name: ";
        getline(cin, animalName);

        cout << "\n\t\tEnter Animal's Species: ";
        getline(cin, species);

        cout << "\n\t\tEnter Animal's Cage Number: ";
        getline(cin, cageNumber);

        cout << "\n\t\tEnter Animal's Sound: ";
        getline(cin, sound);

        cout << "\n\t\tEnter Animal's Age: ";
        cin >> age;
        cin.ignore();  // to consume the newline character left in the buffer
    }

    virtual void showDetails() const {
        cout << "\n\t\tAnimal Name: " << animalName << endl;
        cout << "\n\t\tAnimal's Species: " << species << endl;
        cout << "\n\t\tCage Number: " << cageNumber << endl;
        cout << "\n\t\tAnimal's Sound: " << sound << endl;
        cout << "\n\t\tAnimal's Age: " << age << endl;
    }

    virtual ~Animal() {}
};

class Mammal : public Animal {
public:
    string furColor;

    Mammal() {}

    void getDetails() override {
        Animal::getDetails();
        cout << "\n\t\tEnter Mammal's Fur Color: ";
        getline(cin, furColor);
    }

    void showDetails() const override {
        Animal::showDetails();
        cout << "\n\t\tMammal's Fur Color: " << furColor << endl;
    }
};

class Bird : public Animal {
public:
    int wingspan;

    Bird() : wingspan(0) {}

    void getDetails() override {
        Animal::getDetails();
        cout << "\n\t\tEnter Bird's Wingspan (in inches): ";
        cin >> wingspan;
        cin.ignore();  // to consume the newline character left in the buffer
    }

    void showDetails() const override {
        Animal::showDetails();
        cout << "\n\t\tBird's Wingspan: " << wingspan << " inches" << endl;
    }
};

class Fish : public Animal {
public:
    string waterType;

    Fish() {}

    void getDetails() override {
        Animal::getDetails();
        cout << "\n\t\tEnter Fish's Water Type: ";
        getline(cin, waterType);
    }

    void showDetails() const override {
        Animal::showDetails();
        cout << "\n\t\tFish's Water Type: " << waterType << endl;
    }
};

class Employee {
public:
    string name, designation;
    int employeeID;

    Employee() : employeeID(0) {}

    void getDetails() {
        cout << "\n\t\tEnter Employee's Name: ";
        getline(cin, name);

        cout << "\n\t\tEnter Employee's Designation: ";
        getline(cin, designation);

        cout << "\n\t\tEnter Employee's ID: ";
        cin >> employeeID;
        cin.ignore();  // to consume the newline character left in the buffer
    }

    void showDetails() const {
        cout << "\n\t\tEmployee Name: " << name << endl;
        cout << "\n\t\tEmployee Designation: " << designation << endl;
        cout << "\n\t\tEmployee ID: " << employeeID << endl;
    }
};

class Visitor {
public:
    string name;
    int visitorID;

    Visitor() : visitorID(0) {}

    void getDetails() {
        cout << "\n\t\tEnter Visitor's Name: ";
        getline(cin, name);

        cout << "\n\t\tEnter Visitor's ID: ";
        cin >> visitorID;
        cin.ignore();  // to consume the newline character left in the buffer
    }

    void showDetails() const {
        cout << "\n\t\tVisitor Name: " << name << endl;
        cout << "\n\t\tVisitor ID: " << visitorID << endl;
    }
};

class Enclosure {
public:
    string enclosureType, location;
    vector<Animal*> animalsInEnclosure;

    Enclosure() {}

    void getDetails() {
        cout << "\n\t\tEnter Enclosure Type: ";
        getline(cin, enclosureType);

        cout << "\n\t\tEnter Enclosure Location: ";
        getline(cin, location);

        int numAnimals;
        cout << "\n\t\tEnter the number of animals in the enclosure: ";
        cin >> numAnimals;
        cin.ignore();  // to consume the newline character left in the buffer

        animalsInEnclosure.reserve(numAnimals);
        for (int i = 0; i < numAnimals; ++i) {
            int choice;
            cout << "\n\t\tEnter the type of Animal " << i + 1 << " in the enclosure\n";
            cout << "\n\t\t1. Mammal";
            cout << "\n\t\t2. Bird";
            cout << "\n\t\t3. Fish";
            cout << "\n\t\tEnter your choice: ";
            cin >> choice;
            cin.ignore();  // to consume the newline character left in the buffer

            Animal* newAnimal;

            switch (choice) {
                case 1:
                    newAnimal = new Mammal;
                    break;
                case 2:
                    newAnimal = new Bird;
                    break;
                case 3:
                    newAnimal = new Fish;
                    break;
                default:
                    cout << "\n\t\tInvalid choice\n";
                    return;
            }

            newAnimal->getDetails();
            animalsInEnclosure.push_back(newAnimal);
        }
    }

    void showDetails() const {
        cout << "\n\t\tEnclosure Type: " << enclosureType << endl;
        cout << "\n\t\tEnclosure Location: " << location << endl;

        cout << "\n\t\tAnimals in the Enclosure:\n";
        for (const auto& animal : animalsInEnclosure) {
            animal->showDetails();
            cout << "\n------------------------\n";
        }
    }

    ~Enclosure() {
        for (auto& animal : animalsInEnclosure) {
            delete animal;
        }
    }
};

class Zoo {
public:
    vector<Enclosure> enclosures;
    vector<Employee> employees;
    vector<Visitor> visitors;

    void addEnclosure();
    void addEmployee();
    void addVisitor();
    void addAnimalToEnclosure();
    void displayAnimalList() const;
    void displayEnclosureList() const;
    void displayEmployeeList() const;
    void displayVisitorList() const;
};

void Zoo::addEnclosure() {
    Enclosure newEnclosure;
    newEnclosure.getDetails();
    enclosures.push_back(newEnclosure);
    cout << "\n\t\tEnclosure added Successfully.\n";
}

void Zoo::addEmployee() {
    Employee newEmployee;
    newEmployee.getDetails();
    employees.push_back(newEmployee);
    cout << "\n\t\tEmployee added Successfully.\n";
}

void Zoo::addVisitor() {
    Visitor newVisitor;
    newVisitor.getDetails();
    visitors.push_back(newVisitor);
    cout << "\n\t\tVisitor added Successfully.\n";
}

void Zoo::addAnimalToEnclosure() {
    if (enclosures.empty()) {
        cout << "\n\t\tPlease add an enclosure first.\n";
        return;
    }

    int enclosureIndex;
    cout << "\n\t\tSelect the Enclosure to add an animal:\n";
    displayEnclosureList();
    cout << "\n\t\tEnter the index of the Enclosure: ";
    cin >> enclosureIndex;

    if (enclosureIndex < 0 || enclosureIndex >= enclosures.size()) {
        cout << "\n\t\tInvalid Enclosure index.\n";
        return;
    }

    int choice;
    cout << "\n\t\tEnter the type of Animal to add to the Enclosure\n";
    cout << "\n\t\t1. Mammal";
    cout << "\n\t\t2. Bird";
    cout << "\n\t\t3. Fish";
    cout << "\n\t\tEnter your choice: ";
    cin >> choice;
    cin.ignore();  // to consume the newline character left in the buffer

    Animal* newAnimal;

    switch (choice) {
        case 1:
            newAnimal = new Mammal;
            break;
        case 2:
            newAnimal = new Bird;
            break;
        case 3:
            newAnimal = new Fish;
            break;
        default:
            cout << "\n\t\tInvalid choice\n";
            return;
    }

    newAnimal->getDetails();
    enclosures[enclosureIndex].animalsInEnclosure.push_back(newAnimal);

    cout << "\n\t\tAnimal added to Enclosure Successfully.\n";
}

void Zoo::displayAnimalList() const {
    if (enclosures.empty()) {
        cout << "\n\t\tNo enclosures available.\n";
        return;
    }

    cout << "\n\t    ************ Animal List ************ \n\n";
    for (const auto& enclosure : enclosures) {
        enclosure.showDetails();  // Display enclosure details first

        cout << "\n------------------------\n";
    }
}

void Zoo::displayEnclosureList() const {
    if (enclosures.empty()) {
        cout << "\n\t\tNo enclosures available.\n";
        return;
    }

    cout << "\n\t    ************ Enclosure List ************ \n\n";
    for (size_t i = 0; i < enclosures.size(); ++i) {
        cout << "\n\t\t" << i + 1 << ". Enclosure\n";
        enclosures[i].showDetails();
        cout << "\n------------------------\n";
    }
}

void Zoo::displayEmployeeList() const {
    if (employees.empty()) {
        cout << "\n\t\tNo employees available.\n";
        return;
    }

    cout << "\n\t    ************ Employee List ************ \n\n";
    for (const auto& employee : employees) {
        employee.showDetails();
        cout << "\n------------------------\n";
    }
}

void Zoo::displayVisitorList() const {
    if (visitors.empty()) {
        cout << "\n\t\tNo visitors available.\n";
        return;
    }

    cout << "\n\t    ************ Visitor List ************ \n\n";
    for (const auto& visitor : visitors) {
        visitor.showDetails();
        cout << "\n------------------------\n";
    }
}

int main() {
    Zoo zoo;

    int choice;
    do {
        cout << "\n\t************ ZOO MANAGEMENT SYSTEM ************\n";
        cout << "\n\t\t1. Add Enclosure\n";
        cout << "\n\t\t2. Add Employee\n";
        cout << "\n\t\t3. Add Visitor\n";
        cout << "\n\t\t4. Add Animal to Enclosure\n";
        cout << "\n\t\t5. Display Animal List\n";
        cout << "\n\t\t6. Display Enclosure List\n";
        cout << "\n\t\t7. Display Employee List\n";
        cout << "\n\t\t8. Display Visitor List\n";
        cout << "\n\t\t9. Exit\n";
        cout << "\n\t\tEnter your choice: ";
        cin >> choice;

        cin.ignore();  // to consume the newline character left in the buffer

        switch (choice) {
            case 1:
                zoo.addEnclosure();
                break;
            case 2:
                zoo.addEmployee();
                break;
            case 3:
                zoo.addVisitor();
                break;
            case 4:
                zoo.addAnimalToEnclosure();
                break;
            case 5:
                zoo.displayAnimalList();
                break;
            case 6:
                zoo.displayEnclosureList();
                break;
            case 7:
                zoo.displayEmployeeList();
                break;
            case 8:
                zoo.displayVisitorList();
                break;
            case 9:
                exit(0);
            default:
                cout << "\n\t\tPlease enter correct option :(";
        }
    } while (choice != 9);

    cout << "\n\t\tPress Enter to exit.....";
    cin.ignore();
    cin.get();
    return 0;
}
