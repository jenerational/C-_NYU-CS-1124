//
//  main.cpp
//  Lec-9-12
//
//  Created by Jennifer Walker on 9/12/16.
//  Copyright (c) 2016 Jennifer Walker. All rights reserved.
//
//  Lecture #2
//

#include <iostream>
#include <fstream>          //   reads and writes out to files

using namespace std;

int main() {
//  CS have three different types of loops
    //  1: While Loops
        int x = 0, newX = 0;
        while (x < 7) {     //  while ([condition]) { [code] }
            cout << x;
            x += 1;
        }
    
        cout << endl;
        //  curly brackets not needed if loop is one line of code. Ex:
        while (newX < 7) x+= 1; // complete loop 
        cout << newX;
    
        cout << endl;
    //  2: Do While Loops
        //  a way to guarentee the code runs at least once
        int y = 0;
        do {
            cout << y;
            y += 1;
        } while (y < 7);
    
    //  3: For Loops
    //  for (initialization; Text; Incrementation) { [code ] }
    //  for (;;); is an infinite loop and a great way to fuck w people's code
    
    
    //  prints out nothing bc else is lined up w previous if --> why syntax is so important
    int num = 100;
    if  (num > 1000)
        if (num > 2000)     //  if and following is seen as one line of code
            cout << 'A';
    else
        cout << 'B';
    
    cout << endl;
    
    
    
    
/* THE ONLY MATH OPERATORS
     +
     -
     *
     /
     %
     FOR POWER: #include <cmath> pow([base], [exp])
*/
    
    
    
    
//  Reading and Writing Files
    ofstream outFile;           //  creates object (not yet open)
    outFile.open("/Users/jwalks/Documents/* Poly Shit/* 03 Fall Sem/CS1124-f/Lec-9-12/Lec-9-12/sampleFile.txt");        //  opens the object
    // can also do: ofstream outfile(filename); -> will create *and* open the file
    
    outFile << "C 100" << endl << "K 373" << endl << "F 212" << endl << "C 0" << endl << "C 20" << endl << "K 273";
    outFile.close();            // closes the object
    
    ifstream inFile("/Users/jwalks/Documents/* Poly Shit/* 03 Fall Sem/CS1124-f/Lec-9-12/Lec-9-12/sampleFile.txt");
    if (!inFile) {
        cerr << "File does not exist." << endl;
        exit (1);       //  can also do return 1; which exits from main, thus ending the program 
    }
    
    /* How the file is read:
     1) Skips leading whitespace
     2) Read in "valid" chars (valid is variable determined)
     3) STOPS when reaching WS or invalid chars
     4) Stores result in given variable
    */
    
    char tempLet;
    double tempAmt;
    
    while (inFile >> tempLet) {
        inFile >> tempAmt;
        
        if (tempLet == 'c' || tempLet == 'C') {
            double f = 9.0/5 * tempAmt + 32;
            double k = tempLet + 273;
            cout << "The temperature is " << f << "˚F or " << k << "˚K." << endl;
        }
        else if (tempLet == 'f' || tempLet == 'F') {
            double c = 5.0/9 * (tempAmt - 32);
            cout << "The temperature in celcius is " << c << endl;
        }
        else {
            double c = tempAmt - 273;
            double f = 9.0/5 * c + 32;
            cout << "The temperature is " << f << "˚F or " << c << "˚C." << endl;
        }

    }
    
    
    // for loops
    for (int i = 0; i <10; i++) {
        cout << i << endl;
    }
}



