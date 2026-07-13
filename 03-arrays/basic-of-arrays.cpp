#include<iostream>
using namespace std;

// Declaring and initializing arrays;
// Arrays are vectors, not scalar. 
// int x = 10 -> scaler
// int x[5] -> vector

int main()
{

    int A[5]; // Declaring array; I have an array of size 5 with grabage values in all indices.
    int A1[5] = {1, 2, 3, 4, 5}; // This is both declaring and initializing of array. in memeory I have an array with size 5 filled with 1 to 5;
    int A2[] = {1, 2, 3, 4}; // in here, we did not declared the size of array, so compiler sees what we initiazlied it with? so if I have from 1 to 4, so the size of array is 4;
    // rememmber, I cannot have an array that is empty in size and not initialized. compiler will throw an error of incomplete. 
    int A3[5] = {1, 2}; // when we initialize an array in runtime, it treis to initialize all of the indices. so what if we only initialized 2 indices. The remaining indices will be fill with ZERO;
    int A4[5] = {0}; // we only initialized index 0 with zero. so the remaining indices will also be filled with 0;


    // Accessing arrays;

    int Arr[5] = {1, 2, 3, 4, 5};
    cout << Arr[0] << endl; // prints 1;
    cout << &Arr[0] << endl; // prints address of first elemnt;
    cout << 2[Arr] << endl;     // prints second element
    
    // how can we access all elements? USing loop
    for (int x:Arr){
        cout << x << endl;
    }

    // 2nd method:
    for (int i=0; i<5; i++){
        cout << Arr[i]  << endl;// using direct index
        cout << *(Arr + i) << endl; // using pointers;
        cout << &A[i] << endl;  // printing addresses of all indices;
    }


    return 0;
}