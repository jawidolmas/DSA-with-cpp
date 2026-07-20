#include<iostream>


// Finding Missing Elements: 

// Finding missing element in a sorted array. 

class ArrayADT{
    private:
        int *A; // pointer to point to array's first add in heap
        int capacity; // number of indices inside array;
        int size;     // number of real value elements in array;
    public:
        ArrayADT(int cap);
        ~ArrayADT();     
        void append(int value); 
        void display() const;
        void FindMissingElement() const;
        void MissingSorted() const;

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


/*  Logic:
       
        Now. what if it is not first N natrual numbers? it is sorted, 5 6 7 8... but not first N natural number. so lets discuss,
        suppose we have 6 in index 0 and 7 in 1th and so ...., what is 6 - 0? 6? right, what is 7 - 1? 6? what is 8-2? 6? see the pattern? whenever we subtract the value
        with its index, we are getting the first element, and whenever we did not get first element, then there is a missing element, so that will be first element + index, isnt it?

        let's code. 
*/



// Finding missed element in sorted array.

void ArrayADT::MissingSorted() const{
    if(size == 0){
        std::cout << "Array is empty\n";
        return;
    }
    int l = A[0];
    int diff = l - 0;
    for(int i=0; i<size; i++){
        if(A[i]-i != diff){
            std::cout << "Missing element: " << i + diff;
            break;
        }
    }
}


int main()
{
    int Values[] = {6, 7, 8, 9, 11, 12, 13, 14, 15};
    ArrayADT arr(9);
    for(int i = 0; i<9; i++){
        arr.append(Values[i]);
    }    
    arr.MissingSorted();            // 10 is missing


    return 0;           
}


/*
    ANALYSIS:

      Finding missing array: 
            This function is order of N, as we scan all the elements and do a work of comparing them on each loop. so n+1 for loop itself and n for the comparings. 
            to conclude, we will do a work of O(n).

*/