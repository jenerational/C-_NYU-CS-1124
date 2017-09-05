//
//  Warrior.cpp
//  HW-07
//
//  Created by Jennifer Walker on 11/11/16.
//  Copyright (c) 2016 Jennifer Walker. All rights reserved.
//

#include "Warrior.h"

using namespace std;

namespace WarriorCraft {
    
    //  Default Warrior Constructor
    Warrior::Warrior (const string& warriorName, const int& warriorStrength) : name(warriorName), strength(warriorStrength) {}
    
    void Warrior::runaway() {
        cout << name << " flees in terror, abandoning his lord " << boss->getName() << endl;
        boss->fire(*this);
    }
    
    void Warrior::display() {
        cout << name << ": " << strength << endl;
    }
    //  Accessors
    string Warrior::getName() const {
        return name;
    }
    
    int Warrior::getStrength() const {
        return strength;
    }
    
    bool Warrior::getLife() const{
        return life;
    }
    
    //  Mutators
    void Warrior::setStrength(int& strengthRatio) {
        strength = strength * strengthRatio;
    }
    
    void Warrior::setLife(bool& newLife) {
        life = newLife;
    }
    
    void Warrior::setBoss(Noble* newBoss) {
        boss = newBoss;
    }
    
}