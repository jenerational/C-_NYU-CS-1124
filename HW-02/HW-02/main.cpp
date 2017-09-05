//
//  main.cpp
//  HW-02
//
//  Created by Jennifer Walker on 9/29/16.
//  Copyright (c) 2016 Jennifer Walker. All rights reserved.
//

#include <iostream>         //  cout, cin, cerr
#include <fstream>          //  ifstream
#include <vector>           //  vector<Warrior>

using namespace std;


class Weapon {
    int strength;
    string name;
public:
    //  Constructor
    Weapon(const string& name = "", const int& strength = 0) : name(name), strength(strength) {}
    //  Mutators
    void setName(string newName) {
        name = newName;
    }
    void setStrength(int newStrength) {
        strength = newStrength;
    }
    //  Accessors
    string getName() {
        return name;
    }
    int getStrength() {
        return strength;
    }
};

class Warrior {
    string name;
    Weapon weapon;
    bool life = true;
public:
    //  Constructor
    Warrior (const string& name = "", const string& weaponName = "", const int& strength = 0) : name(name), weapon(Weapon(weaponName, strength)) {}
    //  Mutators
    void setName(string newName) {
        
        name = newName;
    }
    void setWeaponName(string newWeaponName) {
        weapon.setName(newWeaponName);
    }
    void setStrength(int newStrength) {
        weapon.setStrength(newStrength);
    }
    void setLife(bool newLife) {
        life = newLife;
    }
    //  Accessors
    string getName() {
        return name;
    }
    string getWeaponName() {
        return weapon.getName();
    }
    int getStrength() {
        return weapon.getStrength();
    }
    bool getLife() {
        return life;
    }
};

void fightWarrior(string& war1, string& war2, vector<Warrior>& warVec) {
    //  initializes variables to save vector placement of warriors & prints out warrior names
    int i1 = 0, i2 = 0;
    cout << war1 << " battles " << war2 << endl;
    //  searches through vector for warriors and respective attributes
    for (int i = 0; i < warVec.size(); i++) {
        if (warVec[i].getName() == war1) i1 = i;
        else if (warVec[i].getName() == war2) i2 = i;
    }
    //  check to see if either warrior is dead
    if (warVec[i1].getLife() == false && warVec[i2].getLife() == false) {
        cout << "Oh, NO! They're both dead! Yuck!" << endl;
    }
    else if (warVec[i1].getLife() == false) {
        cout << "He's dead, " << warVec[i2].getName() << endl;
    }
    else if (warVec[i2].getLife() == false) {
        cout << "He's dead, " << warVec[i1].getName() << endl;
    }
    //  if both warriors are alive
    if (warVec[i1].getLife() == true && warVec[i2].getLife() == true) {
        //  if war1 is stronger than war2
        if (warVec[i1].getStrength() > warVec[i2].getStrength()) {
            int newStrength = warVec[i1].getStrength() - warVec[i2].getStrength();
            warVec[i1].setStrength(newStrength);
            warVec[i2].setStrength(0);
            warVec[i2].setLife(false);
            cout << war1 << " defeats " << war2 << endl;
        }
        //  if war2 is stronger than war1
        else if (warVec[i1].getStrength() < warVec[i2].getStrength()) {
            int newStrength = warVec[i2].getStrength() - warVec[i1].getStrength();
            warVec[i2].setStrength(newStrength);
            warVec[i1].setStrength(0);
            warVec[i1].setLife(false);
            cout << war2 << " defeats " << war1 << endl;
        }
        //  if war2 strength == war1 strength
        else {
            warVec[i1].setStrength(0);
            warVec[i2].setStrength(0);
            warVec[i1].setLife(false);
            warVec[i2].setLife(false);
            cout << "Mutual Annihilation: " << war1 << " and " << war2 << " die at each other's hands" << endl;
        }
    }
}

void printVec(vector<Warrior>& warVec) {
    //  prints total number of warriors from file
    cout << "There are: " << warVec.size() << " warriors"  << endl;
    //  prints warrior status
    for (Warrior& w : warVec) {
        cout << "Warrior: " << w.getName() << ", weapon: " << w.getWeaponName() << ", " << w.getStrength() << endl;
    }
}

int main() {
    //  load in file
    ifstream wFile("/Users/jwalks/Documents/* Poly Shit/* 03 Fall Sem/CS1124-f/HW-02/HW-02/warriors.txt");
    if (!wFile) {
        cerr << "File cannot be found." << endl;
        exit(1);
    }
    //  initialize variables
    string cmd, name, weapon, war1, war2;
    int strength;
    vector<Warrior> warVec;
    //  read in file
    while (wFile >> cmd) {
        if (cmd == "Warrior") {
            wFile >> name >> weapon >> strength;
            Warrior newW(name, weapon, strength);
            warVec.push_back(newW);
        }
        else if (cmd == "Battle") {
            wFile >> war1 >> war2;
            fightWarrior(war1, war2, warVec);
        }
        else {
            printVec(warVec);
        }
    }
    wFile.close();
}
