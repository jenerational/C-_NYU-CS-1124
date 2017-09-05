//
//  main.cpp
//  Lab 10
//
//  Created by Jennifer Walker on 4/8/16.
//  Copyright (c) 2016 Jennifer Walker. All rights reserved.
//

/*
	testRational.cpp
	CS1124
	Implement the class Rational, so that the following program works.
 */

#include <iostream>
#include "Rational.h"

using namespace std;
using namespace CS1124;

int greatestCommonDivisor(int x, int y) {
    while (y != 0) {
        int temp = x % y;
        x = y;
        y = temp;
    }
    return x;
}

//  NON-MEMBER OPERATOR OVERLOADS
//  output operator overload
ostream& operator<<(ostream& os, const Rational& rat) {
    int n = rat.getInt1(), d = rat.getInt2(), div;
    div = greatestCommonDivisor(n, d);
    if (d/div == 1) {
        os << (n/div);
    }
    else {
        os << (n/div) << "/" << (d/div);
    }
    return os;
}

//  input operator overload
istream& operator>>(istream& is, Rational& rat) {
    int n, d;
    char slash;
    is >> n >> slash >> d;
    if (d==0) {
        cerr << "You cannot divide by 0." << endl;
    }
    else {
        rat.setInt1(n);
        rat.setInt2(d);
    }
    return is;
}

//  addition operator overload
Rational operator+(Rational& rat1, Rational& rat2) {
    Rational tempRat(0);
    tempRat+=rat1;
    tempRat+=rat2;
    return tempRat;
}

//  equals operator overload (2 rat)
bool operator==(Rational& rat1, Rational& rat2) {
    int r1n, r1d, r2n, r2d;
    r1n = rat1.getInt1();
    r2n = rat2.getInt1();
    r1d = rat1.getInt2();
    r2d = rat2.getInt2();
    if (r1n == r2n && r1d == r2d) {
        return true;
    }
    else {
        int div1 = greatestCommonDivisor(r1n, r1d);
        int div2 = greatestCommonDivisor(r2n, r2d);
        if (r1n/div1 == r2n/div2 && r1d/div1 == r2d/div2) {
            return true;
        }
        return false;
    }
}

//  does not equal operator overload (2 rat)
bool operator!=(Rational& rat1, Rational& rat2) {
    bool eqBool = rat1==rat2;
    return !eqBool;
}

//  equals operator overload (1 rat 1 num)
bool operator==(int int1, Rational& rat1) {
    int r1n, r1d;
    r1n = rat1.getInt1();
    r1d = rat1.getInt2();
    if (r1n == int1 && r1d == 1) {
        return true;
    }
    else {
        int div1 = greatestCommonDivisor(r1n, r1d);
        if (r1n/div1 == int1 && r1d/div1 == 1) {
            return true;
        }
        return false;
    }
}


int main() {
    //                                  ~* Preset Lab Code *~
    Rational a, b;
    cout << "Input two rational numbers.\n";
    cout << "a: ";
    cin >> a;
    cout << "b: ";
    cin >> b;
    Rational one = 1;
    
    
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "one = " << one << endl;
    cout << "a += b: " << (a += b) << endl;	// Implement as member
    cout << "a = " << a << endl;
    cout << "a + one: " << (a + one) << endl;	// Implement as non-member, but not a friend
    cout << "a == one: " << boolalpha << (a == one) << endl;
    cout << "1 == one: " << boolalpha << (1 == one) << endl;  // How does this work?
    cout << "a != one: " << boolalpha << (a != one) << endl;  // Do not implement as friend.
    
}

/* LAB NOTES
 - Not able to overload:
    - ?: 
    - .
    - :: 
 - Can only overload as member functions
    - =
    - ,
    - []
 - Should only be implemented as non-member functions
    - <<
    - >> 
 - ++ -- needs a dummy int so it knows it post
 */


