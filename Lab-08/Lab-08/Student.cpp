//
//  Student.cpp
//  Lab-08
//
//  Created by Jennifer Walker on 11/4/16.
//  Copyright (c) 2016 Jennifer Walker. All rights reserved.
//

#include "Student.h"

Student::Student(const string& studentName) : name(studentName) {}

void Student::display() {
    cout << name << endl;
}

string Student::getName() {
    return name;
}



