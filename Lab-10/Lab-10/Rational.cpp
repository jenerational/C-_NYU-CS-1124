
//
//  Rational.cpp
//  Lab 10
//
//  Created by Jennifer Walker on 4/8/16.
//  Copyright (c) 2016 Jennifer Walker. All rights reserved.
//

#include "Rational.h"

using namespace std;

namespace CS1124 {
    //  Constructors
    Rational::Rational() {}
    Rational::Rational (const int& integer1) : int1(integer1), int2(1) {}
    
    //  Accessors
    int Rational::getInt1() const {return int1;}
    int Rational::getInt2() const {return int2;}

    //  Mutators
    void Rational::setInt1(int& newInt) {int1=newInt;}
    void Rational::setInt2(int& newInt) {int2=newInt;}
    
    //  Operator Overloads
    Rational& Rational::operator=(const Rational& rhs) {
        if (this == &rhs) //    tests for self-assignment
            return *this;
        else {
            int1 = rhs.getInt1();
            int2 = rhs.getInt2();
        }
        return *this;
    }
    Rational& Rational::operator+=(const Rational& rhs) {
        if (int2 == rhs.getInt2()) {
            int1 += rhs.getInt1();
        }
        else if (int1 == 0 && int2 == 0) {
            int1 = rhs.getInt1();
            int2 = rhs.getInt2();
        }
        else {
            int temp = int2 * rhs.getInt1();
            int2 *= rhs.getInt2();
            int1 *= rhs.getInt2();
            int1 += temp;
        }
        return *this;
    }


    
    
    
}