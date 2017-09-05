//
//  hw03.cpp
//  HW-03
//
//  Created by Jennifer Walker on 10/10/16.
//  Copyright (c) 2016 Jennifer Walker. All rights reserved.
//
//  NYU ID: jw4043
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
        cout << name << ": " << strength << endl;
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

class Noble : public Warrior {
public:
    //  Default Noble Constructor
    Noble (const string& nobleName = "") : name(nobleName) {}
    
    void hire(const Warrior& fighter){
        //  creates a pointer to the hired warrior
        Warrior* newWarrior = new Warrior(fighter);
        //  pushes new warrior back into the vector
        warriorVec.push_back(newWarrior);
    }
    
    void display() {
        //  displays num of warriors in vector
        cout << name << " has an army of " << warriorVec.size() << endl;
        //  goes through
        for (Warrior* warrior : warriorVec) {
            warrior -> display();
        }
    }
    
    void fire (Warrior& fighter) {
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
    
private:
    string name;
    Warrior fighter;
    vector<Warrior*> warriorVec;
    int strengthRatio;
};


int main() {
    //  creates new nobles w noble name
    Noble art("King Arthur");
    Noble lance("Lancelot du Lac");
    Noble jim("Jim");
    Noble linus("Linus Torvalds");
    Noble billie("Bill Gates");
    
    //  creates new warriors with name and strength
    Warrior cheetah("Tarzan", 10);
    Warrior wizard("Merlin", 15);
    Warrior theGovernator("Conan", 12);
    Warrior nimoy("Spock", 15);
    Warrior lawless("Xena", 20);
    Warrior mrGreen("Hulk", 8);
    Warrior dylan("Hercules", 3);
    
    
    //  uses a Noble Class method to hire warrior
    jim.hire(nimoy);
    lance.hire(theGovernator);
    art.hire(wizard);
    lance.hire(dylan);
    linus.hire(lawless);
    billie.hire(mrGreen);
    art.hire(cheetah);
    
    //  uses a Noble class method to display a noble
    jim.display();
    lance.display();
    art.display();
    linus.display();
    billie.display();
    
    //  uses a Noble class method to fire a warrior
    art.fire(cheetah);
    //  re-displays noble who fired warrior
    art.display();
    
    //  tells nobles to tell their warriors to battle
    art.battle(lance);
    jim.battle(lance);
    linus.battle(billie);
    billie.battle(lance);
}


