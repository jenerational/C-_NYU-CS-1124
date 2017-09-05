//
//  main.cpp
//  Lab-08
//
//  Created by Jennifer Walker on 11/3/16.
//  Copyright (c) 2016 Jennifer Walker. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "Registrar.h"

using namespace std;

int main() {
    //  opens warriors.txt
    ifstream ifs("/Users/jwalks/Documents/* Poly Shit/* 03 Fall Sem/CS1124-f/Lab-08/Lab-08/sepcomp.txt");
    //  sends error message if unable to open
    if(!ifs) {
        cerr << "Unable to open sepcomp.txt." << endl;
        exit(1);
    }
    
    Registrar registrar;
    
    //  defines variables
    string cmd, courseName, studentName;
    
    //  inputs info from file
    while (ifs >> cmd) {
        //checks to see if print report command
        if (cmd == "PrintReport") {
            registrar.printReport();
        }
        //  check to see if add course command
        else if (cmd == "AddCourse") {
            //  adds course into registrar
            (ifs >> courseName); {
                registrar.addCourse(courseName);
            }
        }
        else if (cmd == "AddStudent") {
            //  adds students to the registrar
            (ifs >> studentName); {
                registrar.addStudent(studentName);
            }
        }
        else if (cmd == "EnrollStudentInCourse") {
            // Enrolls a student into a specific course
            (ifs >> studentName >> courseName); {
                registrar.enrollStudentInCourse(studentName, courseName);
            }
        }
        else if (cmd == "CancelCourse") {
            // cancels a specific course
            registrar.cancelCourse(courseName);
        }
        else if (cmd == "Purge") {
            // deletes all vectors of students and courses
            registrar.purge();
        }
    }
    
    //  closes warriors.txt
    ifs.close();
}
