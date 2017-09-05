//
//  main.cpp
//  Lec-9-28
//
//  Created by Jennifer Walker on 9/28/16 AND 10/3/16.
//  Copyright (c) 2016 Jennifer Walker. All rights reserved.
//

#include <iostream>

using namespace std;

void func1() {
    int *y = new int(100);
    //delete y;                   --> causes memory leak if not included
    *y *= 10;
}

void func2(int* arr) {          //  dont need & bc just changing what the pointer is pointing to
    arr[5] = 100;
}

void func3(int* arr) {          //  need & bc were changing the pointer itself
    delete[] arr;
    arr = new int [100];
    arr[6] = 100;
}

class Person{
    string name;
    Person* spouse;
public:
    Person(string newName = "") : name(newName), spouse(nullptr){}
    //  mutators
    void setName(string newName) { name = newName; }
    void setSpouse(Person* newSpouse) {spouse = newSpouse;}
    string getName() const { return name;}
    Person* getSpouse() {return spouse;}
    bool isMarried() const {return (spouse!= nullptr);}
    bool getMarried(Person& p) {
        if (spouse) {           //  (spouse!= nullptr) {    -->     same thing
            return false;       //  cannot marry bc person is already married.
        }
        if (p.spouse!= nullptr) {
            return false;       //  cannot marry bc S.O.-to-be is already married
        }
        //if (p==*this) {       //  does not work bc trying to compare two complete objects
        if (&p == this) {       //  cannot marry yourself - works bc now you're comparing pointers
            return false;
        }
        spouse = &p;
        p.spouse = this;
        return true;
    }
    bool getDivorced() {
        if (spouse) {           //  NEED if statement bc otherwise you run the risk of deref NULL
            spouse->spouse = nullptr;
            spouse = nullptr;
            return true;
        }
        return false;
    }
};

class DynArray {                //  class for dynamic array
    int numOfElements, capacity;
    int* data;
public:
    //  Default Constructor
    DynArray() : data(new int[5]), capacity(5), numOfElements(0){}
    //  misc functions
    int size() const { return numOfElements; }
    //  push_back function
    void push_back(int newValue) {
        if (numOfElements == capacity) {    //  if dynArray is full, resize the array first
            resize(numOfElements * 2);
        }
        data[numOfElements++] = newValue;   //  if there is room, add newValue onto back of the array
    }
    //  pop back
    int pop_back() {
        if (numOfElements > 0)
            return data[--numOfElements];
        return 0;                           //  if no elements, return 0
    }
    //  resize
    void resize(int newSize) {
        if (newSize < numOfElements) {
            numOfElements = newSize;
        }
        int * temp = new int[newSize];
        for (int i = 0; i < numOfElements; i++) {
            temp[i] = data[i];
        }
        //delete[] data;
        data = temp;                        //  now has lost track of the original data ("like guy floating in space")
        capacity = newSize;
    }
};


int main() {
    int* thing1, thing2;        //  not two pointers!! thing1 is pointer, thing 2 is *not* bc could also be written as int *thing1, thing 2;
    int x = 5;
    int* y = &x;
    
    y = new int(100);
    delete y;
    
    /*for (int i = 0; i< 100000000; i++) {
        func1();
    }   //  uses 1.51 GB in a few seconds if y is not deleted, 480 KB if it is
     */
    
    y = nullptr;
    //cout << *y << endl;       --> crashes code
    delete y;                   //  perfectly okay to delete nullptr, not a double delete
    delete y;                   //  we can delete nullptr as many times as we want, wont crash
    
    int* z = new int(100);
    y = new int(200);
    int *w = z;
    z = y;
    y = w;
    delete y;
    delete z;
    //delete w;                 //  crashes bc double delete, not okay!
    
    
    //                                      DYNAMIC ARRAYS
    int size = 100;
    // int sarr[size]           //  cannot use a non-const to define the size of a stack array
    
    //  z is one address but you can store 100 things in it... how?
    //      - element base =                    --> start of array = 0 bc base of array is at position 0
    //          - base of array +               --> pointer!
    //          - index* size of one element    --> known based on one data type
    //  the base of the array is a pointer, which is why when you pass an array to a function by value, the changes are still there -> you're passing a pointer, so when you edit something , youre editing actual data in the pointer location
    z = new int[size];
    z[0] = 100;
    z[1] = INT_MAX;             //  highest num you can store in an integer
    z[2] = INT_MIN;             //  lowest number you can store in an integer
    func2(z);
    cout << z[5] << endl;       //  prints 100 bc changes in func 2 stick w the array
    cout << *z << endl;         //  prints 100
    delete[] z;                 //must use [] or it just deletes the first! & you'll have a memory leak
    
    cout << endl << "W: " << endl;
    w = new int[size];
    w[0] = 100;
    w[1] = INT_MAX;             //  highest num you can store in an integer
    w[2] = INT_MIN;             //  lowest number you can store in an integer
    func2(w);
    cout << w[5] << endl;       //  prints 100
    func3(w);
    cout << w[6] << endl;       //  prints 1000 if arr is pass by reference
    cout << *w << endl;         //  prints 100
    
    cout << *(z + 6) << endl;   //  same as z[6]
    
    /* "Why do you put the * in different places? does it matter?"
     "No, and this goes back to an argument I had with Sterling last semester. He says you should be consistent, but this is my class that I'm not co-teaching bc Sterling is out of country at the moment so do whatever the hell you want. But when Sterling comes back, be consistent." */
    
    cout << endl << "Other: " << endl;
    int * other = w + 6;
    cout << other[0] << endl;   //  same as w[6]
    cout << other[1] << endl;   //  same as w[7]
    cout << *other << endl;     //  same as w[6]
    cout << endl << "Confusing: " << endl;
    int * confusing = other + 2;
    for (int i = 0; i < size; i++) z[i] = i * 10;
    cout << *confusing++ << endl;       //  is it (*confusing)++ or *(confusing++)? --> star has lower precidence
    cout << *confusing << endl;         //  prints out 13 bc above is *(confusing++)
    //delete[] w;                       //  fix?
    
    cout << endl << "John & Jane: " << endl;
    Person* pptr = new Person("John");
    cout << (*pptr).getName() << " (from (*pptr).getName())" << endl;
    cout << pptr -> getName() << " (from pptr -> getName())" << endl;  //  same as above - will both print "John"
    Person p("Jane");
    //                          ***** set these to work for private
    /*p.setSpouse(pptr);                //  could use to marry, or create a marry object like the one above
    pptr->setSpouse(&p);
     */
    p.getMarried(*pptr);
    //cout << *pptr -> spouse << endl;  //  spouse is a private member, cannot acces this blatantly
    cout << p.getSpouse()-> getName() << " (from p.getSpouse()-> getName())" << endl;
    p.getDivorced();
    
    
}





