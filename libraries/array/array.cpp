#include<iostream>
#include "array.h"

// Constructor
Array::Array(int cap){
    A = new int[cap];
    capacity = cap;
    size = 0;
}

// Swap

void Array::swap(int &a, int &b){
    int temp = 0;
    temp = a; 
    a = b;
    b = temp;
}

// Display
void Array::display() const{
    for(int i=0; i<size; i++){
        std::cout << A[i] << " " ;  
    }
    std::cout << std::endl;
}

// Append

void Array::append(int n){
    if(size == capacity){
        std::cout << "Array is full\n";
        return;
    }
    A[size] = n;
    size++;
}

// Insert

void Array::insert(int index, int n){
    if(isFull() || index > size || index < 0){
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
    if(isEmpty() || index >= size || index < 0){
        std::cout << "Either array is empty or index is invalid\n";
        return;
    }
    for(int i = index; i < size-1; i++){
          A[i] = A[i+1];
    }
    size--;
}


// Length

int Array::length() const{
    return size;
}

// IsEmpty

bool Array::isEmpty() const{
    if(size == 0){
        return true;
    }
    else return false;
}


// isFull

bool Array::isFull() const{
    if (size == capacity){
        return true;
    }
    else return false;
}

// Max

int Array::Max() const{
    
    if(isEmpty()){
        std::cout << "Array is empty\n";
        return 0;
    } 
    int maximum = A[0];
    for(int i = 1; i < size; i++){
        if(A[i] > maximum){
            maximum = A[i];
        }
    }
    return maximum;
}

// Min

int Array::Min() const{
    if(isEmpty()){
        std::cout << "Array is empty\n";
        return 0;
    }
    int minimum = A[0];
    for(int i = 1; i < size; ++i){
        if(A[i] < minimum){
            minimum = A[i];
        }
    }
    return minimum;
}

// Sum

int Array::sum() const{
    if(isEmpty()){
        std::cout << "Array is empty\n";
        return 0;
    }
    int sum = 0;
    for(int i = 0; i < size; i++){
        sum += A[i];
    }
    return sum;
}


// Average

double Array::average() const{
    if(isEmpty()){
        std::cout << "Array is empty\n";
        return 0;
    }
    double avg = 0.0;
    avg = (double)sum()/length();
    return avg;
}


// Linear Search

void Array::linearsearch(int key) const{
    
    if(isEmpty()){
        std::cout << "Array is empty\n";
        return;
    }
    bool found = false;
    for(int i = 0; i < size; i++){
        if (A[i] == key){
            std::cout << key <<" Found in index: " << i << "  \n";
            found = true;
        }
    }   
    if(!found){
    std::cout << "Data not found!\n";
}
}


// Get

int Array::get(int index) const{
    if(index >= 0 && index < size){
        std::cout << "The value in given index is: " << A[index] <<"\n";
        return A[index];
    }
    std::cout << "No Data founded in given index\n";
    return -1;      // No value in that index.
}


// Set

void Array::set(int index, int value){
    if(index >= 0 && index < size){
            A[index] = value;
    }
    else {
        std::cout << "Invalid index\n";
    }
}


// Transposition Linear Search

void Array::transpositionLinearSe(int key){
    if(isEmpty()){
        std::cout << "Array is empty\n";
        return;
    }
    bool found = false;
    for(int i = 0; i<size; i++){
        if(key == A[i]){
            found = true;
            std::cout << "The value " << key << " Found in index " << i << "\n";
            if(i > 0){
            swap(A[i], A[i-1]);
        }
    }
    }
    if(!found){
        std::cout << "Data not found\n";
        return;
    }
    
}


// Move to Front/Head Linear Search 

void Array::movetoFrontLinearSe(int key){
     if(isEmpty()){
        std::cout << "Array is empty\n";
        return;
    }
    bool found = false;
    for(int i = 0; i<size; i++){
        if(key == A[i]){
            found = true;
            std::cout << "The value " << key << " Found in index " << i << "\n";
            if(i > 0){
            swap(A[i], A[0]);
        }
    }
    }
    if(!found){
        std::cout << "Data not found\n";
        return;
    }
    
}


// Binary search using loop( Better than recursive version)
// Array must be sorted

int Array::BinarySearchIterative(int key){

    if(isEmpty()){
        std::cout << "Array is empty\n";
        return -1;
    }
        int l, h, mid;
        l = 0;
        h = size - 1;
        mid = 0;

        while(l <= h){
            mid = l + (h-l)/2;          // Handles integer overflow, better instead of (l+h)/2
            if(A[mid] == key){
                std::cout << "Data found in index: " << mid << "\n";
                return mid;
            }
            else if(A[mid] > key){
                h = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return -1;
}

// Binary search Recursive
// Array must be sorted

int Array::BinarySearchRecursive(int l, int h, int key){
    if(isEmpty()){
        std::cout << "Array is empty\n";
        return -1;
    }
    if(l > h){
        return -1;
    }

    int mid = l + (h-l)/2;

    if(A[mid] == key){
        std::cout << "Data found in index: " << mid << "\n";
        return mid;
    }
    else if(A[mid] > key){
        return BinarySearchRecursive(l, mid - 1, key);
    }
    else{
        return BinarySearchRecursive(mid+1, h, key);
    }

}

// Merge sorted array

Array Array::Merge(Array &arr1, Array &arr2){
    Array arr3(arr1.size + arr2.size);
    int i, j, k = 0;
    for(i = 0, j = 0; i<arr1.size && j<arr2.size;){
            if(arr1.A[i] < arr2.A[j]){
                arr3.A[k++] = arr1.A[i++];
                arr3.size++;
            }
            else{
                arr3.A[k++] = arr2.A[j++];
                arr3.size++;
            }
    }
    for(; i<arr1.size; i++){
        arr3.A[k++] = arr1.A[i];
        arr3.size++;
    }
    for(; j<arr2.size; j++){
        arr3.A[k++] = arr2.A[j];
        arr3.size++;
    }
    return arr3;
}


// Destructor
Array::~Array(){
    delete []A;
}
