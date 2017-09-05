//
//  main.cpp
//  Lec-9-14
//
//  Created by Jennifer Walker on 9/14/16.
//  Copyright (c) 2016 Jennifer Walker. All rights reserved.
//

#include <iostream>     // cout, cin, cerr
#include <fstream>      //  to load in files
#include <vector>       //  to use vectors

using namespace std;


// void functions are used when nothing is being returned

//  & --> reference parameter. Instead of making a copy (no &) it assigns another name to the same variable.
//  Thus, the variable will hold onto the changed value when the function is done
//  Important to do so the program isn't unnecessarily duplicating variables and taking up memory
void cChange (double& temp) {
    double f = 9.0/5 * temp + 32;
    double k = temp + 273;
    cout << "The temperature " << temp << "˚C is equal to " << f << "˚F or " << k << "˚K." << endl;
}

void fChange (double& temp) {
    double c = 5.0/9 * (temp - 32);
    double k = c + 273;
    cout << "The temperature " << temp << "˚F is equal to " << c << "˚C or " << k << "˚K." << endl;
}

void kChange (double& temp) {
    double c = temp - 273;
    double f = 9.0/5 * c + 32;
    cout << "The temperature " << temp << "˚K is equal to " << c << "˚C or " << f << "˚F." << endl;
}

// This is a Global Variable (exists outside of any function/main):
int x = 100;        // NEVER create a global variable. It's like sticking a fork in an outlet.

int main() {
    ifstream inFile("/Users/jwalks/Documents/* Poly Shit/* 03 Fall Sem/CS1124-f/Lec-9-12/Lec-9-12/sampleFile.txt");
    if (!inFile) {
        cerr << "File does not exist." << endl;
        exit (1);
    }
    
    char tempLet;
    double tempAmt;
    
    while (inFile >> tempLet) {
        inFile >> tempAmt;
        if (tempLet == 'c' || tempLet == 'C') {
            cChange(tempAmt);
        }
        else if (tempLet == 'f' || tempLet == 'F') {
            fChange(tempAmt);
        }
        else {
            kChange(tempAmt);
        }
    }

    
    const double freezing = 32;         //  const means the variable cannot be changed
    cout << "The freezing temperature in farenheight is " << freezing << endl;
    cout << endl;
    
    
    
    
    //                   VECTORS:    Stores large amounts of info of the same data type
    //                               need to #include <vector>
    
    vector<int> intV;               //  *empty* vector of integers
    
    for (int i = 0; i < 100; i++) {
        intV.push_back(i*2);        //  one by one adds each iteration of (i*2) to the back of the vector
    }
    
    for (int i = 0; i < 100; i++) {
        cout << intV[i] << " ";     //  prints each int in intV one by one
    }   cout << endl;
    
    cout << endl;
    //  New & better vector printing method developed in 2011 - THE RANGED FOR!
    //  Ranged for was needed in C++ bc every other language had it and C++ was falling behind
    for (int i : intV) {
        cout << i << " ";
    }   cout << endl;               //  when all values are printed, ranged for ends automatically
    
    intV.clear();                   //  clears all values in the vector
    
    
    
    
    //                  STRUCTS:    Creates a data type
    //                              Though I have these inside, make structs outside main 
    
    struct Date {                   //  creates data type for struct below
        int day;
        int month;
        int year;
    };
    
    struct Person {                 //  creates "Person" data type to store info about persons
        string name;
        int height;                 //  inches
        double weight;              //  lbs
        Date DOB;                   //  data type created above
    };                              //  need to end struct w ;
    
    Date Birthday;
    Birthday.day = 26;
    Birthday.month = 11;
    Birthday.year = 1995;
    
    Person self;
    self.name = "Jennie";
    self.height = 67;
    self.weight = 145.3;
    self.DOB = Birthday;
    

    vector<Person> personV;
    personV.push_back(self);
    
    for (Person p : personV) {
        cout << p.name;
        if p.DOB ; 
    }
    


}






