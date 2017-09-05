//
//  main.cpp
//  Lab-03
//
//  Created by Jennifer Walker on 9/23/16.
//  Copyright (c) 2016 Jennifer Walker. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Sandwich {
    int const bread=2;
    int cheese, tomato;
    double mayo, mustard;
public:
    //  Default Constructor:
    Sandwich() {cheese = 1; tomato = 2; mayo = 1.0; mustard = 0.5;}
    Sandwich(const int newcheese, const int newtomato, const double newmayo, const double newmustard) {cheese = newcheese, tomato = newtomato, mayo = newmayo, mustard = newmustard;};
    //  Display function:
    void displayS() {
        cout << "Sandwich Contents: " << endl;
        cout << "\t" << tomato << " slice(s) of Tomato" << endl;
        cout << "\t" << cheese << " slice(s) of Cheese" << endl;
        cout << "\t" << mayo << " ounce(s) of Mayo" << endl;
        cout << "\t" << mustard << " ounce(s) of Mustard" << endl;
    }
    //  Get/Accessor functions:
    int getCheese() const{
        return cheese;
    }
    int getTomato() const{
        return tomato;
    }
    double getMayo() const{
        return mayo;
    }
    double getMustard() const{
        return mustard;
    }
    //  Mutator functions
    void setCheese(int newCheese) {
        cheese = newCheese;
    }
    void setTomato(int newTomato) {
        tomato = newTomato;
    }
    void setMayo(double newMayo) {
        mayo = newMayo;
    }
    void setMustard (double newMustard) {
        mustard = newMustard;
    }
    
};

class SandwichTruck {
    vector<Sandwich> sOrder;
public:
    void storeS(Sandwich& s) {
        sOrder.push_back(s);
    }
    void displayS() {
        for (int i = 0; i < sOrder.size(); i++) {
            sOrder[i].displayS();
        }
    }
};



int main() {
    //  Initializes Sandwich Truck
    SandwichTruck st;
    //  Customer 1
    Sandwich s;
    st.storeS(s);
    //  Cusomter 2
    Sandwich s2;
    s2.setMustard(0);
    st.storeS(s2);
    //  Customer 3
    Sandwich s3;
    s3.setCheese(3);
    st.storeS(s3);
    //  Customer 4
    Sandwich s4;
    st.storeS(s4);
    //  Display Delivery Truck Contents
    st.displayS();
    //  Check Mustard
    cout << "Customer 2's Mustard amount is " << s2.getMustard() << " oz."<< endl;
    

}
