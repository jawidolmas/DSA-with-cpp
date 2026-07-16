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
        int RecursionbinarySearch(int low, int high, int key);
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

// Binary Search - using Recursion;

int ArrayADT::RecursionbinarySearch(int l, int h, int key){
    int mid = 0;
    while(l <= h){
        mid = (l + h)/2;
        if(A[mid] == key){
            return mid;
        }
        else if(mid < key){
            return RecursionbinarySearch(mid+1, h, key);
        }
        else{
            return RecursionbinarySearch(l, mid-1, key);
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
    cout << arr.RecursionbinarySearch(0, 5, 11);
    return 0;
}

// In here, it is a sorted list, so when we search for 11, it returns 4 which is the index 11 placed. 
// If we test the edge case, as to give it a list like 11, 2, 6, 8, 25; it will return -1, and say us that not found, despite its in the array; 
// This happens because we explicitely instructed that compiler will check for highest and lowest, and 11 cannot be before 2, 6, 8 in our own policies;



/* ANALYSIS OF BINARY SEARCH
    -Binary search is one the fastest method to search a sorted list;
    -If we think logically and trace the tree of a binary search, then we will get a tree which each father has 2 children until leaves; 
    -So, on each father we do 1 camparison, suppose we have a list of 15 elements, then we will split it in two, then again and again until we reach somewhere
    which we are not be able to split it, means only one element, as a conclusion, either search will succeed or  will fail; 
    -So, on each split, we do one camparision, which is if the key is on right or left hand? 
    -So, as we have 15 element which is 14 index, we will split to 7, then to 3, then to 1, so we did 4 camparision; 
    -In that case, if we have 15 element, we did 4 step of work; lets analyze this now. what does it mean?
    -suppose it was not 15, it was 16, is'nt the 16 = 2^4, so if we got 4 step work in a 16 element list, then can see some pattern?
    - 2^4 = 16
    - 4 = log2to16, log is the reverse of power. any successfull division is log, and any successfull multiplication is power; 
    - so we can conclude that Binary search is O(log2ton); if we think about the exact Order, then it is O(log2ton+1), as we only care polynomails in Big-O, 
    SO IT IS O(log2ton);
    This is true in iterative binary search;


    **Now what about recursion?
     -Recursion Binary search does as much work as iterative works; if we trace the recursion, then we will see the same pattern;
     -Of course, recursion will cost more in terms of space;


*/