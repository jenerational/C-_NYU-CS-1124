//
//  Registrar.h
//  Lab-08
//
//  Created by Jennifer Walker on 11/4/16.
//  Copyright (c) 2016 Jennifer Walker. All rights reserved.
//

#ifndef __Lab_08__Registrar__
#define __Lab_08__Registrar__

#include <stdio.h>
#include <iostream>
#include <vector>
#include "Course.h"
#include "Student.h"

using namespace std;

class Registrar {
public:
    Registrar();
    void printReport();
    void addCourse (const string& courseName);
    void addStudent(const string& studentName);
    void enrollStudentInCourse(const string& studentName, const string& courseName);
    void cancelCourse(const string& courseName);
    void purge();
private:
    string studentName, courseName;
    vector<Course*> courseVec;
    vector<Student*> studentVec;
    bool exists;
};

#endif /* defined(__Lab_08__Registrar__) */
