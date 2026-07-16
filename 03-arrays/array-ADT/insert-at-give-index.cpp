#include<iostream>
using namespace std;

// Display
// we will see how to print the values of array in console;



class ArrayADT{
    private:
        int *A; // pointer to point to array's first add in heap
        int capacity; // number of indices inside array;
        int size;     // number of real value elements in array;
    public:
        ArrayADT(int cap);  // Constructor
        ~ArrayADT();        // Destructor
        void append(int value); // Append means add a value at the end of an array;
        void display() const;   // we will display the real values in array, we did const, coz this function does not modify anything in class;
        void insert(int index, int value);  // This function is responsible to add a value at a given index in array; lets be carefull with logic;
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

// Display:

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


// Insert:
/* Think a line of people sitting in order in a supermarket;
When we want to add a new person which he/she is in hurry, what can be the most effecient way to do it? 
we can shift people back and forth to be able to place that person in wanted index. so we are doing the same thing, now lets think about arrays;
suppose I have an array cap of 10 and size is 5 right now, I want to add a new value in index 3; so what I can do? What is the best way to perform the task?
The best way can be: I will shift value at index 5, to index 6, the value in index 4 to 5 and the value in index 3 to index 4, when I see I am at the wanted index which 
is 3 in here, I will stop and add the new value there;

*/

void ArrayADT::insert(int index, int n){
    // First of all, I need to check if array is full, or the wanted index is not in array at all; in array of capacity 10, insert(12, 5) is impossible;
    if(size == capacity || index > capacity || index < 0){
        std::cout << "Array is either full or index is invalid\n";
        return; // stop;
    }
    // Now let's shift the values as we discussed;
    for(int i = size; i > index; --i){
        A[i] = A[i-1]; // The value in index (i-1)th will now be in index i; A[5] = A[4]; 
    }
    A[index] = n;
    size++; // when we add one value, it means the size should also inrement by one;
}



int main()
{
    
    ArrayADT arr(5);
    arr.append(20);     // Array has 20 at index 0 and size is now 1;
    arr.insert(0, 40);
    arr.display();      // O/P: 40 20;
    return 0;
}