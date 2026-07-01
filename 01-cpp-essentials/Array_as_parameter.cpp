#include<iostream>
using namespace std;


// Array as parameter
// Arrays can only be passed by address. Reason: Arrays are already pointers.

void MultipleArrayElementsBy2(int *A, int size){

    for (int i =0; i<size; i++){
        A[i] = 2 * A[i];
        cout << A[i];
    }
}


// creating an array & allocating a memeory inside heap using function
// This function gets an array with its size, creates the array, fills it with i + 1, and main function will print the array at the end.
int *function(int size){

    int *ptr;
    ptr = new int[size];
    for(int i=0; i<size; i++){
        ptr[i] = i+1;
    }
    return ptr;
}

int main(){

    int Arr[] = {1, 2, 3, 4, 5};
    int size = 5;
    MultipleArrayElementsBy2(Arr, size);
    int *p, size2=5;
    p = function(size2);
    for(int i =0; i<size2; i++){
        cout << p[i];
    }
 
 
 
    return 0;
}