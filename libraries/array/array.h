// Adding include guards in header files. 
// Include guards are a strict protective codes that prevents the .h files from being compiled twice.
// If we have a header file array.h and it is included in linkedlist.h and linkedlist.h is included in main.cpp, then array.h is going to be
// read twice, once inside linkedlist.h and once inside main.cpp
// To prevent this, we use #ifndef NAME_HEADER_FILE(array.h) - means if not defined yet, #define array.h, and once it is defined, second time it does not define it again, coz it is already define once. 
// at the end #endif to end the conditional clause.
// In modern c++, we can change all of those three statements with one statement which is #pragma once


#pragma once

class Array{
    private: 
        int *A;
        int capacity;   // Number of slots or indices in array
        int size;       // number of real values in each index.
        void swap(int &a, int &b);

    public:
        Array(int cap);
        ~Array();
        void append(int n);
        void insert(int index, int n);
        void Delete(int index);
        void display() const;
        int  length() const;
        bool isEmpty() const;
        bool isFull() const;
        int  Max() const;
        int  Min() const; 
        int  sum() const;
        double average() const;
        void linearsearch(int key) const;
        int get(int index) const;
        void set(int index, int value);    
        void transpositionLinearSe(int key);
        void movetoFrontLinearSe(int key);
        int BinarySearchIterative(int key) ;
        int BinarySearchRecursive(int l, int h, int key) ;
        Array Merge(Array &arr1, Array &arr2);
        void Reverse();
        void ReverseUsingAuxiliaryArray(Array &arr);
        void leftshift();
        void Rightshift();
        bool isSorted() const;
        void insertSorted(int val);
        void rearrangeNegandPos();
};