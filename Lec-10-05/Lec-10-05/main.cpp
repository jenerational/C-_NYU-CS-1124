//
//  main.cpp
//  Lec-10-05
//
//  Created by Jennifer Walker on 10/5/16.
//  Copyright (c) 2016 Jennifer Walker. All rights reserved.
//

#include <iostream>

using namespace std;



class Pet { //  known as: base class, super class, parent class
    string name;
    int age;
protected:  //  allows color to be accessed by derived classes
    string color;
public:
    //  dog cant access - constructors are never derived (but default pet constructor will stil be called)
    Pet() : age(0) {}
    Pet(string newName) : name(newName), age(0) {}
    string getColor() const {return color;}
    string getName() const {return name;}
    int getAge() const {return age;}
    void rename(string newName) { name = newName; }
    void paint(string newColor) { color = newColor; }
    void celebrateBirthday() { age++; }
};

//  pet is public bc using public inheretance,
//  private inhereted much more rare, more of a "has a" where public is "is a"
class Dog : public Pet {  //    known as: derived class, sub class, child class
    string breed;
public:
    Dog(string newName = "") :Pet(newName) {}
    void speak() {cout << "Woof woof." << endl;}    //  would put const here or no??
    void setBreed(string newBreed) {breed = newBreed;}
    string getBreed() const {return breed;}
    //  override
    void celebrateBirthday() {
        Pet::celebrateBirthday();   // x:: - scope resolution operator
        if (getAge() <= 10) {
            color = "grey";         //  bc color is protected
            //  paint("grey");      //  could also do
        }
    }
};

//  Order:  Base, Compsition (aka Member), Derived
class BaseMember {
public:
    BaseMember() { cout << "BaseMember Default constructor" << endl; }
};
    
class DerivedMember {
    public:
    DerivedMember() { cout << "DerivedMember Default constructor" << endl; }
};

class Base {
    BaseMember m;
public:
    Base() {cout << "Base Default constructor" << endl;}
    Base( int n) { cout << "Base one argument constructor" << endl; }
    void BaseFunc() {cout << "Inside Base's BaseFunc." << endl; }
};

class Derived : public Base {
    DerivedMember m2;
public:
    Derived() {cout << "Derived Default Constructor" << endl;}
    Derived(double n)  {cout <<  "Derived one argument constructor" << endl;}
    Derived(double n, int y) : Base(y) {cout << "Derived two argument constructor" << endl;}
    void BaseFunc() {cout << "Inside Derived's BaseFunc." << endl; }
    void DerivedFunc() { cout << "Inside Derived Func." << endl; }
};


int main() {
    Dog good;
    good.rename("Fido");
    
    Dog gud("Fifi");
    
    //  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~    Testing     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  //
    Derived(d1);
    //  Results:    Base member, base default, derived member, derived default
    cout << endl;   //  done
    Derived d2(8);
    //  Results:    Base member, base default, derived member, derived one argument
    cout << endl;   //  done
    Derived d3(2, 3);
    //  Results:    base memeber, base one argument, derived member derived two argument
    cout << endl;   //  done
    //  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~     Testing Done    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  //
    
    Base basey;
    Derived derey;
    basey = derey;  //  slicing
    //derey = basey;  //  not allowed *right now* - > "no viable overloaded '='"
    
    int x;
    double d = 5.5;
    x = d;          //  comparison -> can be done but you lose some of it (( truncated ))
    
    Base * basePtr = &derey;    //  Polymorphism , always allowed (poly - many, morph - form/face)
    //basePtr -> DerivedFunc(); //  cant do bc even though Derieved object, its a base ptr;
    basePtr->BaseFunc();
    //Derived * derivedPtr = &basey;  //  NEVER ALLOWED
    
}




