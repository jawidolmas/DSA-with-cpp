#include<iostream>
#include "array.h"

// Constructor
Array::Array(int cap){
    A = new int[cap];
    capacity = cap;
    size = 0;
}



// Display
void Array::display() const{
    for(int i=0; i<size; i++){
        std::cout << A[i] << " " ;  
    }
    std::cout << std::endl;
}




// Append 
/*This function's prupose is to append a data at the end. if we think about adding something at the end, we need to do 2 things:
    1. Check if array is empty
    2. Check if array is full
    3. If conditions met, then add the data at the end and return. 
    According to these operations, I think that append does a function of 3, so I think this function complexity will be O(1), 
    at the same time, if we want to check if array is not full, we may need a loop to trace each index, so in that case, we may jump to O(n), 
    but as we are guessing right now, we may can handle checking fullness of array in some way other than loop, can we really trace an array without a loop or at least less
    work than loop? wait, do we really need to trace all array? what if I do while(array != size -1), again we entered a loop, so I think we highly will have an O(n).
    lets see. Actually, I can see that we dont need a loop, we just can compare size and capacity to understand if array is full. */
void Array::append(int n){
    if(size == capacity){
        std::cout << "Array is full\n";
        return;
    }
    A[size] = n;
    size++;
}
/*Ohh yeah, the size is number of indices in array that has a real value, and the capacity is number of whole array. 
so in fact, if we increment size by one each time, size++ after adding and compare size with capacity that, 
if size is bigger than capacity? size>capacity, then it its true, that means the array is full. isnt it? so this gives us O(1) in append. */


// Insert:

void Array::insert(int index, int n){
    if(size == capacity){
        std::cout << "Array is full\n";
        return;
    }
    for(int i = size; i > index; --i){
        A[i] = A[i-1];
    }
    A[index] = n;
    size++;
}

// Delete
void Array::Delete(int index){
    if(size == 0 || index >= size || index < 0){
        std::cout << "Either array is empty or index is invalid\n";
        return;
    }
    for(int i = index; i < size-1; i++){
          A[i] = A[i+1];
    }
    size--;
}



// Destructor
Array::~Array(){
    delete []A;
}
