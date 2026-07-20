#include<iostream>


// Finding Missing Elements: 

// Finding  missing elements  in a unsorted array. 

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
        void MissingUnsorted(int high) const;

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
        
        So, how can we find missing elements in unsorted array? let's don't care about memory, for now. We will use hashing method. suppose if we have an array of 8 index 
        which its largest value is HIGH. So, we will take another array size HIGH. so A[HIGH] and init it to 0, then we will go to our main array and traverse it, when ever we see any value 
        in main array, and we will increment that index value in second hash array. so we will have a bitset array, all elements 1s and 0s. if any index remained zero, that
        means, that index num  is missing element. CRYSTAL? 
        
        This algorithm is useful when we are given a task like: 
            -You have an array that's supposed to contain all values from 1 to N, but exactly one (or a few) got left out. Find which one(s).

        let's see it in code.
*/



// Finding missing element in unsorted array

void ArrayADT::MissingUnsorted(int high) const{
    if(size == 0){
        std::cout << "Array is empty\n";
        return;
    }
    ArrayADT hash(high + 1);
    for(int i = 0; i<size; ++i){        // Traverse the main array
        hash.A[A[i]]++;                 // Increment hash array's indices with the index values in main array.
    }

    // Now, let's print missing elements in array hash;
    for(int i = 1; i<=high; i++){
            if(hash.A[i] == 0){
                std::cout << i << " ";
            }
    }
}


int main()
{
    int Values[10] = {1, 2, 8, 4, 6, 7, 9, 11};
    ArrayADT arr(10);
    for(int i = 0; i<10; i++){
        arr.append(Values[i]);
    }    
    arr.MissingUnsorted(11);        // 3, 5, 10.   


    return 0;           
}


/*
    ANALYSIS:

        -This function does a work of n. we have a for loop, and it traces main array which it is n, after that, we increment hash array by one, so that is const. 
        Another for loop for printing missing numbers in hash table does a work on n. so in fact, we have time function of 2n and order of O(n).
        -This function can be used when space is less important than time, nowadays, machines are so powerful which leads us to not worry about space, at least in here. 
        -This function uses a lot of space, suppose the largest element was 200000, and we will get an array that much size. 
        When using this algorithm, be confident with what you really looking for. speed or memory. 

*/