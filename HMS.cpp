#include <iostream>
#include <fstream>
using namespace std;
class Horse {
public:
    string name;
    int age;
    string breed;
    string health;
    void input() {
        cout << "Enter Horse Name: ";
        cin >> name;
        cout << "Enter Age: ";
        cin >> age;
        cout << "Enter Breed: ";
        cin >> breed;
        cout << "Enter Health Status: ";
        cin >> health;
    }
    void display() {
        cout << "\n--- Horse Details ---\n";
        cout << "Name: " << name << endl;
        cout << "Age: " << age << " years" << endl;
        cout << "Breed: " << breed << endl;
        cout << "Health: " << health << endl;
    }
};
Horse horses[100];
int countH = 0;
void saveToFile() {
    ofstream file("horses.txt");
    for (int i = 0; i < countH; i++) {
        file << horses[i].name << " "
             << horses[i].age << " "
             << horses[i].breed << " "
             << horses[i].health << endl;
    }
    file.close();
    cout << "Records Saved!\n";
}
void loadFromFile() {
    ifstream file("horses.txt");
    while (file >> horses[countH].name
                >> horses[countH].age
                >> horses[countH].breed
                >> horses[countH].health) {
        countH++;
    }
    file.close();
}
void addHorse() {
    horses[countH].input();
    countH++;
    cout << "Horse Added Successfully!\n";
}
void displayAll() {
    if (countH == 0) {
        cout << "No records found!\n";
        return;
    }
    for (int i = 0; i < countH; i++) {
        horses[i].display();
    }
}
void searchHorse() {
    string key;
    cout << "Enter Horse Name to Search: ";
    cin >> key;

    for (int i = 0; i < countH; i++) {
        if (horses[i].name == key) {
            cout << "\nHorse Found!\n";
            horses[i].display();
            return;
        }
    }
    cout << "Horse Not Found!\n";
}
void updateHorse() {
    string key;
    cout << "Enter Horse Name to Update: ";
    cin >> key;

    for (int i = 0; i < countH; i++) {
        if (horses[i].name == key) {
            cout << "Enter New Age: ";
            cin >> horses[i].age;
            cout << "Enter New Health: ";
            cin >> horses[i].health;
            cout << "Record Updated!\n";
            return;
        }
    }
    cout << "Horse Not Found!\n";
}
void deleteHorse() {
    string key;
    cout << "Enter Horse Name to Delete: ";
    cin >> key;

    for (int i = 0; i < countH; i++) {
        if (horses[i].name == key) {
            for (int j = i; j < countH - 1; j++) {
                horses[j] = horses[j + 1];
            }
            countH--;
            cout << "Horse Deleted Successfully!\n";
            return;
        }
    }
    cout << "Horse Not Found!\n";
}
int main() {
    loadFromFile();
    int choice;
    do {
        cout << "\n--- Horse Management System ---\n";
        cout << "1. Add Horse\n";
        cout << "2. Display All Horses\n";
        cout << "3. Search Horse\n";
        cout << "4. Update Horse\n";
        cout << "5. Delete Horse\n";
        cout << "6. Save to File\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addHorse(); break;
            case 2: displayAll(); break;
            case 3: searchHorse(); break;
            case 4: updateHorse(); break;
            case 5: deleteHorse(); break;
            case 6: saveToFile(); break;
            case 7: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 7);
    return 0;
}
