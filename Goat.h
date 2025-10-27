// Goat.h

#ifndef GOAT_H
#define GOAT_H
#include <iostream>
using namespace std;

class Goat {
private:
    string name;
    int age;
    string color;
public:
    Goat()                          { name = ""; age = 0; color = ""; }
    // write three more constructors
    Goat(string n)                  { name = n; age = 0; color = ""; }
    Goat(string n, int a)           { name = n; age = a; color = ""; }
    Goat(string n, int a, string c) { name = n; age = a; color = c; }
    // setters and getters
    void set_name(string n)         { name = n; };
    string get_name() const         { return name; };
    void set_age(int a)             { age = a; };
    int get_age() const             { return age; }
    void set_color(string c)        { color = c; }
    string get_color() const        { return color; }

    // std::sets are ordered, so this overloaded operator is neccessary so that the compiler knows which
    // variable to use for sorting.
    bool operator<(const Goat &other) const {
        return name < other.get_name();
    }

    bool operator==(const Goat &other) const {
        bool equal = true;

        if (name != other.get_name())
            equal = false;

        if (color != other.get_color())
            equal = false;

        if (age != other.get_age())
            equal = false;

        return equal;
    }
};

#endif