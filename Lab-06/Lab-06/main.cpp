//
//  main.cpp
//  Lab-06
//
//  Created by Jennifer Walker on 10/14/16.
//  Copyright (c) 2016 Jennifer Walker. All rights reserved.
//

#include <iostream>         //  for cout
#include <vector>           //  for pages vector
using namespace std;


//      PROGRAM FOR TASKS 2-15:

class PrintedMaterial {
public:
    //  Default Constructor
    PrintedMaterial(const unsigned& numOfPages = 0) : numberOfPages(numOfPages) {}
    
    //  "virtual" added in task 11
    //  virtual will only be invoked in the case of a pointer
    virtual
    //  "Number of Pages: " added in task 8
    //  Task 13: cannot make const bc TextBook display function doesnt have the same
    //  return type as the function (void vs const void)
    //void displayNumPages() const { cout << "Number of Pages: " << numberOfPages << endl; } //  << endl; added in task 8 bc of no line break // commented out for task 14
    void displayNumPages() const = 0;
    
protected:
private:
    unsigned numberOfPages;
};

class Magazine : public PrintedMaterial {
public:
    //Magazine(const unsigned& numOfPages = 0) : numberOfPages(numOfPages) {}
    Magazine(unsigned numPages) : PrintedMaterial(numPages) {}
    
    void displayNumPages() const {
        cout << "Magazine: " << endl; 
        PrintedMaterial::displayNumPages();
    }
    
protected:
private:
};

class Book : public PrintedMaterial {
public:
    //Book(const unsigned& numOfPages = 0) : numberOfPages(numOfPages) {}
    Book(unsigned numPages) : PrintedMaterial(numPages) {}
    
protected:
private:
    //unsigned numberOfPages;
};

class TextBook : public Book {
public:
    //TextBook(const unsigned& numOfPages = 0) : numberOfPages(numOfPages) {}
    TextBook(unsigned numPages, unsigned numIndxPgs) : Book(numPages), numOfIndexPages(numIndxPgs) {}
    
    void displayNumPages() const {
        // "Number of Index Pages: " and "Number of Pages: " added in task 8
        cout << "Textbook: \nNumber of Index Pages: " << numOfIndexPages << endl;
        PrintedMaterial::displayNumPages();
        //  cout << "Number of Pages: "; << numOfPages << endl; --> needed to go back to original constructor //  << endl; added in task 8 bc of no line break
    }
protected:
private:
    //unsigned numberOfPages;
    unsigned numOfIndexPages;
    unsigned numOfPages;            //  Added in task 8 bc of undeclared identifier in display
};

class Novel : public Book {
public:
    //Novel(const unsigned& numOfPages = 0) : numberOfPages(numOfPages) {}
    Novel(unsigned numPages) : Book(numPages) {}
    
    void displayNumPages() const {
        cout << "Novel: " << endl;
        PrintedMaterial::displayNumPages();
    }
    
protected:
private:
    //unsigned numberOfPages;
};

//  Task 12
void displayNumberOfPages(const PrintedMaterial& anyPGDisplay) {
    anyPGDisplay.displayNumPages();
}

//  is called by public method in classes
void PrintedMaterial::displayNumPages() const {
    cout << "Pages: " << numberOfPages << endl;
}

// tester/modeler code
int main()
{
    /*TextBook t;
     t.displayNumPages();            //  displayed "0" for task 6
     Novel n;
     n.displayNumPages();            //  displayed "0" for task 6
     Magazine m; */
    
    //  Task 7
    TextBook t(5430, 234);
    Novel n(213);
    Magazine m(6);
    //t.displayNumPages();
    //n.displayNumPages();
    //m.displayNumPages();
    
    //  Task 9
    /* PrintedMaterial pm = t; // like putting a t into a vector of PrintedMaterials
     pm.displayNumPages(); */
    
    //  Task 10
    PrintedMaterial* pmPtr;
    pmPtr = &t;
    // instead of putting an actual PrintedMaterial
    // object into the vector, we put a pointer to
    // a PrintedMaterial object (t) into a vector
    // of pointers-to-PrintedMaterial
    // (that is, pointers to the Base class)
    // we'll be "managing" our objects by using
    // pointers to PrintedMaterial values.
    
    //pmPtr->displayNumPages();
    
    //  Task 15
    //  creates vector with PM pointers that pushes back page addresses
    vector<PrintedMaterial*> printPageNums;
    printPageNums.push_back(&t);
    printPageNums.push_back(&n);
    printPageNums.push_back(&m);
    
    //  cycles through and adds vector
    for (int i = 0; i < printPageNums.size(); i++) {
        printPageNums[i] -> displayNumPages();
        //  ends line between displays
        cout << endl;
    }
}


