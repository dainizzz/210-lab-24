#include <iostream>
#include <fstream>
#include <iomanip>
#include <list>
#include <limits>
#include "Goat.h"
using namespace std;

const int SZ_NAMES = 200, SZ_COLORS = 25, MAX_AGE = 20;

int select_goat(list<Goat> trip);
void delete_goat(list<Goat> &trip);
void add_goat(list<Goat> &trip, string [], string []);
void display_trip(list<Goat> trip);
int main_menu();

int main() {
    srand(time(0));
    bool again;

    // read & populate arrays for names and colors
    ifstream fin("names.txt");
    string names[SZ_NAMES];
    int i = 0;
    while (fin >> names[i++]);
    fin.close();
    ifstream fin1("colors.txt");
    string colors[SZ_COLORS];
    i = 0;
    while (fin1 >> colors[i++]);
    fin1.close();

    int choice = main_menu();
    list<Goat> trip;

    return 0;
}

int main_menu() {
    int choice;
    cout << "*** GOAT MANAGER 3001 ***" << endl;
    cout << "[1] Add a goat" << endl;
    cout << "[2] Delete a goat" << endl;
    cout << "[3] List goats" << endl;
    cout << "[4] Quit" << endl;
    cout << "Choice --> ";
    while (!(cin >> choice) || choice < 1 || choice > 4) {
        cout << "Invalid choice. Please enter a number 1-4 as your choice:" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return choice;
}

int select_goat(list<Goat> trip) {

}

void delete_goat(list<Goat> &trip) {
}

void add_goat(list<Goat> &trip, string names[], string colors[]) {
    // randomly select a name and color from main()'s arrays
    // select a random age between 0 and max age
}

void display_trip(list<Goat> trip) {
    // OUTPUT FORMAT:
    // [num] name (age, color)
    // num starts at 1
}
