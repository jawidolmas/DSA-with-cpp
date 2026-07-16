#include<iostream>
using namespace std;

// Append/Add; 



class ArrayADT{
    private:
        int *A; // pointer to point to array's first add in heap
        int capacity; // number of indices inside array;
        int size;     // number of real value elements in array;
    public:
        ArrayADT(int cap);  // Constructor
        ~ArrayADT();        // Destructor
        void append(int value); // Append means add a value at the end of an array;
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



int main()
{
    
    ArrayADT arr(5);
    arr.append(20);     // Array has 20 at index 0 and size is now 1;
    return 0;
}