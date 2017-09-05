//
//  main.cpp
//  HW-04
//
//  Created by Jennifer Walker on 10/14/16.
//  Copyright (c) 2016 Jennifer Walker. All rights reserved.
//


#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>

using namespace std;

class Warrior {
public:
    //  Default Warrior Constructor
    Warrior (const string& warriorName = "", const int& warriorStrength = 0) : name(warriorName), strength(warriorStrength) {}
    void display() {
        cout << "\t" << name << ": " << strength << endl;
    }
    string getName() const {
        return name;
    }
    
    int getStrength() const {
        return strength;
    }
    
    void editStrength(int& strengthRatio) {
        strength = strength * strengthRatio;
    }
private:
    string name;
    int strength, strengthRatio;
    
};

class Noble {
public:
    //  Default Noble Constructor
    Noble (const string& nobleName = "") : name(nobleName) {}
    
    void hire(const string& fighter, vector<Warrior*>& warVec){
        for (int i = 0; i < warVec.size(); i++) {
            if (fighter == warVec[i]->getName()) {
                warriorVec.push_back(warVec[i]);
                warVec.erase(warVec.begin()+i);
            }
        }
    }
    
    void fire (const string& fighter, vector<Warrior*>& warVec) {
        for (int i = 0; i < warriorVec.size(); i++) {
            if (fighter == warriorVec[i]->getName()) {
                warVec.push_back(warriorVec[i]);
                cout << warriorVec[i]->getName() << " is no longer employed by " << name << endl;
                warriorVec.erase(warriorVec.begin()+i);
                break;
            }
        }
    }
    
    void battle (Noble& nobleFoe) {
        //  initializes strength variables
        int n1strength = 0, n2strength = 0;
        //  gets first noble's total strength
        for (int i = 0; i < warriorVec.size(); i++) {
            n1strength += warriorVec[i] -> getStrength();
        }
        //  gets second noble's total strength
        for (int i = 0; i < nobleFoe.warriorVec.size(); i++) {
            n2strength += nobleFoe.warriorVec[i] -> getStrength();
        }
        //  prints battle statement
        cout << name << " battles " << nobleFoe.name << endl;
        //  "if neither noble is dead yet..."
        if (n1strength != 0 && n2strength != 0 ) {
            if (n1strength > n2strength) {
                cout << name << " defeats " << nobleFoe.name << endl;
                strengthRatio = n2strength / n1strength;
                for (int i = 0; i < warriorVec.size(); i++) {
                    warriorVec[i] -> editStrength(strengthRatio);
                }
                strengthRatio = 0;
                for (int i = 0; i < nobleFoe.warriorVec.size(); i++) {
                    nobleFoe.warriorVec[i] -> editStrength(strengthRatio);
                }
            }
            else if (n1strength < n2strength) {
                cout << nobleFoe.name << " defeats " << name << endl;
                strengthRatio = n1strength / n2strength;
                for (int i = 0; i < nobleFoe.warriorVec.size(); i++) {
                    nobleFoe.warriorVec[i] -> editStrength(strengthRatio);
                }
                strengthRatio = 0;
                for (int i = 0; i < warriorVec.size(); i++) {
                    warriorVec[i] -> editStrength(strengthRatio);
                }
            }
            else {
                cout << "Mutual Annihalation: " << name << " and " << nobleFoe.name << " die at each other's hands." << endl;
                strengthRatio = 0;
                for (int i = 0; i < warriorVec.size(); i++) {
                    warriorVec[i] -> editStrength(strengthRatio);
                }
                for (int i = 0; i < nobleFoe.warriorVec.size(); i++) {
                    nobleFoe.warriorVec[i] -> editStrength(strengthRatio);
                }
            }
        }
        else if (n1strength != 0 && n2strength == 0) {
            cout << "He's dead " << name << endl;
        }
        else if (n1strength == 0 && n2strength!= 0){
            cout << "He's dead " << nobleFoe.name << endl;
        }
        else {
            cout << "Oh, NO!  They're both dead!  Yuck!" << endl;
        }
    }
    void display() {
        //  displays num of warriors in vector
        cout << name << " has an army of " << warriorVec.size() << endl;
        //  goes through
        for (Warrior* warrior : warriorVec) {
            warrior -> display();
        }
    }
    string getName() {
        return name;
    }
    
    void clear() {
        for (int i = 0; i < warriorVec.size(); i++) {
            delete warriorVec[i];
        }
    }
    
private:
    string name;
    vector<Warrior*> warriorVec;
    int strengthRatio;
};


void printVec(vector<Noble*>& nobVec, vector<Warrior*> warVec) {
    cout << "Nobles:" << endl;
    if (nobVec.size() == 0) {
        cout << "NONE" << endl;
    }
    else {
        for (int i = 0; i < nobVec.size(); i++) {
            nobVec[i]->display();
        }
    }
    cout << "Unemployed Warriors:" << endl;
    if (warVec.size() == 0) {
        cout << "NONE" << endl;
    }
    else {
        for (int i = 0; i < warVec.size(); i++) {
            warVec[i] -> display();
        }
    }
}

int main() {
    fstream ifs("/Users/jwalks/Documents/* Poly Shit/* 03 Fall Sem/CS1124-f/HW-04/HW-04/nobleWarriors.txt");
    if (!ifs) {
        cerr << "File not found." << endl;
    }
    
    //  initialize variables
    string cmd, name, nob1, nob2;
    int strength;
    vector<Warrior*> warVec;
    vector<Noble*> nobVec;
    
    //  read in file
    while (ifs >> cmd) {
        if (cmd == "Noble") {
            ifs >> name;
            Noble* newN = new Noble(name);
            nobVec.push_back(newN);
        }
        else if (cmd == "Warrior") {
            ifs >> name >> strength;
            Warrior* newW = new Warrior(name, strength);
            warVec.push_back(newW);
        }
        else if (cmd == "Hire") {
            ifs >> nob1 >> name;
            for (int i = 0; i < nobVec.size(); i++) {
                if (nob1 == nobVec[i]->getName()) {
                    nobVec[i]->hire(name, warVec);
                }
            }
        }
        else if (cmd == "Fire") {
            ifs >> nob1 >> name;
            for (int i = 0; i < nobVec.size(); i++) {
                if (nob1 == nobVec[i]->getName()) {
                    nobVec[i]->fire(name, warVec);
                }
            }
        }
        else if (cmd == "Battle") {
            ifs >> nob1 >> nob2;
            for (int i = 0; i < nobVec.size(); i++) {
                if (nob1 == nobVec[i]->getName()) {
                    for (int j = 0; j < nobVec.size(); j++) {
                        if (nob2== nobVec[j]->getName()) {
                            nobVec[i]->battle(*nobVec[j]);
                        }
                    }
                    break;
                }
            }
        }
        else if (cmd == "Status") {
            cout << "\nStatus \n======" << endl;
            printVec(nobVec, warVec);
            cout << endl;
        }
        else {
            for (int i = 0; i < nobVec.size(); i++) {
                nobVec[i]->clear();
                delete nobVec[i];
            }
            for (int i = 0; i < warVec.size(); i++) {
                delete warVec[i];
            }
            nobVec.clear();
            warVec.clear();
        }
    }
    ifs.close();
}


