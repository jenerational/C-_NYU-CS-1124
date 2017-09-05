//
//  main.cpp
//  Lab-07
//
//  Created by Jennifer Walker on 11/2/16.
//  Copyright (c) 2016 Jennifer Walker. All rights reserved.
//  NYU ID: jw4043
//
//  MIL^2 Program - parts 1 & 2

#include <iostream>         //  for cout
#include <vector>           //  for inst vec
using namespace std;

class Instrument {
public:
    //  Default Constructor
    Instrument() {}
    // make sound method tests generic instrument
    virtual void makeSound ()const {
        cout << "Testing instrument sound." << endl;
    }
private:
};


class Brass : public Instrument {
public:
    // Brass constructor
    Brass (const int& mouthSize) : mouthSize(mouthSize) {}
    // make sound method
    void makeSound(int& mouthSize) {
        cout << "To make a sound... blow on a mouthpiece of size " << mouthSize << endl;
    }
private:
    int mouthSize;
};

class Trombone : public Brass {
public:
    // Trombone constructor
    Trombone(const int& mouthSize) : Brass(mouthSize) {}
    void makeSound() const {
        cout << "Blat ";
    }
private:
};

class Trumpet : public Brass {
public:
    // Trumpet constructor
    Trumpet(const int& mouthSize) : Brass(mouthSize) {}
    void makeSound() const {
        cout << "Toot ";
    }
private:
};

class String : public Instrument {
public:
    //  String constructor
    String(const int& pitch) : pitch(pitch) {}
    // make sound method
    void makeSound(int& pitch) const {
        cout << "To make a sound... bow a string with pitch " << pitch << endl;
    }
private:
    int pitch;
};

class Violin : public String {
public:
    // Violin constructor
    Violin(const int& pitch) : String(pitch) {}
    void makeSound() const {
        cout << "Screech ";
    }
private:
};

class Cello : public String {
public:
    // Cello constructor
    Cello(const int& pitch) : String(pitch) {}
    void makeSound() const {
        cout << "Squack ";
    }
private:
};

class Percussion : public Instrument {
public:
    //  Percussion constructor
    Percussion() {}
    // make sound method
    void makeSound() {
        cout << "To make a sound... hit me!" << endl;
    }
private:
};

class Drum : public Percussion {
public:
    //
    Drum() : Percussion() {}
    void makeSound() const {
        cout << "Boom ";
    }
private:
};

class Cymbal : public Percussion {
public:
    //
    Cymbal() : Percussion() {} 
    void makeSound() const {
        cout << "Crash ";
    }
private:
};

//  method copied from lab instructions
class Musician {
public:
    Musician() : instr( NULL ) {}
    void acceptInstr( Instrument & i ) { instr = &i; }
    Instrument* giveBackInstr( ) {
        Instrument* tmp(instr);
        instr = NULL;
        return tmp;
    }
    void testPlay() const {
        if( instr )
            instr->makeSound();
        else
            cerr << "have no instr\n";
    }
    //  adding necessary function for musiciians to play
    //  function points to musician's instrument
    void play() const {
        if (instr != nullptr) {
            instr -> makeSound();
        }
    }
private:
    Instrument* instr;
};

class MILL {
public:
    //  default MILL constructor
    MILL() {}
    // puts instruement into vector
    void receiveInstr(Instrument& inst) {
        //  creates bool to see if instrument can be placed into vector via for loop
        bool recieved = false;
        //  adds instrument to vector
        // TA NOTE --> dont push back, set first nullptr to the inst
        for (int i = 0; i < instVec.size(); i++) {
            if (instVec[i] == nullptr && recieved == false) {
                instVec[i] = &inst;
                recieved = true;
                //cout << "Instrument recieved." << endl;
            }
        }
        if (recieved == false) {
            instVec.push_back(&inst);
            //cout << "Instrument recieved." << endl;
        }
    }
    //  tests the instruments in the vector
    void dailyTestPlay() {
        //  cycles through the vector to test the instruments
        for (int i = 0; i < instVec.size(); i++) {
            //  checks to make sure it exists
            if (instVec[i]) {
                //  use -> bc instVec is a pointer
                instVec[i]->makeSound();
            }
        }
    }
    //  loans out instrument
    Instrument* loanOut() {
        // TA NOTE --> set first non nullptr to null ptr
        //  outside loop in case of vector size 0
        Instrument* instLoaner = nullptr;
        for (int i = 0; i < instVec.size(); i++) {
            if (nullptr != instVec[i]) {
                // reassigns instLoaner value to inst
                instLoaner = instVec[i];
                instVec[i] = nullptr;
                return instLoaner;
            }
        }
        //  in case unable to previously return
        return instLoaner;
    }
private:
    Instrument inst;
    //  vector with pointers to Instrument
    vector<Instrument*> instVec;
};


class Orch {
public:
    void addPlayer(Musician &musician) {
        musVec.push_back(&musician);
    }
    void play() const {
        for (int i = 0; i <musVec.size(); i++) {
            musVec[i] -> play();
        }
        cout << endl;
    }
    //  added to reset for part two
    void returnAll(MILL& mill) {
        for (int i = 0; i < musVec.size(); i++) {
            mill.receiveInstr(*musVec[i]->giveBackInstr());
        }
    }
private:
    vector<Musician*> musVec;
};

