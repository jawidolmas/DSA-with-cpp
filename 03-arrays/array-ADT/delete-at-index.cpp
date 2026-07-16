#include<iostream>
using namespace std;

// Delete
// The delete can happen using the index. so we will delete by index.



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
        void Delete(int index);
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


// Delete:
// When deleting a value from an index, we need to shift other values so there should not be a gap in between, which will be a reason to lose access to datas;

void ArrayADT::Delete(int index){
    if(size == 0 || index >= size || index < 0){
        std::cout << "Something went wrong\n";
        return;
    }
    for(int i = index; i < size-1; i++){
        A[i] = A[i+1];
    }
    size--;
}

// Comment for myself: Remmember that, A[i] = A[i+1] is a hardware overwrite. means it act only as a normal variable, not something like shifting beside the whatever the value is; so its simply x = 30, then x = 40; just modifying that index. the hardware overwrite is the bit patterns change only, so 30 bits to 40; 


int main()
{
    
    ArrayADT arr(5);
    arr.append(20);     // Array has 20 at index 0 and size is now 1;
    arr.append(30);
    arr.append(40);
    arr.append(50);
    arr.Delete(1);      // Deletes value in index 1 which is 30;
    arr.display();      // O/P: 20 40 50;
    return 0;
}