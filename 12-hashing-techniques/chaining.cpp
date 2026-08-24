#include <iostream>
using namespace std;

#include "HashLinkedList.hpp"


/*
        HASH TABLE:
            Full explanation has been done in iPad notes.



            Let's code chaining technique



*/

int hashfunction(int key){
    return key % 10;        // in here, we take the first digit intentionally.
}

void Insert(node *HT[], int key){
    HashLinkedL h1;
    int index = hashfunction(key);
    h1.SortedInsert(&HT[index], key);
}





int main()
{
    node *H[10];
    for(int i = 0; i<10; i++){
        H[i] = nullptr;
    }

    Insert(H, 55);
    Insert(H, 65);
    Insert(H, 75);
    Insert(H, 85);



    return 0;
}