//
//  main.cpp
//  Lec-9-26
//
//  Created by Jennifer Walker on 9/26/16.
//  Copyright (c) 2016 Jennifer Walker. All rights reserved.
//

//  main memory is like a really really big array
/* What is in main memory?
 - the main code
 - heaps & stacks
 - has to be shared amongst many programs that are running
 - has to be shared between the code and the data executed on the code
 
 Memory
    - 32 bit --> 4 GB
    - 64 bit --> 18.4 Exobytes --> exobyte = 1 billion gigs
    - Seems crazy but may not be.
    - in mid 1980s there was 1 MB of ram, and the idea of 4 gigs of ram seemed insane
    - in 32 years, it's thus fathomable
 
 every byte has a unique address in main memory
    - addresses are done in Hex (...808, 809, 80A, 80B,...)
    - ex: int x = 5;
    - ints take up four bytes (limits of the int). ex(801, 802, 803, 804).
        - all c++ needs to know is that it *starts* at address 801
    - uses a pointer --> way to store a memory address.
        - int* z;       //  int pointer, stored in (806 807, 808, 809)
            - all thats being stored in the pointer is garbage rn, bc it doesnt point to anything
            - we always should know what it's pointing to, otherwise it's called a dangling pointer
        - z = nullptr;      //  says that it doesn't point to anything
        - z = &x;           //  z now stores address of x (801)
        - pointers have to point to the address, it doesn't store the value in the address
        - spec. to data type: int pointer points to an integer, cannot point to a double, char, etc

 3 errors with pointers
    - 1) Defreference nullptr;      -->     program will completely crash
        - ex: int *x = nullptr;
        - not always as obvious as blatantly dereferencing, can happen accidentally
    - 2) Double delete
        - cant delete a pointer twice 
        - ex:
            int* x = new int;
            int* y = x;
            delete x;
            delete y;           //  y points to the same integer, thus the double delete. It's like calling a box by two names and then trying to remove the same thing from it twice 
    - 3) Garbage on the heap / memory leak (same thing)
        - when you have memory left on the heap that you can no longer access 
        - ex:
            int* x = new int;
            x = other new int;
            delete x;           //  new int is still left on the heap that you can't access - will never find it again 
        - how they usually show up:
            - something starts up and runs for long time (ex: months). When a program ends, all the memory used goes back into the system, but if the program is continuously running, the memory never gets deleted
            - crashes every couple of months bc even though its fine when it starts (only using a few megs), there are small memory leaks that add up into multiple memory leaks (gigs, etc) and eventually the computer cannot allocate more memory to the program and crashes 
 
 The Heap
    - place where we can create / delete memory
    - cannot name the variables on the heap --> can only access by using pointers. 
    - ex:
        - int* x = new int;
        - *x = 100;
        - cout << *x;
        - delete x;             //  doesnt do anything to the pointer, only deletes what the pointer is pointing to
        - x = other new int;    //  thus, can reuse the pointer once the past data is deleted
    - Metaphor: you rent the apartment. You use the apartment, you live there, but when you want to move, you tell the landlord that you're moving, get the deposit back (return the space bzack to the memory) and can get a new apartment
        - where double delete comes in - you cant get your deposit back twice
 */

#include <iostream>
#include <vector>

using namespace std;

int main() {
    //                                  POINTERS IN CODE
    int x = 5;
    int* z = &x;
    cout << *z << endl;     //  prints the value that z is pointing to - called a dereference ("dereference z")
    

    //  If we are people, and we have parents, and our parents are people, we need a way to point to parents
    class Date {
        int day;
        int month;
        int year;
    public:
        //  Mutators
        void setDay(int newday) {
            day = newday; 
        }
        void setMonth(int newmonth) {
            month = newmonth;
        }
        void setYear(int newyear) {
            year = newyear;
        }
    };
    
    class Person {
        string name;
        int height;                 //  inches
        double weight;              //  lbs
        Date DOB;
        Person* Mom;                //  Pointers bc parent objects dont exist in Person object, just the pointers
        Person* Dad;
        vector<Person*> Children;   //  vector of pointers for children
    public:
        //  Default constructor
        Person (string newname = "", Person* newmom = nullptr, Person* newdad = nullptr) : Mom(newmom), Dad(newdad) {}
        //  Mutators
        void setName(string newname) {
            name = newname;
        }
        void setWeight(int newweight) {
            weight = newweight;
        }
        void setHeight(int newheight) {
            height = newheight;
        }
        void setDOB (Date newDOB) {
            DOB = newDOB;
        }
        void setMom(Person* newMom) {
            Mom = newMom;
        }
        void setDad(Person* newDad) {
            Dad = newDad;
        }
        
    };
    
    //  Me
    Date selfBirthday;
    selfBirthday.setDay(26);
    selfBirthday.setMonth(11);
    selfBirthday.setYear(1995);
    
    Person self;
    self.setName("Jennie");
    self.setWeight(145.3);
    self.setHeight(67);
    self.setDOB(selfBirthday);
    
    //  Mom
    Date momBirthday;
    momBirthday.setDay(9);
    momBirthday.setMonth(6);
    momBirthday.setYear(1962);
    
    Person mom;
    mom.setName("Leigh");
    mom.setHeight(68);
    mom.setDOB(selfBirthday);
    
    //  Dad
    Date dadBirthday;
    dadBirthday.setDay(14);
    dadBirthday.setMonth(2);
    dadBirthday.setYear(1956);
    
    Person dad;
    dad.setName("Brian");
    dad.setHeight(65);
    dad.setDOB(dadBirthday);

    //  create parental pointers
    self.setMom(&mom);
    self.setDad(&dad);
    
    cout << endl;
    
}
