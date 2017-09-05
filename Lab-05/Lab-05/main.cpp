//
//  main.cpp
//  Lab 05
//
//  Created by Jennifer Walker on 10/7/16.
//  Copyright (c) 2016 Jennifer Walker. All rights reserved.
//

#include <iostream>             //  for cout
#include <vector>               //  for vectors
#include <string>               //  for strings

using namespace std;

class Student {
public:
    //  Default Student Constructor with default 13 "-1"s for absences
    Student(const string& studentName = "") : sName(studentName), gradeVec(13, -1) {}
    
    //  Accessor
    string getSName() {
        return sName;
    }
    //  Accessor for extra c
    int getGrade(const int& wkIndex) {
        return gradeVec[wkIndex];
    }
    
    //  adds student's grade into gradeVec
    void addGrade (const int& grade, const int wkIndex) {
        gradeVec[wkIndex] = grade;
    }
    
    void stuDisplay() {
        cout << "Student: " << sName << "; Grades:";
        // displays grades for weeks 1 - 13, including the preset absenses
        for (int i = 0; i < 13; i++) {
            cout << " " << gradeVec[i];
        }
        // ends line after grades have all been displayed
        cout << endl;
    }
    
private:
    string sName;
    //  to display each weeks grades or absences
    vector<int> gradeVec;
};

class TimeSlot {
public:
    //  Default TimeSlot Constructor
    TimeSlot (const string& sectionDay = "", const int& class24hr = 0) : day(sectionDay), hr(class24hr) {}
    
    //  allows an outside function to access the time
    int getHR() {
        return hr;
    }
    
    //  allows an outside function to access the day of the section
    string getDay() {
        return day;
    }
    
private:
    //  initializes variables
    string day;
    int hr;
};

class Section : public Student, TimeSlot {
public:
    //  Default Section Constructor
    Section(const string& sectionName = "", const string& sectionDay = "", const int& class24hr = 0) : secName(sectionName), time(TimeSlot(sectionDay, class24hr)) {}
    
    //  allows outside function to access section data
    string getSection () {
        return secName;
    }
    
    //  adds pointer to student
    void addStudent(const string& studentName) {
        Student* newStudent = new Student(studentName);
        studentVec.push_back(newStudent);
    }
    
    //  displays specified section
    void display () {
        //determines whether to display am or pm
        if (time.getHR() <= 12) {
            cout << "Section: " << secName << "; " << time.getDay() << " " << time.getHR() << "AM" << endl;
        }
        else {
            cout << "Section: " << secName << "; " << time.getDay() << " " << time.getHR()-12 << "PM" << endl;
        }
        //  goes through the student vector and displays each student's grades through the Student class
        for (Student* student : studentVec) {
            student -> stuDisplay();
        }
        cout << endl;
    }
    
    //  points to student. Needed here so function can access the student pointer vector
    void addGrade (const string& studentName, const int& grade, const int& wkIndex) {
        //  for Student in studentVec, if it equals S
        for (Student* student : studentVec) {
            if (studentName == student -> getSName()) {
                student -> addGrade(grade, wkIndex);
            }
        }
    }
    //  extra credit: displays section average for certain week
    void displayAverageForWeek(const int& wkIndex) {
        cout << "Average for section " << secName << " for week " << wkIndex << " is: ";
        float avgTotal = 0;
        for (Student* student : studentVec) {
            avgTotal += student->getGrade(wkIndex-1);
        }
        cout << avgTotal/studentVec.size() << endl;
    }
    
    //  clears student pointer vector
    void reset () {
        studentVec.clear();
    }
    
private:
    //  initializes variables
    string secName, day;
    int hr;
    vector<Student*> studentVec;
    TimeSlot time;
};

class LabWorker : public Section, Student {
public:
    //  Default LabWorker Constructor
    LabWorker(const string& labWorkerName = "") : LWName(labWorkerName) {}
    
    
    //  creates a pointer to section
    void addSection(Section& section) {
        this -> sectionName = &section;
    }
    
    //  allows Lab Worker to add in grades
    void addGrade(const string& studentName, const int& grade, const int& wkIndex) {
        //  ***POINTS TO SECTION
        sectionName -> addGrade(studentName, grade, wkIndex);
    }
    
    
    //  displays Lab Worker's section's grades
    void displayGrades() {
        cout << LWName << " has ";
        sectionName -> display();
        cout << endl;
    }
    
    //  extra C: display week average
    void displayAverageForWeek(const int& wkIndex) {
        sectionName -> displayAverageForWeek(wkIndex);
    }
    
private:
    //  initializes variables
    string LWName;
    Section* sectionName;
};

int main() {
    // lab workers
    LabWorker moe( "Moe" );
    LabWorker jane( "Jane" );
    
    // sections and setup and testing
    Section secA2( "A2", "Tuesday", 16 );
    //secA2.loadStudentsFromFile( "A2.txt" );
    secA2.addStudent("John");
    secA2.addStudent("George");
    secA2.addStudent("Paul");
    secA2.addStudent("Ringo");
    
    cout << "\ntest A2\n";    // here the modeler-programmer checks that load worked
    secA2.display();          // YOU'll DO THIS LATER AS: cout << secA2 << endl;
    moe.addSection( secA2 );
    moe.displayGrades();       // here the modeler-programmer checks that adding the Section worked
    
    Section secB3( "B3", "Thursday", 11 );
    //secB3.loadStudentsFromFile( "B3.txt" );
    secB3.addStudent("Thorin");
    secB3.addStudent("Dwalin");
    secB3.addStudent("Balin");
    secB3.addStudent("Kili");
    secB3.addStudent("Fili");
    secB3.addStudent("Dori");
    secB3.addStudent("Nori");
    secB3.addStudent("Ori");
    secB3.addStudent("Oin");
    secB3.addStudent("Gloin");
    secB3.addStudent("Bifur");
    secB3.addStudent("Bofur");
    secB3.addStudent("Bombur");
    
    cout << "\ntest B3\n";    // here the modeler-programmer checks that load worked
    secB3.display();          // YOU'll DO THIS LATER AS: cout << secB3 << endl;
    jane.addSection( secB3 );
    jane.displayGrades();      // here the modeler-programmer checks that adding Instructor worked
    
    
    // setup is complete, now a real world scenario can be written in the code
    // [NOTE: the modeler-programmer is only modeling joe's actions for the rest of the program]
    
    // week one activities
    cout << "\nModeling week: 1\n";
    moe.addGrade( "John", 7, 1 );
    moe.addGrade( "Paul", 9, 1 );
    moe.addGrade( "George", 7, 1 );
    moe.addGrade( "Ringo", 7, 1 );
    cout << "End of week one\n";
    moe.displayGrades();
    
    // week two activities
    cout << "\nModeling week: 2\n";
    moe.addGrade( "John", 5, 2 );
    moe.addGrade( "Paul", 10, 2 );
    moe.addGrade( "Ringo", 0, 2 );
    cout << "End of week two\n";
    moe.displayGrades();
    
    //  extra credit
    moe.displayAverageForWeek(2);
    
    //test that reset works  // NOTE: can we check that the heap data was dealt with?
    cout << "\ntesting reset()\n";
    secA2.reset();
    secA2.display();
    moe.displayGrades();
    
    
}
