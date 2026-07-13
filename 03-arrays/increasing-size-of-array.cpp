#include<iostream>
using namespace std;

// why arrays cannot be increased or decreased? because they are contigoues and we cannot tell the OS to get a memory as we want, maybe memory that we want is occupied already


// As we said we only can increase size of array in Dynamic arrays and its impossible in static arrays;
// SO, How to increase size of an array in Dynamic arrays?


int main()
{

    int *p;
    p = new int[5]; // Dynamic;
    p[0] = 2;
    p[1] = 5;
    p[2] = 7;
    p[3] = 9;
    p[4] = 11;

    for ( int i=0; i<5; i++){
        cout << p[i] << " ";
    }

    // In here we only an array of size 5, so what if I need 10? We will use method of copying;
    // For copying anything, we need a temporary place that stores our values. 
    int *temp;
    temp = new int[10];
    for(int i=0; i<10; i++){
        temp[i] = p[i];
    }
    cout << endl;
    // Now, we have copied values in p to temp, so lets now delete the array of p and then point the pointer p to temp, and delete temp as it was temporary;
    delete []p;
    p = temp;
    temp = nullptr;

    for (int i=0; i<10; i++){
        cout << &p[i] << endl;
    } // Prints a continues side by side address of each 10 index.

    // Rememmber to release the memory after use.
    delete []p;

    return 0;
}


