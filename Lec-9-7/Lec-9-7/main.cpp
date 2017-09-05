//
//  main.cpp
//  Lec-9-7
//
//  Created by Jennifer Walker on 9/7/16.
//  Copyright (c) 2016 Jennifer Walker. All rights reserved.
//  Made with XCode
//

#include <iostream>
// included bc C++ starts out w no modules. Always use
using namespace std;

/* 
 Gotcha's:
 - C++ does not care about whitespace
 - cout is a variable which represents the screen 
 - **must** have a semi colon at the end of each "line"
 - variables must be defined as a type before use
 - need to use "endl" or "/n" to go to the next line when printing
 
 Data Types:
 - int
 - bool
 - double (often use instead of float)
 - char
    - uses single quotes (')
 - string 
    - if using string remember to #include <string>
    - uses doubles quotes (")
 */

int main() {
    //how to define a variable (3 ways)
    int newInt;
    newInt = 20;            // method seen as "a bit iffy"
    int newerInt = 100;
    int newestInt(30);
    
    //how to print
    cout << "Hello, World!" << endl;
    cout << newInt << " " << newerInt << " " << newestInt << endl;
    
    double c;
    cout << "What is the celcius value? ";
    cin >> c;
    //double f = 9/5 * c + 32;      --> cant use bc 9/5 = 1 (bc int
    double f = 9.0/5 * c + 32;
    cout << "The temperature in farenheight is " << f << endl;
    
    //using if statements
    cout << "What format is your temperature? (c/f/k) ";
    char tempLet;
    cin >> tempLet;
    if (tempLet == 'c' || tempLet == 'C') {
        double c;
        cout << "What is the celcius value? ";
        cin >> c;
        double f = 9.0/5 * c + 32;
        cout << "The temperature in farenheight is " << f << endl;
    }
    else if (tempLet == 'f' || tempLet == 'F') {
        double f;
        cout << "What is the farenheight value? ";
        cin >> f;
        double c = 5.0/9 * (f - 32);
        cout << "The temperature in celcius is " << c << endl;
    }
    else {
        double k;
        cin >> k; 
    }
    
    // for loops
    for (int i = 0; i <10; i++) {
        cout << i << endl;
    }
}


