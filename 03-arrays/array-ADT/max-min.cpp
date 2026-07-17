#include<iostream>
using namespace std;

// MAXIMUM  and MINIMUM


class ArrayADT{
    private:
        int *A; // pointer to point to array's first add in heap
        int capacity; // number of indices inside array;
        int size;     // number of real value elements in array;
    public:
        ArrayADT(int cap);
        ~ArrayADT();     
        void append(int value); 
        int max() const;
        int min() const;
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

// max

int ArrayADT::max() const{
    if(size == 0){
        std::cout << "Array is empty\n";
        return 0;
    }
    int max = A[0];
    for(int i = 1; i < size; i++){
        if(A[i] > max){
            max = A[i];
        }
    }
    return max;
}


// min

int ArrayADT::min() const{
    if(size == 0){
        std::cout << "Array is empty\n";
        return 0;
    }
    int min = A[0];
    for(int i = 1; i < size; ++i){
        if(A[i] < min){
            min = A[i];
        }
    }
    return min;
}



int main()
{
    int Values[] = {1, 55, 6, 8, -89, 25};
    ArrayADT arr(6);
    for(int i = 0; i<6; i++){
        arr.append(Values[i]);
    }   
    
    cout << arr.max() << endl;      // 55
    cout << arr.min() << endl;     // -89
    return 0;
}




/*
    ANALYSIS:

        Max:
            -This function is O(n). reason is that this function traces all indices and campares them. 

        Min:
            -This function is also O(n). the same as the max function, which only the check gate differs.

*/