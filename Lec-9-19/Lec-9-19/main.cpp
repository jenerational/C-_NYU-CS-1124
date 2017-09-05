//
//  main.cpp
//  Lec-9-19
//
//  Created by Jennifer Walker on 9/19/16.
//  ALSO USED FOR LEC 9/21/16
//  Copyright (c) 2016 Jennifer Walker. All rights reserved.
//
//  in 2134: careful balance between CPU speed, Memory usage, and actual coding time
//

#include <iostream>         //  cout, cin, cerr
#include <vector>           //  vector


using namespace std;

/* Encapsulation:
 We want to have the data types and the functions together
 We also want to have data hiding
 */

//  Dictionaries in Python most closely correlates w maps in C++

/* Problems with Structs:
 - don't contain any functions
 - everyone has access to everything in structs (no data hiding)
 */

//  Class of a deck of playing cards

class Card {
    //  because these are not under public, no one will have access to this data except for the functions within the class
    char suit;
    int value;      //  J=11, Q=12, K=13, A=1
public:
    //  Default Constructor: Sets default values if the card is initialized without any parameters
    //  Constructors have no returns
    Card() {value = 1; suit = 'S';}
    //  Can have other constructors as well.
    Card (char newSuit, int newValue);      //     -> this one outside the class
    
    //  Accessors: / "Getters" :
    //  allows outside functions to access the stored data points; only job is to return the value
    int getValue() const {return value;}
    char getSuit() const {return suit;}
    
    //  Mutators: / "Setters":
    //  Instead of only returning a value, it changes/uses it
    bool setValue(int& newval);
    /*  Can also have full functions inside the class
     bool setValue(int newValue) {   //  return is FAIL flag
        if (newValue <= 13 && newValue > 0) {
            value = newValue;
            return false;
        }
        return true;
    }*/
};

//                              Card Class Functions
//  Constructors can be made outside the Class
/*Card::Card() {
    value = 1; suit = 'S';
}*/
Card::Card(char newSuit, int newValue) {
    if (newSuit != 'C' && newSuit != 'S' && newSuit != 'D' && newSuit != 'H') {
        suit = 'S';
    }
    else {
        suit = newSuit;
    }
    if (newValue > 13 || newValue <= 0) {
        value = 1;
    }
    else {
        value = newValue;
    }
}

bool Card::setValue(int& newValue) {   //  return is FAIL flag
    if (newValue <= 13 && newValue > 0) {
        value = newValue;
        return false;
    }
    return true;
 }

//                                   Deck Class:
class Deck {
    //  For the Deck of Cards
    int originalNumber;
    vector<Card> cards;
    vector<bool> dealt;
public:
    //  member initialization list -> : followed by list of instructions
    Deck(int numOfCards = 52) : originalNumber(numOfCards) {    //  default and one argument constructor
        shuffle();
    }
    void shuffle();
    Card deal();
    
};

//                                  Deck Class Functions:
void Deck::shuffle() {
    cards.clear();                          //  first: nuke the deck, start from scratch
    string suits = "CSDH";
//    for (int i = 0; i < suits.size(); i++) {
//        for (int j = 1; j <=13; j++) {    //  cant use bc model only works for 52 cards
    int cardNum = 0;
    while(cardNum<originalNumber) {
        Card temp(suits[(cardNum%52)/13], (cardNum%13)+1);
        cards.push_back(temp);
        cardNum++;
    }
}

Card Deck::deal() {
    int num = rand() % cards.size();
    Card retval = cards[num];
    cards[num] = cards[cards.size()-1];
    cards[cards.size() - 1] = retval;       //  not really necessary
    cards.pop_back();
    return retval;
}


//                                  Other functions:
void func(const Card& c) {
    cout << c.getSuit();
}


int main() {
    Card c;
    //cout << c.value << endl;              -> main does not have access to data point
    cout << c.getValue() << " " << c.getSuit() << endl;
    
    Card newc('H', 10);
    cout << newc.getValue() << " " << newc.getSuit() << endl;
    
    Deck d;
    //while (d.remaining() != 0) {
        
    //}
    
    //                              x++ vs ++x
    int x=5;
    int y;
    y = x++;                        //  y stores original value of x, x gets incremented
    cout << x;
    cout << y;
    
    cout << endl;
    
    int a = 5;
    int b;
    b = ++a;                        //  x gets incremented first, y stores changed value
    cout << a;
    cout << b;
    
}









