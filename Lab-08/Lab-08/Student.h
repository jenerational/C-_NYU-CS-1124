//
//  Student.h
//  Lab-08
//
//  Created by Jennifer Walker on 11/4/16.
//  Copyright (c) 2016 Jennifer Walker. All rights reserved.
//

#ifndef __Lab_08__Student__
#define __Lab_08__Student__

#include <stdio.h>
#include <iostream>

using namespace std;

class Student {
public:
    //
    Student(const string& studentName);
    void display();
    string getName();
private:
    string name;
};

#endif /* defined(__Lab_08__Student__) */
