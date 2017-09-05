//
//  main.cpp
//  Lab-02
//
//  Created by Jennifer Walker on 9/16/16.
//  Copyright (c) 2016 Jennifer Walker. All rights reserved.
//

#include <iostream>         //  cout
#include <vector>           //  vector
#include <fstream>          //  ifstream

using namespace std;

struct Molecule {
    vector<string> nameVec;
    int carbonNo;
    int hydroNo;
};

void vectorSort (vector<Molecule>& hcs) {
    for (int i = 0; i < hcs.size(); i++) {
        for (int i = 0; i < hcs.size(); i++) {
            if (hcs[i].carbonNo > hcs[i+1].carbonNo) {
                Molecule temp = hcs[i];
                hcs[i] = hcs[i+1];
                hcs[i+1] = temp;
            }
            else if (hcs[i].carbonNo == hcs[i+1].carbonNo) {
                if (hcs[i].hydroNo > hcs[i+1].hydroNo) {
                    Molecule temp = hcs[i];
                    hcs[i] = hcs[i+1];
                    hcs[i+1] = temp;
                }
            }
        }
    }
}

int main() {
    ifstream ifs("/Users/jwalks/Documents/* Poly Shit/* 03 Fall Sem/CS1124-f/Lab-02/Lab-02/hydrocarbons.txt");
    if (!ifs) {
        cerr << "File not found." << endl;
        exit(1);
    }
    
    string name;            //  to store ifs variables 
    int carbon;
    int hydro;
    char dummy;             //  we need a variable to store C and H but dont need to use them
    vector<Molecule> hydrocarbonVec;
    
    while (ifs >> name >> dummy >> carbon >> dummy >> hydro) {
        bool input = false;
        //for (Molecule x : hydrocarbonVec) {                 //  Mistake: for each loop copies vector instead of edits it
        for (int i=0; i < hydrocarbonVec.size(); i++) {       //  if using a for each loop, must use & after data type name to pass it by reference
            if (hydrocarbonVec[i].carbonNo == carbon && hydrocarbonVec[i].hydroNo == hydro) {
                hydrocarbonVec[i].nameVec.push_back(name);
                input = true;
            }
        }
        if (input == false) {
            Molecule hydrocarbon;
            hydrocarbon.nameVec.push_back(name);
            hydrocarbon.carbonNo = carbon;
            hydrocarbon.hydroNo = hydro;
            hydrocarbonVec.push_back(hydrocarbon);
        }
    }
    
    vectorSort(hydrocarbonVec);
    
    //cout << hydrocarbonVec[0].carbonNo << " " << &hydrocarbonVec[0].carbonNo;  --> tried to use to find out why C0H0 was printing
    
    
    //  prints out vector
    for (Molecule mol : hydrocarbonVec) {
        cout << "C" << mol.carbonNo << "H" << mol.hydroNo;
        for (string n : mol.nameVec) {
            cout << " " << n;
        }
        cout << endl;
    }
    
}

/* Rec Notes:

1) Make Struct: 
 Struct Module {
    string name;
    int NoOfCarbons;
    int NoOfHydrogens;
 {;

2) Store struct in a vector:
Vector <module< hydrocarbons;
    -> need #include <vector> 

3) Initialize and define new Module variable
 Module hydrocarbon;                //  initializes Module variable
 hydrocarbon.name = xyz;            //  assign values to new variable
 hydrocarbon.NoOfCarbons = 6;
 hydrocarbon.NoOfHydrogens = 4;     
 
4) Store hydrocarbons in the vector
 hydrocarbons.push_back(hydrocarbon); 
 
5) how to store multiple names in the vector
 make struct have vector<string> name; instead of string name;
 
6) Sort by number of carbons
 set variable for max # of carbons and go through vector finding the max and repeat
 
7) Print out from vector
 
Also:
 Parameter Passing
*/