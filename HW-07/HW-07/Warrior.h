//
//  Warrior.h
//  HW-07
//
//  Created by Jennifer Walker on 11/11/16.
//  Copyright (c) 2016 Jennifer Walker. All rights reserved.
//

#ifndef __HW_07__Warrior__
#define __HW_07__Warrior__

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

namespace WarriorCraft {
    
    class Noble;
    
    class Warrior {
    public:
        //  Warrior Constructor
        Warrior (const std::string& warriorName, const int& warriorStrength);
        void display();
        void runaway();
        //  Accessors
        std::string getName() const;
        int getStrength() const;
        bool getLife() const;
        //  Mutators
        void setStrength(int& strengthRatio);
        void setLife(bool& newLife);
        void setBoss(Noble* newBoss);
        
    private:
        Noble* boss = nullptr;
        std::string name;
        int strength, strengthRatio;
        bool life = true;
    };
}

#endif /* defined(__HW_07__Warrior__) */
