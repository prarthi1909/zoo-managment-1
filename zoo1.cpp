#include <iostream>
#include <vector>
#include <string>
#include <iomanip>      //setw()
#include <limits>

using namespace std;

// Class definitions
class Animal
{
public:
    string type;
    string name;
    string species;
    int cagenumber;
    string sound;
    int age;
    string colour;
};

class Enclosure
{
public:
    string type;
    string location;
    int number;
    vector<Animal> animals;
};

class Employee
{
public:
    string name;
    string desihnation;
    int id;
};

class Visitor
{
public:
    string name;
    string gender;
    int age;
    int id;
};

// Function declarations
void addEnclosure(vector<Enclosure> &enclosures);
void addEmployee(vector<Employee> &employees);
void addVisitor(vector<Visitor> &visitors);
void addAnimalToEnclosure(vector<Enclosure> &enclosures);
void displayAnimalList(const vector<Enclosure> &enclosures);
void displayEnclosureList(const vector<Enclosure> &enclosures);
void displayEmployeeList(const vector<Employee> &employees);
void displayVisitorList(const vector<Visitor> &visitors);
void removeEmployee(int idToRemove, vector<Employee> &employees);
void removeAnimalFromEnclosure(string enclosureName, string animalName, vector<Enclosure> &enclosures);

