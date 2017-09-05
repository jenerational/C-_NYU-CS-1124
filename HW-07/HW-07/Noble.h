//
//  Noble.h
//  HW-07
//
//  Created by Jennifer Walker on 11/11/16.
//  Copyright (c) 2016 Jennifer Walker. All rights reserved.
//

#ifndef __HW_07__Noble__
#define __HW_07__Noble__

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

namespace WarriorCraft {
    
    class Warrior;
    
    class Noble {
    public:
        //  Noble Constructor
        Noble (const std::string& nobleName);
        void hire(const Warrior& fighter);
        void display() const;
        void fire (Warrior& fighter);
        void battle (Noble& nobleFoe);
        //  Accessors
        std::string getName();
    private:
        std::string name;
        std::vector<Warrior*> warriorVec;
        int strengthRatio;
    };
}


#endif /* defined(__HW_07__Noble__) */
