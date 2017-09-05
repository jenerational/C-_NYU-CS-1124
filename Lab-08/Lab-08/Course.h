//
//  Course.h
//  Lab-08
//
//  Created by Jennifer Walker on 11/4/16.
//  Copyright (c) 2016 Jennifer Walker. All rights reserved.
//

#ifndef __Lab_08__Course__
#define __Lab_08__Course__

#include <stdio.h>
#include <iostream>
#include <vector>
#include "Student.h"

using namespace std;

class Course {
public:
    //
    Course(const string& courseName);
    void display();
    void enrollStudentInCourse(const string& studentName);
    string getName();
private:
    string name, studentName;
    bool exists;
    vector<Student*> studentInCourseVec;
    
};

#endif /* defined(__Lab_08__Course__) */