int main()
{
    vector<Enclosure> enclosures;
    vector<Employee> employees;
    vector<Visitor> visitors;

    int choice;
    int idToRemove;
    string enclosureName, animalName;
    do
    {
        cout << "************ ZOO MANAGEMENT SYSTEM ************" << endl;
        cout << "1. Add Enclosure\n"
             << "2. Add Employee\n"
             << "3. Add Visitor\n"
             << "4. Add Animal to Enclosure\n"
             << "5. Display Animal List\n"
             << "6. Display Enclosure List\n"
             << "7. Display Employee List\n"
             << "8. Display Visitor List\n"
             << "9. Remove Employee\n"
             << "10. Remove Animal from Enclosure\n"
             << "11. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear buffer

        switch (choice)
        {
        case 1:
            addEnclosure(enclosures);
            break;
        case 2:
            addEmployee(employees);
            break;
        case 3:
            addVisitor(visitors);
            break;
        case 4:
            addAnimalToEnclosure(enclosures);
            break;
        case 5:
            displayAnimalList(enclosures);
            break;
        case 6:
            displayEnclosureList(enclosures);
            break;
        case 7:
            displayEmployeeList(employees);
            break;
        case 8:
            displayVisitorList(visitors);
            break;
        case 9:
            cout << "Enter ID of the employee to remove: ";
            cin >> idToRemove;
            removeEmployee(idToRemove, employees);
            break;
        case 10:
            cout << "Enter enclosure name: ";
            getline(cin, enclosureName);
            cout << "Enter animal name: ";
            getline(cin, animalName);
            removeAnimalFromEnclosure(enclosureName, animalName, enclosures);
            break;
        case 11:
            cout << "Exiting program. Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 11);

    return 0;
}

// Function implementations remain unchanged...
void addEnclosure(vector<Enclosure> &enclosures)
{
    Enclosure newEnclosure;
    cout << "Enter Enclosure Type: ";
    getline(cin, newEnclosure.type);
    cout << "Enter Enclosure Location: ";
    getline(cin, newEnclosure.location);
    cout << "Enter the number of animals in the Enclosure: ";
    cin >> newEnclosure.number;
    enclosures.push_back(newEnclosure);
    cout << "Enclosure added successfully." << endl;
}

void addEmployee(vector<Employee> &employees)
{
    Employee newEmployee;
    cout << "Enter the name of the employee: ";
    getline(cin, newEmployee.name);
    cout << "Enter the position of the employee: ";
    getline(cin, newEmployee.desihnation);
    cout << "Enter the ID of the employee: ";
    cin >> newEmployee.id;
    employees.push_back(newEmployee);
    cout << "Employee added successfully." << endl;
}

void addVisitor(vector<Visitor> &visitors)
{
    Visitor newVisitor;
    cout << "Enter the name of the visitor: ";
    getline(cin, newVisitor.name);
    cout << "Enter the gender of the visitor: ";
    getline(cin, newVisitor.gender);
    cout << "Enter the age of the visitor: ";
    cin >> newVisitor.age;
    cout << "Enter the ID of the visitor: ";
    cin >> newVisitor.id;
    visitors.push_back(newVisitor);
    cout << "Visitor added successfully." << endl;
}

void addAnimalToEnclosure(vector<Enclosure> &enclosures)
{
    string enclosureName;
    cout << "Enter the name of the enclosure: ";
    getline(cin, enclosureName);
    for (Enclosure &enclosure : enclosures)
    {
        if (enclosure.type == enclosureName)
        {
            Animal newAnimal;
            cout << "Enter the type of the animal: ";
            getline(cin, newAnimal.type);
            cout << "Enter the name of the animal: ";
            getline(cin, newAnimal.name);
            cout << "Enter the species of the animal: ";
            getline(cin, newAnimal.species);
            cout << "Enter Sound of the animal: ";
            getline(cin, newAnimal.sound);
            cout << "Enter Colour of the animal: ";
            getline(cin, newAnimal.colour);
            cout << "Enter the Cage Number of the animal: ";
            cin >> newAnimal.cagenumber;
            cout << "Enter the age of the animal: ";
            cin >> newAnimal.age;
            enclosure.animals.push_back(newAnimal);
            cout << "Animal added to enclosure successfully." << endl;
            return;
        }
    }
    cout << "Enclosure not found. Animal not added." << endl;
}

void displayAnimalList(const vector<Enclosure> &enclosures)
{
    cout << "************ Animal List ************" << endl;
    cout << setw(15) << "Enclosure" << setw(15) << "Type" << setw(15) << "Name" << setw(15) << "Species" << setw(15) << "Cage" << setw(15) << "Sound" << setw(15) << "Age" << setw(15) << "Colour" << endl;
    cout << "|"
         << "------------------------------------------------------------------------------------------------------------------------"
         << "|" << endl;
    for (const Enclosure &enclosure : enclosures)
    {
        for (const Animal &animal : enclosure.animals)
        {
            cout << setw(15) << enclosure.type << setw(15) << animal.type << setw(15) << animal.name << setw(15)
                 << animal.species << setw(15) << animal.cagenumber << setw(15) << animal.sound << setw(15) << animal.age << setw(15) << animal.colour << endl;
        }
    }
    cout << "|"
         << "------------------------------------------------------------------------------------------------------------------------"
         << "|" << endl;
}

void displayEnclosureList(const vector<Enclosure> &enclosures)
{
    cout << "************ Enclosure List ************" << endl;
    cout << setw(15) << "Type" << setw(20) << "Location" << setw(20) << "Number of Animals" << endl;
    cout << "|"
         << "-------------------------------------------------------------------"
         << "|" << endl;
    for (const Enclosure &enclosure : enclosures)
    {
        cout << setw(15) << enclosure.type << setw(20) << enclosure.location << setw(20) << enclosure.number << endl;
    }
    cout << "|"
         << "-------------------------------------------------------------------"
         << "|" << endl;
}

void displayEmployeeList(const vector<Employee> &employees)
{
    cout << "************ Employee List ************" << endl;
    cout << setw(15) << "Name" << setw(20) << "Designation" << setw(20) << "ID" << endl;
    cout << "|"
         << "---------------------------------------------------------------------"
         << "|" << endl;
    for (const Employee &employee : employees)
    {
        cout << setw(15) << employee.name << setw(20) << employee.desihnation << setw(20) << employee.id << endl;
    }
    cout << "|"
         << "---------------------------------------------------------------------"
         << "|" << endl;
}

void displayVisitorList(const vector<Visitor> &visitors)
{
    cout << "************ Visitor List ************" << endl;
    cout << setw(15) << "Name" << setw(15) << "Gender" << setw(15) << "Age" << setw(15) << "ID" << endl;
    cout << "|"
         << "----------------------------------------------------------------------"
         << "|" << endl;
    for (const Visitor &visitor : visitors)
    {
        cout << setw(15) << visitor.name << setw(15) << visitor.gender << setw(15) << visitor.age << setw(15) << visitor.id << endl;
    }
    cout << "|"
         << "----------------------------------------------------------------------"
         << "|" << endl;
}

void removeEmployee(int idToRemove, vector<Employee> &employees)
{
    for (auto it = employees.begin(); it != employees.end(); ++it)
    {
        if (it->id == idToRemove)
        {
            employees.erase(it);
            cout << "Employee with ID " << idToRemove << " removed successfully." << endl;
            return;
        }
    }
    cout << "Employee with ID " << idToRemove << " not found." << endl;
}

void removeAnimalFromEnclosure(string enclosureName, string animalName, vector<Enclosure> &enclosures)
{
    for (auto &enclosure : enclosures)
    {
        if (enclosure.type == enclosureName)
        {
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear buffer
            for (auto it = enclosure.animals.begin(); it != enclosure.animals.end(); ++it)
            {
                if (it->name == animalName)
                {
                    enclosure.animals.erase(it);
                    cout << "Animal " << animalName << " removed from enclosure " << enclosureName << " successfully." << endl;
                    return;
                }
            }
            cout << "Animal " << animalName << " not found in enclosure " << enclosureName << "." << endl;
            return;
        }
    }
    cout << "Enclosure " << enclosureName << " not found." << endl;
}
