//
//  Noble.cpp
//  HW 07
//
//  Created by Jennifer Walker on 11/11/16.
//  Copyright (c) 2016 Jennifer Walker. All rights reserved.
//

#include "Noble.h"
#include "Warrior.h"
using namespace std;
namespace WarriorCraft{
    
    Noble::Noble (const string& nobleName) : name(nobleName) {}
    
    void Noble::hire(const Warrior& fighter){
        //  creates a pointer to the hired warrior
        Warrior* newWarrior = new Warrior(fighter);
        //  has new warrior point to noble
        newWarrior->setBoss(this);
        //  pushes new warrior back into the vector
        warriorVec.push_back(newWarrior);
    }
    
    void Noble::display() const {
        //  displays num of warriors in vector
        cout << name << " has an army of " << warriorVec.size() << endl;
        //  goes through
        for (Warrior* warrior : warriorVec) {
            cout << "\t";
            warrior -> display();
        }
    }
    
    void Noble::fire (Warrior& fighter) {
        bool removed = false;
        string fName = fighter.getName();
        while (removed == false) {
            for (int i = 0; i < warriorVec.size(); i++) {
                string wName = warriorVec[i] -> getName();
                if (fName == wName) {
                    // --> erase from vector // warriorVec[i];
                    warriorVec.erase(warriorVec.begin()+i);
                    cout << fName << ", you're fired! -- " << name << endl;
                    //  stops method looping through the vector
                    removed = true;
                }
            }
        }
    }
    
    void Noble::battle (Noble& nobleFoe) {
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
                    warriorVec[i] -> setStrength(strengthRatio);
                }
                strengthRatio = 0;
                for (int i = 0; i < nobleFoe.warriorVec.size(); i++) {
                    nobleFoe.warriorVec[i] -> setStrength(strengthRatio);
                }
            }
            else if (n1strength < n2strength) {
                cout << nobleFoe.name << " defeats " << name << endl;
                strengthRatio = n1strength / n2strength;
                for (int i = 0; i < nobleFoe.warriorVec.size(); i++) {
                    nobleFoe.warriorVec[i] -> setStrength(strengthRatio);
                }
                strengthRatio = 0;
                for (int i = 0; i < warriorVec.size(); i++) {
                    warriorVec[i] -> setStrength(strengthRatio);
                }
            }
            else {
                cout << "Mutual Annihalation: " << name << " and " << nobleFoe.name << " die at each other's hands." << endl;
                strengthRatio = 0;
                for (int i = 0; i < warriorVec.size(); i++) {
                    warriorVec[i] -> setStrength(strengthRatio);
                }
                for (int i = 0; i < nobleFoe.warriorVec.size(); i++) {
                    nobleFoe.warriorVec[i] -> setStrength(strengthRatio);
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
    
}