int main() {
    /*
    //  Lab defined test code
    cout << "Define some instruments ----------------------------------------\n";
    Drum drum;
    Cello cello(673);
    Cymbal cymbal;
    Trombone tbone( 4 );
    Trumpet trpt( 12 ) ;
    Violin violin( 567 ) ;
    
    // // use the debugger to look at the mill
    cout << "\nDefine the MILL -----------------------------------------------\n";
    MILL mill;
    
    cout << "\nPut the instruments into the MILL ------------------------------\n";
    mill.receiveInstr( trpt );
    mill.receiveInstr( violin );
    mill.receiveInstr( tbone );
    mill.receiveInstr( drum );
    mill.receiveInstr( cello );
    mill.receiveInstr( cymbal );
    
    cout << "\nDaily test -----------------------------------------------\n";
    cout << endl;
    cout << "dailyTestPlay()" << endl;
    mill.dailyTestPlay();
    cout << endl;
    
    cout << "\nDefine some Musicians-------------------------------------------\n";
    Musician j;
    Musician jj;
    Musician q;
    
    cout << "\nTESTING: q.acceptInstr( *mill.loanOut() );-----------------------\n";
    q.testPlay();
    cout << endl;
    q.acceptInstr( *mill.loanOut() );
    cout << endl;
    q.testPlay();
    cout << endl;
    cout << "dailyTestPlay()" << endl;
    mill.dailyTestPlay();
    
    cout << endl << endl;
    
    q.testPlay();
    cout << endl;
    mill.receiveInstr( *q.giveBackInstr() );
    j.acceptInstr( *mill.loanOut() );
    q.acceptInstr( *mill.loanOut() );
    cout << endl;
    q.testPlay();
    cout << endl;
    j.testPlay();
    cout << endl;
    cout << "dailyTestPlay()" << endl;
    mill.dailyTestPlay();
    
    cout << "TESTING: mill.receiveInstr( *q.giveBackInstr() ); -------------\n";
    
    // fifth
    mill.receiveInstr( *q.giveBackInstr() );
    cout << "TESTING: mill.receiveInstr( *j.giveBackInstr() ); -------------\n";
    mill.receiveInstr( *j.giveBackInstr() );
    
    
    cout << endl;
    cout << "dailyTestPlay()" << endl;
    mill.dailyTestPlay();
    
    
    //RESET
    mill.receiveInstr( *q.giveBackInstr() );
    mill.receiveInstr( *j.giveBackInstr() );
    mill.receiveInstr( *jj.giveBackInstr() ); */
    cout << endl << endl;
    //  PART 2
    
    Drum drum;
    Cello cello(673);
    Cymbal cymbal;
    Trombone tbone( 4 );
    Trumpet trpt( 12 ) ;
    Violin violin( 567 ) ;
    
    MILL mill;
    mill.receiveInstr( trpt );
    mill.receiveInstr( violin );
    mill.receiveInstr( tbone );
    mill.receiveInstr( drum );
    mill.receiveInstr( cello );
    mill.receiveInstr( cymbal );
    
    Musician bob;
    Musician sue;
    Musician mary;
    Musician ralph;
    Musician jody;
    Musician morgan;
    
    Orch orch;
    
    // THE SCENARIO
    
    //Bob joins the orchestra without an instrument.
    orch.addPlayer(bob);
    
    //The orchestra performs
    cout << "orch performs\n";
    orch.play();
    
    //Sue gets an instrument from the MIL2 and joins the orchestra.
    sue.acceptInstr( *mill.loanOut() );
    orch.addPlayer(sue);
    
    //Ralph gets an instrument from the MIL2.
    ralph.acceptInstr( *mill.loanOut() );
    
    //Mary gets an instrument from the MIL2 and joins the orchestra.
    mary.acceptInstr( *mill.loanOut() );
    orch.addPlayer(mary);
    
    //Ralph returns his instrument to the MIL2.
    mill.receiveInstr( *ralph.giveBackInstr() );
    
    //Jody gets an instrument from the MIL2 and joins the orchestra.
    jody.acceptInstr( *mill.loanOut() );
    orch.addPlayer(jody);
    
    // morgan gets an instrument from the MIL2
    morgan.acceptInstr( *mill.loanOut() );
    
    //The orchestra performs.
    cout << "orch performs\n";
    orch.play();
    
    //Ralph joins the orchestra.
    orch.addPlayer(ralph);
    
    //The orchestra performs.
    cout << "orch performs\n";
    orch.play();
    
    // bob gets an instrument from the MIL2
    bob.acceptInstr( *mill.loanOut() );
    
    // ralph gets an instrument from the MIL2
    ralph.acceptInstr( *mill.loanOut() );
    
    //The orchestra performs.
    cout << "orch performs\n";
    orch.play();
    
    //Morgan joins the orchestra.
    orch.addPlayer(morgan);
    
    //The orchestra performs.
    cout << "orch performs\n";
    orch.play();
    }