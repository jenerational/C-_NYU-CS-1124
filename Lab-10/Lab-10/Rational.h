//
//  Rational.h
//  Lab 10
//
//  Created by Jennifer Walker on 4/8/16.
//  Copyright (c) 2016 Jennifer Walker. All rights reserved.
//

#ifndef __Lab_10__Rational__
#define __Lab_10__Rational__

#include <stdio.h>
#include <iostream>

namespace CS1124 {
    
    class Rational {
    public:
        //  constuctors
        Rational(); 
        Rational(const int& integer1);
        //  accessors
        int getInt1()const;
        int getInt2()const;
        //  mutators
        void setInt1(int& newInt);
        void setInt2(int& newInt);
        //  op overloads
        Rational& operator=(const Rational& rhs);
        Rational& operator+=(const Rational& rhs); 
    private:
        int int1, int2;
    };
}

#endif /* defined(__Lab_10__Rational__) */
