//
//  Course.cpp
//  Lab-08
//
//  Created by Jennifer Walker on 11/4/16.
//  Copyright (c) 2016 Jennifer Walker. All rights reserved.
//

#include "Course.h"

Course::Course(const string& courseName) : name(courseName) {}

void Course::display() {
    cout << name << ":" << endl;
    for (Student* student : studentInCourseVec) {
        student -> display();
    }
    if (studentInCourseVec.size() == 0) {
        cout << "No students currently enrolled." << endl;
    }
}

void Course::enrollStudentInCourse(const string& studentName) {
    //  makes addition to vector of pointers to Student via the heap
    Student* newStudent = new Student(studentName);
    //  makes bool saying student does not already exist in the vector
    exists = false;
    //  checks to see if the student is already in the course/vector
    for (int i=0; i < studentInCourseVec.size(); i++) {
        if (studentInCourseVec[i] == newStudent) {
            exists = true;
        }
    }
    //  if student is not in the course/vector, it adds it
    if (exists == false) {
        studentInCourseVec.push_back(newStudent);
    }
}

string Course::getName() {
    return name;
}
