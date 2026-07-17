#include<iostream>
using namespace std;

// Check if array is sorted


class ArrayADT{
    private:
        int *A; // pointer to point to array's first add in heap
        int capacity; // number of indices inside array;
        int size;     // number of real value elements in array;
    public:
        ArrayADT(int cap);
        ~ArrayADT();     
        void append(int value); 
        void checkSortedArr() const;
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

// Check if array  is sorted

void ArrayADT::checkSortedArr() const{
    if(size == 0){
        std::cout << "Array is empty\n";
        return;
    }
    bool sorted = true;
    for(int i = 0; i<size-1; i++){
        if(A[i]>A[i+1]){
            sorted = false;
            break;
        }
    }
    if(sorted){
        std::cout << "sorted\n";
    }
    else{
        std::cout << "Not sorted\n";
    }
}





int main()
{
    int Values[] = {1, 9, 8, 78, 50};
    ArrayADT arr(6);
    for(int i = 0; i<5; i++){
        arr.append(Values[i]);
    }       
    arr.checkSortedArr();       // O/P: Not sorted; if it was 1 2 3 25 50, then sorted.
    arr.display();
    
    
    return 0;           
}




/*
    ANALYSIS:
        -This function is O(n) time, since the loop compares each adjacent pair once, running size-1 times, and every other operation is constant time. 
        -Space complexity is O(1), no extra array used.
*/