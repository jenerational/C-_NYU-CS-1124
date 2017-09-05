//
//  main.cpp
//  HW-01
//
//  Created by Jennifer Walker on 9/21/16.
//  Copyright (c) 2016 Jennifer Walker. All rights reserved.
//

#include <iostream>             //  cout, cin, cerr
#include <fstream>              //  ifstream
#include <vector>               //  vector
#include <sstream>              //  istringstream

using namespace std;

//  Finds shift amount listed in the file
int findShift(ifstream& ccFile) {
    string line;
    getline(ccFile, line);
    int shiftBy;
    istringstream(line) >> shiftBy;
    return shiftBy;
}

//  function reads instream file and decrypts lines
void readFile(ifstream& ccFile, vector<string>& txtLines, const int& shiftBy) {
    string line;
    while (getline(ccFile, line)) {
        for (char& ch : line) {
            if (isalpha(ch) && !isupper(ch)) {
                ch -= shiftBy;
                if (ch < 'a') {
                    ch += 26;
                }
            }
        }
        txtLines.push_back(line);
    }
}

int main() {
    //  names incoming cypher file file ccFile
    ifstream ccFile("/Users/jwalks/Documents/* Poly Shit/* 03 Fall Sem/CS1124-f/HW-01/HW-01/encrypted.txt");
    //  creates error message if file isn't found
    if (!ccFile) {
        cerr << "File cannot be found." << endl;
        exit(1);
    }
    
    //  finds shift w function
    int shiftBy = findShift(ccFile);
    
    //  initializes vector of strings and reads file into vector using function
    vector<string> txtLines;
    readFile(ccFile, txtLines, shiftBy);
    
    //  prints decrypted lines
    for (size_t i = txtLines.size(); i > 0; i--) {
        cout << txtLines[i-1] << "\n";
    }
}
