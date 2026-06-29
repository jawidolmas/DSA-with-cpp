#include<iostream>

using namespace std;

/*
    This is a simple implementation of arrays.
    The array is a collection of elements of the same type, stored in contiguous memory locations.
     Array elements can be accessed using an index, which starts from 0 for the first element.
      In C++, arrays can be declared with a fixed size or dynamically allocated. This implementation demonstrates the basic usage of arrays, including declaration, initialization, and accessing elements.  
*/





int main(){

    int array[5]; // Decalring an array size of 5 elements.
    array[0] = 10; // Assigning value to the first element of the array.
    int array2[5] = {1, 2, 3, 4, 5}; // Declaring and initializing an array with values.

    // Array stored in stack of the memomry. The size of array is fixed and cannot be changed during runtime. 
    // For printing all elements of the array, we will need a loop to iterate through all elements one by one. 
    cout << "Elements of array2 are: \n";
    for (int i = 0; i<5; i++){
        cout << array2[i] << "\n";  // Printing all elements and more IMPORTANTLY, we used << "\n" instead of endl, as flushes the output buffer, it makes the program slower. its always good to use "\n" inside a loop.
    }
    
    

    return 0;
}

