#include<iostream>


// Duplicates of elements: 

// Finding  duplicate of  elements  in sorted/unsorted array using hash. 

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
        void FindduplicateHash(int high) const;

};


ArrayADT::ArrayADT(int cap){
    A = new int[cap](); 
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




// Finding missing element in sorted array using hash table

void ArrayADT::FindduplicateHash(int high) const{
    if(size == 0){
        std::cout << "Array is empty\n";
        return;
    }
    ArrayADT hash(high+1);
    for(int i = 0; i<size; i++){
        hash.A[A[i]]++;
    }

    for(int i = 1; i<=high; i++){
        if(hash.A[i] > 1){
            std::cout << "The number " << i << " appeared " << hash.A[i] << " times\n";
        }
    }
}



int main()
{
    int Values[10] = {3, 6, 8, 8, 10, 8, 15, 15, 15, 20};
    ArrayADT arr(10);
    for(int i = 0; i<10; i++){
        arr.append(Values[i]);
    }    
    arr.FindduplicateHash(20);       

    return 0;           
}


/*
    ANALYSIS:

        -This function is O(n). we trace the array which n step work, and then the remaining operations are all constant. 
        -Space consuming function.
*/