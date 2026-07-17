#include<iostream>
using namespace std;

// Get and Set
// Get means fetching a data from a given index. when get(index), then means bring the value in index;
// Set means replacing a data in a given index. when set(index, x), then means change the value in index, with new value x;


class ArrayADT{
    private:
        int *A; // pointer to point to array's first add in heap
        int capacity; // number of indices inside array;
        int size;     // number of real value elements in array;
    public:
        ArrayADT(int cap);
        ~ArrayADT();     
        void append(int value); 
        int get(int index) const; 
        void set(int index, int x);
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


// Append:
void ArrayADT::append(int n){
    if(size == capacity){   
        std::cout << "Array is full\n";
        return;
    }
    A[size] = n;
    size++;         
}

// Get(index)

int ArrayADT::get(int index) const{
    if(index >= 0 && index < size){     // Check if the index is valid;
        return A[index];                // Return the value in that index;
    }
    return -1;                      // If not valid index, then return -1;
}


// Set(index, x)

void ArrayADT::set(int index, int x){
    if(index >= 0 && index < size){ // Check if the index is valid
        A[index] = x;               // Modify the value in valid index;
    }
}


void ArrayADT::display() const{
    for(int i = 0 ; i <size; i++){
        std::cout << A[i] << " ";
    }
    cout << endl;
}



int main()
{
    int Values[] = {1, 2, 6, 8, 11, 25};
    ArrayADT arr(6);
    for(int i = 0; i<6; i++){
        arr.append(Values[i]);
    }
    arr.display();
    cout << arr.get(2) << endl;
    arr.set(2, 7);
    arr.display();


    return 0;
}

/*  Output:

    1 2 6 8 11 25 
    6
    1 2 7 8 11 25 





    ANALYSIS:
        GET:
            -for get function, the complexity is O(1). reason: we only do two step work, which is checking if index is valid and returning value;
        
        Set:
            -for set function, the complexity is also O(1). we only do a 2 step work. check if index is valid, then modify the value;

*/