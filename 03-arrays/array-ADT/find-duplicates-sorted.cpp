#include<iostream>


// Duplicates of elements: 

// Finding  duplicate of  elements  in sorted array. 

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
        void Findduplicate() const;

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
        
        In here, the logic is simple, trace the array index by index, and compare index with index+1, if they are two, then A[index] has a copy. but how many copy?
        we will track it by having another variable to track the count of duplicates, so at the end we will only print the duplicated number ones, and the number of 
        duplications. 

        let's see it in code.
*/



// Finding missing element in sorted array

void ArrayADT::Findduplicate() const{
    if(size == 0){
        std::cout << "Array is empty\n";
        return;
    }
    int j = 0;          // count the number of duplicates
    for(int i = 0; i<size; i++){
        if(A[i] == A[i+1]){
            j = i+1;
            while(A[j] == A[i]) j++;
            std::cout << "The number " << A[i] << " appeared " << j-i << " times\n";
            i = j-1;        // Lets get the i ready for loop.
        }
    }
}


// Remmember, array needs to be sorted.  8 8 9 12 15 OK. 8 7 8 9 12 Not OK

int main()
{
    int Values[10] = {3, 6, 8, 8, 10, 12, 15, 15, 15, 20};
    ArrayADT arr(10);
    for(int i = 0; i<10; i++){
        arr.append(Values[i]);
    }    
    arr.Findduplicate();        // 3, 5, 10.   


    return 0;           
}


/*
    ANALYSIS:

        -This function is O(n). we trace the array which n step work, and then the remaining operations are all constant. the while loop does work depending on 
        number of duplicates. so to conclude, the complexity is O(n). 

*/