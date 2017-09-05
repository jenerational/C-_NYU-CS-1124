//
//  main.cpp
//  Lab-11
//
//  Created by Jennifer Walker on 11/18/16.
//  Copyright (c) 2016 Jennifer Walker. All rights reserved.
//

#include <iostream>
#include <cstdlib> // To allow NULL if no other includes

using namespace std;

struct Node {
    Node(int data = 0, Node* link = NULL) : data(data), link(link) {}
    int data;
    Node* link;
};

void listInsertHead(int entry, Node*& headPtr) {
    headPtr = new Node(entry, headPtr);
    
}

void spliceInto(int numAfter, Node* listOne, Node* listTwo) {
    while (listOne != nullptr && listOne-> data != numAfter) {
        listOne = listOne-> link;
    }
    Node* p = listOne->link;
    listOne->link = listTwo;
    while (listOne->link) {
        listOne=listOne->link;
    }
    listOne -> link = p;
    
}

void listPrint(Node* list) {
    Node* p = list;
    while (p != nullptr) {
        cout << p-> data << " ";
        p = p-> link;
    }
    cout << endl;
}

void nodeSearch(Node* searching, Node* searchList) {
    bool trueList = false;
    Node* tempSearch = searching;
    while (tempSearch != nullptr && searchList!=nullptr) {
        if (tempSearch->data != searchList-> data) {
            searchList = searchList->link;
            trueList = false;
            tempSearch = searching;
        }
        else {
            while (tempSearch != nullptr && tempSearch->data == searchList->data) {
                tempSearch = tempSearch->link;
                searchList = searchList->link;
                trueList = true;
            }
        }
    }
    if (trueList == true) {
        while (searching != nullptr) {
            cout << searching-> data;
            searching = searching->link;
        }
        cout << endl;
    }
    else {
        cout << "nullptr" << endl;
    }
}

int main() {
    Node* listOne = nullptr;
    listInsertHead(1, listOne);
    listInsertHead(9, listOne);
    listInsertHead(7, listOne);
    listInsertHead(5, listOne);
    
    Node* listTwo = nullptr;
    listInsertHead(2, listTwo);
    listInsertHead(3, listTwo);
    listInsertHead(6, listTwo);
    
    //                                 Part 1
    cout << "Part 1: " << endl;
    
    //Print Lists 1
    cout << "List One: ";
    listPrint(listOne);
    cout << "List Two: ";
    listPrint(listTwo);
    
    cout << "Splicing List Two into List One after 7." << endl;
    spliceInto(7, listOne, listTwo);
    
    //Print Lists 2
    cout << "List One: ";
    listPrint(listOne);
    cout << "List Two: ";
    listPrint(listTwo);
    
    
    //                                  Part 2
    cout << "\nPart 2: " << endl;
    
    cout << "Target List: ";
    listPrint(listOne);
    
    Node n1; n1.data = 7;
    Node n2; n2.data = 6; n1.link = &n2;
    cout << "Looking for: 76" << endl;
    nodeSearch(&n1, listOne);
    
    Node n3; n3.data = 6;
    Node n4; n4.data = 7; n3.link = &n4;
    cout << "Looking for: 67" << endl;
    nodeSearch(&n3, listOne);
    
    Node n5; n5.data = 5;
    Node n6; n6.data = 6; n5.link = &n6
    ;
    cout << "Looking for: 56" << endl;
    nodeSearch(&n5, listOne);
    
    
}



//                                      OUTPUT.TXT
/* Part One:
 
 L1: 5 7 9 1
 L2: 6 3 2
 Target: 7 9 1
 Splicing L2 at target in L1
 L1: 5 7 6 3 2 9 1
 L2: 6 3 2 9 1
 =====================
 
 Part two:
 
 Target: 1 2 3 2 3 2 4 5 6
 
 Attempt match: 1
 1 2 3 2 3 2 4 5 6
 
 Attempt match: 3 9
 Failed to match
 
 Attempt match: 2 3
 2 3 2 3 2 4 5 6
 
 Attempt match: 2 4 5 6
 2 4 5 6
 
 Attempt match: 2 3 2 4
 2 3 2 4 5 6
 
 Attempt match: 5 6 7
 Failed to match
 
 Press any key to continue */

