//
//  Registrar.cpp
//  Lab-08
//
//  Created by Jennifer Walker on 11/4/16.
//  Copyright (c) 2016 Jennifer Walker. All rights reserved.
//

#include "Registrar.h"

Registrar::Registrar() {}

void Registrar::printReport() {
    //  checks to see if there are any courses in the registrar
    if (courseVec.size() > 0) {
        //  prints each course with the students in it
        for (Course* course : courseVec) {
            course -> display();
        }
    }
    else {
        cout << "No courses or students added yet." << endl;
    }
}

void Registrar::addCourse(const string& courseName) {
    //  makes addition to vector of pointers to Course via the heap
    Course* newCourse = new Course(courseName);
    //  makes bool saying course does not already exist in the vector
    exists = false;
    //  checks to see if the course is already in the registrar/vector
    for (int i=0; i < courseVec.size(); i++) {
        if (courseVec[i] == newCourse) {
            exists = true;
        }
    }
    //  if course is not in the registrar/vector, it adds it
    if (exists == false) {
        courseVec.push_back(newCourse);
    }
}

void Registrar::addStudent(const string& studentName) {
    //  makes addition to vector of pointers to Student via the heap
    Student* newStudent = new Student(studentName);
    //  makes bool saying student does not already exist in the vector
    exists = false;
    //  checks to see if the student is already in the registrar/vector
    for (int i=0; i < studentVec.size(); i++) {
        if (studentVec[i] == newStudent) {
            exists = true;
        }
    }
    //  if student is not in the registrar/vector, it adds it
    if (exists == false) {
        studentVec.push_back(newStudent);
    }
}

void Registrar::enrollStudentInCourse(const string& studentName, const string& courseName) {
    //  error checks to make sure student exists in vector
    exists = false;
    for (int i = 0; i < studentVec.size(); i++) {
        string studentVecName = studentVec[i]->getName();
        if (studentName == studentVecName) {
            exists = true;
        }
    }
    if (exists == true) {
        // find course name in vec of pointers, pass that specific pointer
        for (int i = 0; i < courseVec.size(); i++) {
            string courseVecName = courseVec[i] -> getName();
            if (courseName == courseVecName) {
                courseVec[i] -> enrollStudentInCourse(studentName);
            }
        }
    }
    else {
        cerr << "This student does not exist." << endl;
    }
}

void Registrar::cancelCourse(const string& courseName) {
    //  looks through vector for course name to delete.
    for (int i = 0; i < courseVec.size(); i++) {
        string courseVecName = courseVec[i] -> getName();
        if (courseName == courseVecName) {
            cout << courseName << " has been canceled." << endl;
            courseVec.erase(courseVec.begin()+i);
        }
    }
}

void Registrar::purge() {
    //  deletes pointers and then clears the vector .
    for (int i = 0; i < courseVec.size(); i++) {
        delete courseVec[i];
    }
    courseVec.clear();
    //  deletes pointers and then clears the vector .
    for (int i = 0; i < studentVec.size(); i++) {
        delete studentVec[i];
    }
    studentVec.clear();
    cout << "The registrar has been purged." << endl;
}


