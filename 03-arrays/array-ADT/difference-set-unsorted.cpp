#include<iostream>
using namespace std;

// SETS: 

// Difference of two arrays. 

// A set mathematically can not have internal duplicates. so inputs should suit this rule. 


class ArrayADT{
    private:
        int *A; // pointer to point to array's first add in heap
        int capacity; // number of indices inside array;
        int size;     // number of real value elements in array;
    public:
        ArrayADT(int cap);
        ~ArrayADT();     
        void append(int value); 
        ArrayADT differenceSorted(ArrayADT &arr1, ArrayADT &arr2);
        ArrayADT differenceUnsorted(ArrayADT &arr1, ArrayADT &arr2);
        void display() const;
};


ArrayADT::ArrayADT(int cap){
    A = new int[cap];
    capacity = cap;
    size = 0;
}


ArrayADT::~ArrayADT(){
    delete []A;
}


void ArrayADT::display() const{
    // lets check if array is empty;
    if (size == 0){ // means no value in it;
        std::cout << "Array is empty\n";
        return;
    }
    for(int i = 0; i<size; ++i){
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;
}

// Append:
void ArrayADT::append(int n){
    if(size == capacity){   
        std::cout << "Array is full\n";
        return;
    }
    A[size] = n;
    size++;         
}


// Difference Unsorted:

ArrayADT ArrayADT::differenceUnsorted(ArrayADT &arr1, ArrayADT &arr2){
    
    ArrayADT arr3(arr1.size + arr2.size);           // Distination Array;
    int i, j, k;
    i = j = k = 0;

    bool found = false;    
    for(; i < arr1.size; ++i){
        for(j = 0; j<arr2.size; ++j){
            if(arr1.A[i] == arr2.A[j]){
                found = true;  
            }
        }
        if(!found){
        arr3.A[k++] = arr1.A[i];
        arr3.size++;
        }
        found = false;
    }
    return arr3;
}







int main()
{
    int Values[] = {1, 8, 12, 31, 85};
    int Values2[] = {10, 5, 9, 29, 90};
    ArrayADT arr(5);
    for(int i = 0; i<5; i++){
        arr.append(Values[i]);
    }    
    ArrayADT arr2(5);
    for(int i = 0; i<5; i++){
        arr2.append(Values2[i]);
    }   
    
    ArrayADT arr3 = arr.differenceUnsorted(arr, arr2);        
    arr3.display();
    return 0;           
}




/*
    ANALYSIS:

      UNSORTED ARRAY:
        -Same quadratic shape as intersectionUnsorted and unionOfSet: for each of the n elements in arr1, we scan all m
        elements of arr2 to check if a match exists anywhere. Total work is n*m, so if m=n, theta(n^2).
        -Only difference from intersection is the insert condition is flipped: intersection inserts when found, 
        difference inserts when NOT found. Same nested-scan cost either way.


*/