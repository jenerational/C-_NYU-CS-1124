//
//  main.cpp
//  Lab-01
//
//  Created by Jennifer Walker on 9/9/16.
//  Copyright (c) 2016 Jennifer Walker. All rights reserved.
//
/*  Instructions:
        1 - read line by line
            - use method getline([inprogramfilename],line)
            - print line count at the end 
        2 - read char by char
            - print char count (including whitespace) at the end
                - use ifs >> noskipws;
                - to skip ws again, use ifs >> skipws;
*/

#include <iostream>
#include <fstream>

using namespace std;

int main() {
    //  load in file
    ifstream ifs ("/Users/jwalks/Documents/* Poly Shit/* 03 Fall Sem/CS1124-f/Lab-01/Lab-01/jabberwocky.txt");
    //  ifstream ifs;
    //  ifs.open()
    if (!ifs) {
        cout << "File cannot be located at this time." << endl;
        exit(1);
    }
    //  initialize variables
    string line = "", word = "";
    char myChar;
    int lineCnt = 0, wordCnt = 0, charCnt = 0;
    
    // print and count lines
    while (getline(ifs, line)) {
        cout << line << endl;
        lineCnt += 1;               // can also do "lineCnt++;"
    }
    cout << "The number of lines is " << lineCnt << "." << endl;
    
    //  close and reopen file
    ifs.close();
    ifs.open("/Users/jwalks/Documents/* Poly Shit/* 03 Fall Sem/CS1124-f/Lab-01/Lab-01/jabberwocky.txt");
    
    // count words
    while (ifs >> word) {
        wordCnt += 1;
    }
    cout << "The number of words is " << wordCnt << "." << endl;
    
    //  close and reopen file
    ifs.close();
    ifs.open("/Users/jwalks/Documents/* Poly Shit/* 03 Fall Sem/CS1124-f/Lab-01/Lab-01/jabberwocky.txt");

    // count chars
    ifs >> noskipws;
    while (ifs >> myChar) {
        charCnt += 1;
    }
    cout << "The number of chars is " << charCnt << "." << endl;
    
    // close file
    ifs.close();
    
}







