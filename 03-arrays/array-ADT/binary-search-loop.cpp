#include<iostream>
using namespace std;

// Search
// We have 2 foundational searches, 1. Linear search; 2. Binary search; of course we have other algorithms too.
// BINARY SEARCH



class ArrayADT{
    private:
        int *A; // pointer to point to array's first add in heap
        int capacity; // number of indices inside array;
        int size;     // number of real value elements in array;
    public:
        ArrayADT(int cap);
        ~ArrayADT();     
        void append(int value); 
        int binarySearch(int low, int high, int key);
};


ArrayADT::ArrayADT(int cap){
    A = new int[cap];
    capacity = cap;
    size = 0;
}


ArrayADT::~ArrayADT(){
    delete []A;
}


// Append:
void ArrayADT::append(int n){
    if(size == capacity){   // Check if array is already full;
        std::cout << "Array is full\n";
        return;
    }
    A[size] = n;
    size++;         // increment size coz the latest index is occupied by new value n;
}

/*
    Binary search is a type of searching algorithms, which is faster than linear search, and it holds one condition, which is:
    The list given should be sorted. so if we have 1 2 4 3 5 8 6 7, binary search will not suit this kind of lists;
    
    How binary search works? 
    Before that, lets understand why binary? binray search always splits a list into 2, so that is the reason it is binary(2);
    Binray search holds 3 variables, the lowest index, the highest index and the middle index.
    It splits by middle and check for a condition of, if key is right hand side of middle or left hand side; 
    Now, what if a given key does not exist in list? then stop? but how? Binary search can never happen when lowest side is bigger than highest side;
    lets see how to code; 

    We CAN code binary search using loop as well as recursion;
*/

// Binary Search - using loop;

int ArrayADT::binarySearch(int l, int h, int key){
    int mid = 0;
    while(l <= h){
        mid = (l + h)/2;
        if(A[mid] == key){
            return mid;
        }
        else if(A[mid] < key){
            l = mid + 1;
        }
        else{
            h = mid - 1;
        }
    }
    return -1;
}





int main()
{
    int Values[] = {1, 2, 6, 8, 11, 25};
    ArrayADT arr(6);
    for(int i = 0; i<6; i++){
        arr.append(Values[i]);
    }
    cout << arr.binarySearch(0, 5, 11);
    return 0;
}

// In here, it is a sorted list, so when we search for 11, it returns 4 which is the index 11 placed. 
// If we test the edge case, as to give it a list like 11, 2, 6, 8, 25; it will return -1, and say us that not found, despite its in the array; 
// This happens because we explicitely instructed that compiler will check for highest and lowest, and 11 cannot be before 2, 6, 8 in our own policies;