//
//  main.cpp
//  HW-06
//
//  Created by Jennifer Walker on 11/2/16.
//  Copyright (c) 2016 Jennifer Walker. All rights reserved.
//  jw4043
//
//  Inheretance HW
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

//  all other class types are people that have a name and can die (Person is most Base class)
class Person {
    string name;
    bool death;
public:
    Person(const string& name) : name(name), death(false) {}
    string getName() const {
        return name;
    }
    //  Accessors
    virtual double getStrength() const = 0;
    bool getDeath() const {
        return death;
    }
    //  Mutators
    void setDeath() {
        death = true;
    }
    virtual void setStrength(double newStrength) = 0;
};

//  Protectors are people that are Warriors or Wizards
class Protector : public Person{
    double proStrength;
    string employer;
public:
    Protector(const string& name, double strength): Person(name), proStrength(strength) {}
    virtual void defend() = 0;
    //  Accessors
    double getStrength() const override {
        return proStrength;
    }
    string getEmployer() const {
        return employer;
    }
    //  Mutators
    void setStrength(double newStrength) override {
        proStrength = newStrength;
    }
    void setEmployer(const string& hiringNoble) {
        employer = hiringNoble;
    }
};

//  Nobles are people that are either Lords or Lords w/ strength
class Noble : public Person{
public:
    Noble(const string& name) : Person(name) {}
    virtual void takeDamage(double oppenentStrength) = 0;
    void battle(Noble& opponent){
        cout << this->getName() << " battles " << opponent.getName() << endl;
        if(this->getStrength() == opponent.getStrength()){
            if(opponent.getDeath()){
                cout << "Oh, NO! They're both dead! Yuck!\n";
            }
            else{
                this->setStrength(0);
                opponent.setStrength(0);
                this->setDeath();
                opponent.setDeath();
                cout << "Mutual Annihalation: " << this->getName() << " and " << opponent.getName() << "die at each other's hands.\n";
            }
        }
        else if(this->getStrength() > opponent.getStrength()){
            if(opponent.getDeath()){
                cout << "He's dead, " << this->getName() << endl;
            }
            else{
                this->takeDamage(opponent.getStrength());
                opponent.setStrength(0);
                opponent.setDeath();
                cout << this->getName() << " defeats " << opponent.getName() << endl;
            }
        }
        else {
            if(this->getDeath()){
                cout << "He's dead, "<< opponent.getName() << endl;
            }
            else{
                opponent.takeDamage(this->getStrength());
                this->setStrength(0);
                this->setDeath();
                cout << opponent.getName() << " defeats " << this->getName() << endl;
            }
        }
    }
};

class Lord : public Noble {
    vector<Protector*> army;
public:
    Lord(const string& name) : Noble(name) {}
    //  Accessor
    double getStrength() const override {
        double strength = 0;
        for(Protector* defender: army){
            strength += defender->getStrength();
        }
        return strength;
    }
    //  Mutator
    void setStrength(double newStrength) override {
        for(Protector* protPtr: army){
            protPtr->defend();
            protPtr->setStrength(newStrength);
            if(protPtr->getStrength() <= 0){
                protPtr->setDeath();
            }
        }
    }
    void takeDamage(double opponentStrength) override {
        double ratio = opponentStrength/this->getStrength();
        for(Protector* protPtr: army){
            protPtr->defend();
            protPtr->setStrength(protPtr->getStrength() - ratio*protPtr->getStrength());
            if(protPtr->getStrength() <= 0){
                protPtr->setDeath();
            }
        }
    }
    void hires(Protector& employee){
        if((employee.getEmployer() == "") && !(this->getDeath()) && (employee.getStrength() != 0)){
            army.push_back(&employee);
            employee.setEmployer(this->getName());
        }
    }
};

class PersonWithStrengthToFight : public Noble {
    double nobleStrength;
public:
    PersonWithStrengthToFight(const string& name, double strength) : Noble(name), nobleStrength(strength) {}
    //  Accessor
    double getStrength() const override {
        return nobleStrength;
    }
    //  Mutator
    void setStrength(double newStrength) override {
        nobleStrength = newStrength;
    }
    void takeDamage(double opponentStrength) override {
        nobleStrength -= opponentStrength;
    }
};

class Wizard : public Protector {
public:
    Wizard(const string& name, double strength) : Protector(name, strength) {}
    void defend() override {
        if(!(this->getDeath())){
            cout << "POOF\n";
        }
    }
};
            
class Warrior : public Protector {
public:
    Warrior(const string& name, double strength) : Protector(name, strength) {}
    void defend() override {
        cout << this->getName() << " says: Take that in the name of my lord, "
        << this->getEmployer() << endl;
    }
};

//  Archers are a type of warrior
            
class Archer : public Warrior {
public:
    Archer(const string& name, double strength) : Warrior(name,strength) {}
    //  defends by saying
    void defend() override {
        if(!(this->getDeath())){
            cout << "TWANG! ";
            Warrior::defend();
        }
    }
};

//  Swordsmen are a type of warrior
class Swordsman : public Warrior {
public:
    Swordsman(const string& name, double strength) : Warrior(name, strength) {}
    //  defends by saying CLANG then Lord's name
    void defend() override {
        if(!(this->getDeath())){
            cout << "CLANG! ";
            Warrior::defend();
        }
    }
};
            
int main() {
    Lord sam("Sam");
    Archer samantha("Samantha", 200);
    sam.hires(samantha);
    Lord joe("Joe");
    PersonWithStrengthToFight randy("Randolf the Elder", 250);
    joe.battle(randy);
    joe.battle(sam);
    Lord janet("Janet");
    Swordsman hardy("TuckTuckTheHardy", 100);
    Swordsman stout("TuckTuckTheStout", 80);
    janet.hires(hardy);
    janet.hires(stout);
    PersonWithStrengthToFight barclay("Barclay the Bold", 300);
    janet.battle(barclay);
    janet.hires(samantha);
    Archer pethora("Pethora", 50);
    Archer thora("Thorapleth", 60);
    Wizard merlin("Merlin", 150);
    janet.hires(pethora);
    janet.hires(thora);
    sam.hires(merlin);
    janet.battle(barclay);
    sam.battle(barclay);
    joe.battle(barclay);
}