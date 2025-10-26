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
	list<Goat> trip;
	int choice;

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

	again = true;
	while (again) {
		choice = main_menu();
		switch (choice) {
			case 1:
				add_goat(trip, names, colors);
				break;
			case 2:
				delete_goat(trip);
				break;
			case 3:
				display_trip(trip);
				break;
			case 4:
				again = false;
				break;
			default:
				break; // Invalid choices should already be caught in main_menu();
		}
	}

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
	// Checks that the input is the correct type & in the correct range
	while (!(cin >> choice) || choice < 1 || choice > 4) {
		cout << "Invalid choice. Please enter a number 1-4 as your choice:" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	return choice;
}

int select_goat(list<Goat> trip) {
	int choice;
	display_trip(trip);
	cout << "Choice --> ";
	while (!(cin >> choice) || choice < 1 || choice > trip.size()) {
		cout << "Invalid choice. Please enter a number 1-" << trip.size() << " as your choice:" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	return choice;
}

void delete_goat(list<Goat> &trip) {
	cout << "Which goat do you want to delete?" << endl;
	int choice = select_goat(trip);
	auto it = trip.begin();
	// Starting i at 1 so the iterator matches up correctly with the choice
	for (int i = 1; i < choice; i++) {
		++it;
	}
	trip.erase(it);
}

void add_goat(list<Goat> &trip, string names[], string colors[]) {
	int nameIndex = rand() % SZ_NAMES; // the random number is between [0,SZ_NAMES)
	int age = rand() % (MAX_AGE + 1); // the random number is between [0,MAX_AGE]
	int colorIndex = rand() % SZ_COLORS; // the random number is between [0,SZ_COLORS)

	Goat newGoat(names[nameIndex], age, colors[colorIndex]);
	trip.push_back(newGoat);
}

void display_trip(list<Goat> trip) {
	int num = 1;
	for (Goat goat: trip) {
		cout << "\t[" << num << "] " << goat.get_name() << " (" << goat.get_age() << ", " << goat.get_color() << ')' <<
				endl;
		num++;
	}
}