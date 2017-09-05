//
//  main.cpp
//  Lab-09
//
//  Created by Jennifer Walker on 11/4/16.
//  Copyright (c) 2016 Jennifer Walker. All rights reserved.
//

/*
 Recitation 09
 CS1124
 John Sterling
 
 Focus: Copy Control.  Uses dynamic array of pointers.
 */

#include <string>
#include <iostream>
using namespace std;

class Position {
public:
    Position(const string& aTitle, double aSalary) : title(aTitle), salary(aSalary) {}
    string getTitle() const {return title;}
    double getSalary() const {return salary;}
    void changeSalaryTo(double d) {salary = d;}
    void printDict() {cout << "\tTitle: " << title << "\n\tSalary: $" << salary << endl;}
private:
    string title;
    double salary;
};

class Entry {
public:
    Entry(const string& aName, unsigned aRoom, unsigned aPhone, Position& aPosition) : name(aName), room(aRoom), phone(aPhone), pos(&aPosition) {
    }
    friend ostream& operator<<( ostream& os, const Entry& e ) {
        os << e.name << '\n' << e.room << '\n' << e.phone;
        return os;
    }
    //  gives access to employee name
    string getName() const {return name;}
    
    //  gives access to employee room
    unsigned getRoom() const {return room;}
    
    //  gives access to employee phone #
    unsigned getPhone() const {return phone;}
    
    void printDict() {pos -> printDict();}
private:
    string name;
    unsigned room;
    unsigned phone;
    Position* pos;
}; // Entry

class Directory {
public:
    Directory()
    : capacity(2), size(0), entries(new Entry*[2] )
    {
        for (size_t i = 0; i < capacity; i++) {
            entries[i] = NULL;
        }
    }
    
    //  Directory copy constructor
    Directory(const Directory& dir) {
        cout << "Copy Constructor Running" << endl;
        for (size_t i = capacity; i > -1; i--){
            delete entries[i];
        }
        size = dir.size;
        capacity = dir.capacity;
        entries = dir.entries;
    }
    
    void add(const string& name, unsigned room, unsigned ph, Position& pos) {
        if( size == capacity )	{
            //  What was missing:
            //  if size is at capacity, increase capacity
            size_t newCapacity = capacity+1;
            Entry** newEntries = new Entry*[newCapacity];
            for (size_t i = 0; i < capacity; i++){
                newEntries[i] = entries[i];
            }
            for (size_t i = capacity; i > -1; i--){
                delete entries[i];
            }
            entries = newEntries;
            //  What was missing:
            //  set capacity to the new capacity
            capacity = newCapacity;
        }
        entries[size++] = new Entry(name, room, ph, pos);       // entry addition increases array size
    }
    
    //  Directory Assignment Operator
    Directory& operator= (const Directory& dir){
        cout << "Assignment Operator Running" << endl;
        if (this != &dir){
            if (size != dir.size) {
                delete entries;
                size = dir.size;
                capacity = dir.size + 1;
            }
            for (int i = 0; i < size; i++)
                entries[i] = dir.entries[i];
        }
        return *this;
    }
    
    //
    int operator[] (string name) const {
        for (size_t i = 0; i < size; i++){
            if (entries[i]->getName() == name){
                return entries[i]->getPhone();
            }
        }
        return 0;
    }
    
    //  Prints Dictionary
    void printDict() {
        for (int i = 0; i < size; i++) {
            string name = entries[i] -> getName();
            unsigned room = entries[i] -> getRoom();
            unsigned phone = entries[i] -> getPhone();
            // access through entries -> have get methods in data class
            cout << "Employee " << i+1 << ": \n" << "\tName: " << name << endl;
            entries[i] -> printDict();
            cout << "\tRoom: " << room << "\n\tPhone: " << phone << endl;
        }
    }
    
    //  Directory Deconstructor
    ~Directory(){
        cout << "Destructor Running" << endl;
        for (size_t i = capacity; i > -1; i--){
            delete entries[i];
        }
        //delete [] entries;
    }
    
private:
    Entry** entries;
    size_t size;
    size_t capacity;
};

int main() {
    
    // Model as if there are these four kinds
    // of position in the problem:
    Position boss("Boss", 3141.59);
    Position pointyHair("Pointy Hair", 271.83);
    Position techie("Techie", 14142.13);
    Position peon("Peonissimo", 34.79);
    
    // Creates first directory
    Directory d;
    d.add("Marilyn", 123, 4567, boss);
    
    //  Creates second directory; copies first directory
    Directory d2 = d;	// Q: What function is being used. --> A: copy constructor
    d2.add("Gallagher", 111, 2222, techie);
    //  add more employees to d2 to test capacity increase
    d2.add("Hellfire", 666, 4311, techie);
    d2.add("Oswald", 503, 5049, techie);
    d2.add("Sunshine", 268, 7676, techie);
    cout << "Directory 2:" << endl;
    d2.printDict();     //  prints second dict
    
    //  Creates third directory; copies second directory
    Directory d3 = d2;
    d3.add("Roofielia", 223, 7453, peon);
    d3.add("Samantha Zamara", 000, 1411, pointyHair);
    d3.add("Hallelujah", 123, 7654, boss);
    cout << "Directory 3:" << endl;
    d3.printDict();     //  prints third dict
    
}